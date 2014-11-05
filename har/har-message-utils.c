/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-message-utils.h"
#include "har-header.h"
#include "gslist.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static JsonNode *
har_bytes_serialize(gconstpointer boxed)
{
  GBytes * bytes = (GBytes *) boxed;
  JsonNode * result = json_node_alloc ();
  gsize nbytes = 0;
  gchar * s = g_bytes_unref_to_data (g_bytes_ref (bytes), &nbytes);
  s[nbytes] = '\0';
  result = json_node_init_string (result, g_strdup(s));
  return result;
}

static gpointer
har_bytes_deserialize(JsonNode *node)
{
  if (!JSON_NODE_HOLDS_VALUE(node)) {
    printf("no value");
    return NULL;
  }
  const gchar * s = json_node_get_string(node);
  GBytes * bytes = g_bytes_new(g_strdup(s), strlen(s));
  return (gpointer) bytes;
}

static JsonNode *
har_date_time_serialize(gconstpointer boxed)
{
  GDateTime * datetime = (GDateTime *) boxed;
  JsonNode * result = json_node_alloc ();
  gchar * s = g_date_time_format(datetime, "%Y-%m-%dT%H:%M:%SZ");
  result = json_node_init_string (result, s);
  return result;
}

static gpointer
har_date_time_deserialize(JsonNode *node)
{
  if (!JSON_NODE_HOLDS_VALUE(node))
    return NULL;

  const gchar * s = json_node_get_string(node);

  struct tm tm;
  if (strptime(s, "%Y-%m-%dT%H:%M:%SZ", &tm) == NULL) {
    printf("ERROR parsing date");
    return NULL;
  }
  gint64 t = mktime(&tm);
  GDateTime * datetime = g_date_time_new_from_unix_utc(t);
  return (gpointer) datetime;
}

static void
har_slist_serialize_element(gpointer data, gpointer user_data)
{
  printf("har_slist_serialize_element\n");
  JsonBuilder * builder = JSON_BUILDER (user_data); 

  HarHeader * object = HAR_HEADER (data);

  JsonNode * node = json_gobject_serialize ((GObject *)object);
  json_builder_add_value(builder, node);
}

static JsonNode *
har_slist_serialize(gconstpointer boxed)
{
  if (!G_IS_OBJECT(boxed)) {
    printf("har_slist_serialize FAILED\n");
    return NULL;
  }

  printf("har_slist_serialize\n");
  GSList * list = (GSList *) boxed;
  JsonNode * result;
  JsonBuilder * builder = json_builder_new();
  json_builder_begin_array(builder);
  g_slist_foreach(list, (GFunc) &har_slist_serialize_element, (gpointer) builder);
  json_builder_end_array(builder);
  result = json_builder_get_root(builder);
  g_object_unref(builder);
  return result;
}

static void
har_slist_deserialize_element(JsonArray *array, guint index, JsonNode *node, gpointer user_data)
{
printf("har_slist_deserialize_element\n");
  GSList ** list = (GSList **) user_data; 
  GObject * object = json_gobject_deserialize(HAR_TYPE_HEADER, node);
  *list = g_slist_prepend(*list, (gpointer) object);
}

static gpointer
har_slist_deserialize(JsonNode *node)
{
printf("har_slist_deserialize\n");
  GSList * result = NULL;
  JsonArray * array = json_node_get_array (node);
  json_array_foreach_element(array, (JsonArrayForeach) &har_slist_deserialize_element, (gpointer) &result);
  return (gpointer) result;
}


static const gchar *
g_module_check_init(GModule *module)
{
    printf("check_init()");

    json_boxed_register_serialize_func(G_TYPE_BYTES, JSON_NODE_VALUE, 
      (JsonBoxedSerializeFunc) &har_bytes_serialize);

    json_boxed_register_deserialize_func(G_TYPE_BYTES, JSON_NODE_VALUE,
      (JsonBoxedDeserializeFunc) &har_bytes_deserialize);

    json_boxed_register_serialize_func(G_TYPE_DATE_TIME, JSON_NODE_ARRAY, 
      (JsonBoxedSerializeFunc) &har_date_time_serialize);

    json_boxed_register_deserialize_func(G_TYPE_DATE_TIME, JSON_NODE_ARRAY,
      (JsonBoxedDeserializeFunc) &har_date_time_deserialize);

    json_boxed_register_serialize_func(G_TYPE_SLIST, JSON_NODE_ARRAY, 
      (JsonBoxedSerializeFunc) &har_slist_serialize);

    json_boxed_register_deserialize_func(G_TYPE_SLIST, JSON_NODE_ARRAY,
      (JsonBoxedDeserializeFunc) &har_slist_deserialize);

    return NULL;
}

static void
g_module_unload (GModule *module)
{
    printf("unload()");
}

void
har_init (void)
{
    g_module_check_init(NULL);
}

static inline guint
_har_parse_http_version_string_helper(const gchar * version, gsize version_length)
{
  printf("har_parse_http_version_string_helper(%s)\n", version);
    if (version_length != 8)
        return 1;

    /* This is the negative version of a normal strcmp, 
     * normally you would see !strcmp() for a positive match */
    if (g_ascii_strncasecmp("HTTP/", version, 5))
        return 2;

    if (!(g_ascii_isdigit(version[5]) && version[6] == '.' && 
          g_ascii_isdigit(version[7])))
        return 3;

    guint major = version[5] - '0';
    guint minor = version[7] - '0';
    guint result = major*10 + minor;

    printf("result = %d", result);
    return result;
}

guint
har_parse_http_version_string(const gchar * version, gsize version_length)
{
    guint version_number = _har_parse_http_version_string_helper(version, version_length);
    if (!version_number) {
        if (g_ascii_strncasecmp("SPDY", version, version_length))
            return 19;
    }
    return version_number;
}

const gchar *
har_render_http_version_string(guint version_number)
{
    switch (version_number) {
    case 9: return "HTTP/0.9";
    case 10: return "HTTP/1.0";
    case 11: return "HTTP/1.1";
    case 19: return "SPDY";
    case 20: return "HTTP/2.0";
    default: return "UNKNOWN";
    }
}
