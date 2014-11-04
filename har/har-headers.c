/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-headers.h"


/*
 * Forward declarations.
 */



/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarHeaders, har_headers, HAR_TYPE_OBJECT)


static void 
har_headers_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarHeaders * self;
  self = HAR_HEADERS (object);
  switch (property_id) {

    /* HarObject */
  case HAR_HEADERS_COMMENT:
    g_value_set_string (value, har_headers_get_comment (self));
    break;

    /* HarHeaders */

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_headers_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarHeaders * self;
  self = HAR_HEADERS (object);
  switch (property_id) {

    /* HarObject */
  case HAR_HEADERS_COMMENT:
    har_headers_set_comment (self, g_value_get_string (value));
    break;

    /* HarHeaders */

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_headers_class_init (HarHeadersClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_headers_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_headers_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_HEADERS_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarHeaders */

#undef FLAGS

}


static void 
har_headers_init (HarHeaders * self)
{
  g_return_if_fail (self != NULL);
}


HarHeaders * 
har_headers_new (void)
{
  return g_object_new (HAR_TYPE_HEADERS, NULL);
}
