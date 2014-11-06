/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-header.h"


/*
 * Forward declarations.
 */



/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarHeader, har_header, HAR_TYPE_OBJECT)


static void 
har_header_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarHeader * self;
  self = HAR_HEADER (object);
  switch (property_id) {

    /* HarObject */
  case HAR_HEADER_COMMENT:
    g_value_set_string (value, har_header_get_comment (self));
    break;

    /* HarHeader */
  case HAR_HEADER_NAME:
    g_value_set_string (value, har_header_get_name (self));
    break;
  case HAR_HEADER_VALUE:
    g_value_set_string (value, har_header_get_value (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_header_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarHeader * self;
  self = HAR_HEADER (object);
  switch (property_id) {

    /* HarObject */
  case HAR_HEADER_COMMENT:
    har_header_set_comment (self, g_value_get_string (value));
    break;

    /* HarHeader */
  case HAR_HEADER_NAME:
    har_header_set_name (self, g_value_get_string (value));
    break;
  case HAR_HEADER_VALUE:
    har_header_set_value (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_header_class_init (HarHeaderClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_header_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_header_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_HEADER_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarHeader */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_HEADER_NAME, 
    g_param_spec_string ("name", "name", "Name.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_HEADER_VALUE, 
    g_param_spec_string ("value", "value", "Value.", NULL, FLAGS));

#undef FLAGS

}


static void 
har_header_init (HarHeader * self)
{
  g_return_if_fail (self != NULL);

  self->name = "";
  self->value = "";
}


HarHeader * 
har_header_new (void)
{
  return g_object_new (HAR_TYPE_HEADER, NULL);
}


const gchar * 
har_header_get_comment (HarHeader * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_header_set_comment (HarHeader * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


const gchar * 
har_header_get_name (HarHeader * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->name;
}


void 
har_header_set_name (HarHeader * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->name = g_strdup (value);
  g_object_notify ((GObject *) self, "name");
}


const gchar * 
har_header_get_value (HarHeader * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->value;
}


void 
har_header_set_value (HarHeader * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->value = g_strdup (value);
  g_object_notify ((GObject *) self, "value");
}
