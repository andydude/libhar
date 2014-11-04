/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-message-body.h"


/*
 * Forward declarations.
 */


/*
 * Method definitions.
 */

G_DEFINE_TYPE_WITH_PRIVATE(HarMessageBody, har_message_body, HAR_TYPE_OBJECT)



static void
har_message_body_get_property (
    GObject * object,
    guint property_id,
    GValue * value,
    GParamSpec * pspec)
{
    HarMessageBody * self = HAR_MESSAGE_BODY (object);
  switch (property_id) {

  case HAR_MESSAGE_BODY_COMMENT:
    g_value_set_string (value, har_message_body_get_comment (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_message_body_set_property (
    GObject * object,
    guint property_id,
    const GValue * value,
    GParamSpec * pspec)
{
  HarMessageBody * self = HAR_MESSAGE_BODY (object);
  switch (property_id) {

  case HAR_MESSAGE_BODY_COMMENT:
    har_message_body_set_comment (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_message_body_class_init (HarMessageBodyClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = har_message_body_get_property;
  G_OBJECT_CLASS (klass)->set_property = har_message_body_set_property;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_BODY_COMMENT,
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

#undef FLAGS

}


static void
har_message_body_init (HarMessageBody * self)
{
  g_return_if_fail (self != NULL);
}


HarMessageBody *
har_message_body_new (void)
{
    return g_object_new (HAR_TYPE_MESSAGE_BODY, NULL);
}



const gchar * har_message_body_get_comment (HarMessageBody * self)
{
    return har_object_get_comment (HAR_OBJECT (self));
}


void har_message_body_set_comment (HarMessageBody * self, const gchar * value)
{
    har_object_set_comment (HAR_OBJECT (self), value);
}


gint har_message_body_get_compressed_size (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_compressed_length;
}


void har_message_body_set_compressed_size (HarMessageBody * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_compressed_length = value;
  g_object_notify ((GObject *) self, "dns");
}


gint har_message_body_get_compression (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_compression;
}


void har_message_body_set_compression (HarMessageBody * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_compression = value;
  g_object_notify ((GObject *) self, "dns");
}


const gchar * har_message_body_get_encoding (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_encoding;
}


void har_message_body_set_encoding (HarMessageBody * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_encoding = value;
  g_object_notify ((GObject *) self, "dns");
}


const gchar * har_message_body_get_mime_type (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_mime_type;
}


void har_message_body_set_mime_type (HarMessageBody * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_mime_type = value;
  g_object_notify ((GObject *) self, "dns");
}


const gchar * har_message_body_get_charset (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_charset;
}


void har_message_body_set_charset (HarMessageBody * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_charset = value;
  g_object_notify ((GObject *) self, "dns");
}


gint har_message_body_get_size (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_length;
}


void har_message_body_set_size (HarMessageBody * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_length = value;
  g_object_notify ((GObject *) self, "dns");
}


GBytes * har_message_body_get_text (HarMessageBody * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_content;
}


void har_message_body_set_text (HarMessageBody * self, GBytes * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_content = value;
  g_object_notify ((GObject *) self, "dns");
}


