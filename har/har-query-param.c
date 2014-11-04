/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-query-param.h"


/*
 * Forward declarations.
 */



/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarQueryParam, har_query_param, HAR_TYPE_OBJECT)


static void 
har_query_param_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarQueryParam * self;
  self = HAR_QUERY_PARAM (object);
  switch (property_id) {

    /* HarObject */
  case HAR_QUERY_PARAM_COMMENT:
    g_value_set_string (value, har_query_param_get_comment (self));
    break;

    /* HarQueryParam */
  case HAR_QUERY_PARAM_NAME:
    g_value_set_string (value, har_query_param_get_name (self));
    break;
  case HAR_QUERY_PARAM_VALUE:
    g_value_set_string (value, har_query_param_get_value (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_query_param_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarQueryParam * self;
  self = HAR_QUERY_PARAM (object);
  switch (property_id) {

    /* HarObject */
  case HAR_QUERY_PARAM_COMMENT:
    har_query_param_set_comment (self, g_value_get_string (value));
    break;

    /* HarQueryParam */
  case HAR_QUERY_PARAM_NAME:
    har_query_param_set_name (self, g_value_get_string (value));
    break;
  case HAR_QUERY_PARAM_VALUE:
    har_query_param_set_value (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_query_param_class_init (HarQueryParamClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_query_param_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_query_param_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_QUERY_PARAM_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarQueryParam */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_QUERY_PARAM_NAME, 
    g_param_spec_string ("name", "name", "Name.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_QUERY_PARAM_VALUE, 
    g_param_spec_string ("value", "value", "Value.", NULL, FLAGS));

#undef FLAGS

}


static void 
har_query_param_init (HarQueryParam * self)
{
  g_return_if_fail (self != NULL);

  self->name = "";
  self->value = "";
}


HarQueryParam * 
har_query_param_new (void)
{
  return g_object_new (HAR_TYPE_QUERY_PARAM, NULL);
}


const gchar * 
har_query_param_get_comment (HarQueryParam * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_query_param_set_comment (HarQueryParam * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


const gchar * 
har_query_param_get_name (HarQueryParam * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->name;
}


void 
har_query_param_set_name (HarQueryParam * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->name = value;
  g_object_notify ((GObject *) self, "name");
}


const gchar * 
har_query_param_get_value (HarQueryParam * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->value;
}


void 
har_query_param_set_value (HarQueryParam * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->value = value;
  g_object_notify ((GObject *) self, "value");
}
