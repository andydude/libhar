/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-message.h"


/*
 * Forward declarations.
 */


struct _HarMessagePrivate
{
  gint _version;
  gint _headers_size;
  gint _body_size;
};


/*
 * Method definitions.
 */


G_DEFINE_TYPE_WITH_PRIVATE(HarMessage, har_message, HAR_TYPE_OBJECT)

static void 
har_message_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarMessage * self = HAR_MESSAGE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_MESSAGE_COMMENT:
    g_value_set_string (value, har_message_get_comment (self));
    break;

    /* HarMessage */
  case HAR_MESSAGE_VERSION:
    g_value_set_int (value, har_message_get_version (self));
    break;
  case HAR_MESSAGE_COOKIES:
    g_value_set_object (value, har_message_get_cookies (self));
    break;
  case HAR_MESSAGE_HEADERS:
    g_value_set_object (value, har_message_get_headers (self));
    break;
  case HAR_MESSAGE_BODY:
    g_value_set_object (value, har_message_get_body (self));
    break;
  case HAR_MESSAGE_HEADERS_SIZE:
    g_value_set_int (value, har_message_get_headers_size (self));
    break;
  case HAR_MESSAGE_BODY_SIZE:
    g_value_set_int (value, har_message_get_body_size (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_message_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec) 
{
  HarMessage * self = HAR_MESSAGE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_MESSAGE_COMMENT:
    har_message_set_comment (self, g_value_get_string (value));
    break;

    /* HarMessage */
  case HAR_MESSAGE_VERSION:
    har_message_set_version (self, g_value_get_int (value));
    break;
  case HAR_MESSAGE_COOKIES:
    har_message_set_cookies (self, g_value_get_object (value));
    break;
  case HAR_MESSAGE_HEADERS:
    har_message_set_headers (self, g_value_get_object (value));
    break;
  case HAR_MESSAGE_BODY:
    har_message_set_body (self, g_value_get_object (value));
    break;
  case HAR_MESSAGE_HEADERS_SIZE:
    har_message_set_headers_size (self, g_value_get_int (value));
    break;
  case HAR_MESSAGE_BODY_SIZE:
    har_message_set_body_size (self, g_value_get_int (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}

static void 
har_message_class_init (HarMessageClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_message_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_message_set_property;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_COMMENT,
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

#undef FLAGS

}


static void 
har_message_init (HarMessage * self)
{
  g_return_if_fail (self != NULL);
}

HarMessage * 
har_message_new (void) {
  return g_object_new (HAR_TYPE_MESSAGE, NULL);
}


const gchar * 
har_message_get_comment (HarMessage * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}

void 
har_message_set_comment (HarMessage * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}

guint har_message_get_version (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, 0);
  return self->priv->_version;
}

void har_message_set_version (HarMessage * self, guint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_version = value;
  g_object_notify ((GObject *) self, "http-version");
}

GSList * har_message_get_cookies (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->cookies;
}

void har_message_set_cookies (HarMessage * self, GSList * value)
{
  g_return_if_fail (self != NULL);
  self->cookies = value;
  g_object_notify ((GObject *) self, "cookies");
}

HarHeaders * har_message_get_headers (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->headers;
}

void har_message_set_headers (HarMessage * self, HarHeaders * value)
{
  g_return_if_fail (self != NULL);
  self->headers = value;
  g_object_notify ((GObject *) self, "headers");
}

HarMessageBody * har_message_get_body (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->body;
}

void har_message_set_body (HarMessage * self, HarMessageBody * value)
{
  g_return_if_fail (self != NULL);
  self->body = value;
  g_object_notify ((GObject *) self, "body");
}

gint har_message_get_headers_size (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_headers_size;
}

void har_message_set_headers_size (HarMessage * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_headers_size = value;
  g_object_notify ((GObject *) self, "headers-size");
}

gint har_message_get_body_size (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_body_size;
}

void har_message_set_body_size (HarMessage * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_body_size = value;
  g_object_notify ((GObject *) self, "body-size");
}
