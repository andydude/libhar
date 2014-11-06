/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-cookie.h"


/*
 * Forward declarations.
 */



/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarCookie, har_cookie, HAR_TYPE_OBJECT)


static void 
har_cookie_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarCookie * self;
  self = HAR_COOKIE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_COOKIE_COMMENT:
    g_value_set_string (value, har_cookie_get_comment (self));
    break;

    /* HarCookie */
  case HAR_COOKIE_NAME:
    g_value_set_string (value, har_cookie_get_name (self));
    break;
  case HAR_COOKIE_VALUE:
    g_value_set_string (value, har_cookie_get_value (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cookie_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarCookie * self;
  self = HAR_COOKIE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_COOKIE_COMMENT:
    har_cookie_set_comment (self, g_value_get_string (value));
    break;

    /* HarCookie */
  case HAR_COOKIE_NAME:
    har_cookie_set_name (self, g_value_get_string (value));
    break;
  case HAR_COOKIE_VALUE:
    har_cookie_set_value (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cookie_class_init (HarCookieClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_cookie_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_cookie_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_COOKIE_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarCookie */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_COOKIE_NAME, 
    g_param_spec_string ("name", "name", "Name.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_COOKIE_VALUE, 
    g_param_spec_string ("value", "value", "Value.", NULL, FLAGS));

#undef FLAGS

}


static void 
har_cookie_init (HarCookie * self)
{
  g_return_if_fail (self != NULL);

  self->name = "";
  self->value = "";
}


HarCookie * 
har_cookie_new (void)
{
  return g_object_new (HAR_TYPE_COOKIE, NULL);
}


const gchar * 
har_cookie_get_comment (HarCookie * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_cookie_set_comment (HarCookie * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


const gchar * 
har_cookie_get_name (HarCookie * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->name;
}


void 
har_cookie_set_name (HarCookie * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->name = g_strdup (value);
  g_object_notify ((GObject *) self, "name");
}


const gchar * 
har_cookie_get_value (HarCookie * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->value;
}


void 
har_cookie_set_value (HarCookie * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->value = g_strdup (value);;
  g_object_notify ((GObject *) self, "value");
}
