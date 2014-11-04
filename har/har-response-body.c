/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-response-body.h"

/*
 * Method definitions.
 */

G_DEFINE_TYPE(HarResponseBody, har_response_body, HAR_TYPE_MESSAGE_BODY)


static void
har_response_body_get_property (
    GObject * object,
    guint property_id,
    GValue * value,
    GParamSpec * pspec)
{
    HarResponseBody * self = HAR_RESPONSE_BODY (object);
  switch (property_id) {

  case HAR_RESPONSE_BODY_COMMENT:
    g_value_set_string (value, har_response_body_get_comment (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_response_body_set_property (
    GObject * object,
    guint property_id,
    const GValue * value,
    GParamSpec * pspec)
{
  HarResponseBody * self = HAR_RESPONSE_BODY (object);
  switch (property_id) {

  case HAR_RESPONSE_BODY_COMMENT:
    har_response_body_set_comment (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_response_body_class_init (HarResponseBodyClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = har_response_body_get_property;
  G_OBJECT_CLASS (klass)->set_property = har_response_body_set_property;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_BODY_COMMENT,
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

#undef FLAGS

}


static void
har_response_body_init (HarResponseBody * self)
{
  g_return_if_fail (self != NULL);
}
