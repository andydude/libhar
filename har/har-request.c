/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-request.h"
#include "gslist.h"

/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_TYPE_WITH_PRIVATE(HarRequest, har_request, HAR_TYPE_MESSAGE)


static void 
har_request_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarRequest * self = HAR_REQUEST (object);
  switch (property_id) {


    /* HarObject */
  case HAR_REQUEST_COMMENT:
    g_value_set_string (value, har_request_get_comment (self));
    break;

    /* HarMessage */
  case HAR_REQUEST_VERSION:
    g_value_set_uint (value, har_request_get_version (self));
    break;
  case HAR_REQUEST_COOKIES:
    g_value_set_boxed (value, har_request_get_cookies (self));
    break;
  case HAR_REQUEST_HEADERS:
    g_value_set_boxed (value, har_request_get_headers (self));
    break;
  case HAR_REQUEST_BODY:
    g_value_set_object (value, har_request_get_body (self));
    break;
  case HAR_REQUEST_HEADERS_SIZE:
    g_value_set_int (value, har_request_get_headers_size (self));
    break;
  case HAR_REQUEST_BODY_SIZE:
    g_value_set_int (value, har_request_get_body_size (self));
    break;
  case HAR_REQUEST_HTTP_VERSION:
    g_value_set_string (value, har_request_get_http_version (self));
    break;
  //case HAR_REQUEST_HTTP_HEADERS:
  //  g_value_set_object (value, har_request_get_http_headers (self));
  //  break;

    /* HarRequest */
  case HAR_REQUEST_METHOD:
    g_value_set_string (value, har_request_get_method (self));
    break;
  case HAR_REQUEST_URL:
    g_value_set_string (value, har_request_get_url (self));
    break;
  case HAR_REQUEST_QUERY:
    g_value_set_boxed (value, har_request_get_query (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_request_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec) 
{
  HarRequest * self = G_TYPE_CHECK_INSTANCE_CAST (object, HAR_TYPE_REQUEST, HarRequest);
  switch (property_id) {

    /* HarObject */
  case HAR_REQUEST_COMMENT:
    har_request_set_comment (self, g_value_get_string (value));
    break;

    /* HarMessage */
  case HAR_REQUEST_VERSION:
    har_request_set_version (self, g_value_get_uint (value));
    break;
  case HAR_REQUEST_COOKIES:
    har_request_set_cookies (self, g_value_get_boxed (value));
    break;
  case HAR_REQUEST_HEADERS:
    har_request_set_headers (self, g_value_get_boxed (value));
    break;
  case HAR_REQUEST_BODY:
    har_request_set_body (self, g_value_get_object (value));
    break;
  case HAR_REQUEST_HEADERS_SIZE:
    har_request_set_headers_size (self, g_value_get_int (value));
    break;
  case HAR_REQUEST_BODY_SIZE:
    har_request_set_body_size (self, g_value_get_int (value));
    break;
  case HAR_REQUEST_HTTP_VERSION:
    har_request_set_http_version (self, g_value_get_string (value));
    break;
  //case HAR_REQUEST_HTTP_HEADERS:
  //  har_request_set_http_headers (self, g_value_get_object (value));
  //  break;

    /* HarRequest */
  case HAR_REQUEST_METHOD:
    har_request_set_method (self, g_value_get_string (value));
    break;
  case HAR_REQUEST_URL:
    har_request_set_url (self, g_value_get_string (value));
    break;
  case HAR_REQUEST_QUERY:
    har_request_set_query (self, g_value_get_boxed (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_request_class_init (HarRequestClass * klass) {
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_request_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_request_set_property;
  //G_OBJECT_CLASS (klass)->constructor = har_request_constructor;
  //G_OBJECT_CLASS (klass)->finalize = har_request_finalize;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READWRITE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_COMMENT,
    g_param_spec_string ("comment", "comment", "Comment.", NULL, FLAGS));

  /* HarMessage */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_VERSION,
    g_param_spec_uint ("httpVersionNumber", "http-version-number", "HTTP version number.", 
                       9,  /* HTTP/0.9 minimum */
                       20, /* HTTP/2.0 maximum */
                       11, /* HTTP/1.1 default */
                       FLAGS));

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_COOKIES,
    g_param_spec_boxed ("cookies", "cookies", "Cookies.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_HEADERS,
    g_param_spec_boxed ("headers", "headers", "Headers.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_HEADERS_SIZE,
    g_param_spec_int ("headersSize", "headers-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_SIZE,
    g_param_spec_int ("bodySize", "body-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_HTTP_VERSION,
    g_param_spec_string ("httpVersion", "http-version", "TODO.", NULL, FLAGS));
  //g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_HTTP_HEADERS,
  //  g_param_spec_object ("httpHeaders", "http-headers", "TODO.", NULL, FLAGS));

  /* HarRequest */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY,
    g_param_spec_object ("postData", "request body", "TODO.", HAR_TYPE_REQUEST_BODY, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_METHOD,
    g_param_spec_string ("method", "method", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_URL,
    g_param_spec_string ("url", "url", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_QUERY,
    g_param_spec_boxed ("queryString", "query string params", "TODO.", G_TYPE_SLIST, FLAGS));

#undef FLAGS
}


static void 
har_request_init (HarRequest * self) 
{
  g_return_if_fail (self != NULL);
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, HAR_TYPE_REQUEST, HarRequestPrivate);
  g_return_if_fail (self->priv != NULL);

  self->body = har_request_body_new ();
  self->method = "";
  self->url = "";
  self->query = NULL;
}


HarRequest * 
har_request_new (void) {
  HarRequest * result;
  result = g_object_new (HAR_TYPE_REQUEST, NULL);
  har_request_init(result);
  return result;
}




const gchar * har_request_get_comment (HarRequest* self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}
void har_request_set_comment (HarRequest * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}

guint har_request_get_version (HarRequest* self)
{
  return har_message_get_version (HAR_MESSAGE (self));
}

void har_request_set_version (HarRequest * self, guint value)
{
  har_message_set_version (HAR_MESSAGE (self), value);
}

GSList * har_request_get_cookies (HarRequest* self)
{
  return har_message_get_cookies (HAR_MESSAGE (self));
}

void har_request_set_cookies (HarRequest * self, GSList * value)
{
  har_message_set_cookies (HAR_MESSAGE (self), value);
}

GSList * har_request_get_headers (HarRequest* self)
{
  return har_message_get_headers (HAR_MESSAGE (self));
}

void har_request_set_headers (HarRequest * self, GSList * value)
{
  har_message_set_headers (HAR_MESSAGE (self), value);
}

HarRequestBody * har_request_get_body (HarRequest* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->body;
}

void har_request_set_body (HarRequest * self, HarRequestBody * value)
{
  g_return_if_fail (self != NULL);
  if (self->body)
    g_object_unref (self->body);
  if (value)
    value = g_object_ref (value);
  self->body = value;
  g_object_notify ((GObject *) self, "postData");
}

gint har_request_get_headers_size (HarRequest* self)
{
  return har_message_get_headers_size (HAR_MESSAGE (self));
}

void har_request_set_headers_size (HarRequest * self, gint value)
{
  har_message_set_headers_size (HAR_MESSAGE (self), value);
}

gint har_request_get_body_size (HarRequest* self)
{
  return har_message_get_body_size (HAR_MESSAGE (self));
}

void har_request_set_body_size (HarRequest * self, gint value)
{
  har_message_set_body_size (HAR_MESSAGE (self), value);
}


const gchar * har_request_get_http_version (HarRequest * self)
{
  return har_message_get_http_version (HAR_MESSAGE (self));
}

void har_request_set_http_version (HarRequest * self, const gchar * value)
{
  har_message_set_http_version (HAR_MESSAGE (self), value);
}

//HarHeaders * har_request_get_http_headers (HarRequest * self)
//{
//  return har_message_get_http_headers (HAR_MESSAGE (self));
//}
//
//void har_request_set_http_headers (HarRequest * self, HarHeaders * value)
//{
//  har_message_set_http_headers (HAR_MESSAGE (self), value);
//}


const gchar * har_request_get_method (HarRequest* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->method;
}

void har_request_set_method (HarRequest * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->method = g_strdup (value);
  g_object_notify ((GObject *) self, "method");
}

const gchar * har_request_get_url (HarRequest* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->url;
}

void har_request_set_url (HarRequest * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->url = g_strdup (value);
  g_object_notify ((GObject *) self, "url");
}

GSList * har_request_get_query (HarRequest* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->query;
}

void har_request_set_query (HarRequest * self, GSList * value)
{
  g_return_if_fail (self != NULL);
  self->query = value;
  g_object_notify ((GObject *) self, "queryString");
}
