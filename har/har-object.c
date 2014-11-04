/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-object.h"


/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarObject, har_object, G_TYPE_OBJECT)


static void
har_object_get_property (
    GObject * object,
    guint property_id,
    GValue * value,
    GParamSpec * pspec)
{
  HarObject * self = HAR_OBJECT (object);
  switch (property_id) {

    /* HarObject */
  case HAR_OBJECT_COMMENT:
    g_value_set_string (value, har_object_get_comment (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_object_set_property (
    GObject * object,
    guint property_id,
    const GValue * value,
    GParamSpec * pspec)
{
  HarObject * self = HAR_OBJECT (object);
  switch (property_id) {

    /* HarObject */
  case HAR_OBJECT_COMMENT:
    har_object_set_comment (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_object_class_init (HarObjectClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_object_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_object_set_property;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_OBJECT_COMMENT,
    g_param_spec_string ("comment", "comment", "Comment.", NULL, FLAGS));

#undef FLAGS

}


static void
har_object_init (HarObject * self)
{
  g_return_if_fail (self != NULL);

  self->comment = "";
}


HarObject *
har_object_new (void)
{
  return g_object_new (HAR_TYPE_OBJECT, NULL);
}


const gchar * har_object_get_comment (HarObject * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->comment;
}

void har_object_set_comment (HarObject * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->comment = g_strdup(value);
  g_object_notify ((GObject *) self, "comment");
}
