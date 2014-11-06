/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-message.h"
#include "har-message-utils.h"
#include "gslist.h"
#include <string.h>

/*
 * Forward declarations.
 */


struct _HarMessagePrivate
{
  const gchar * _http_version;
  gint _http_version_number;
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
    g_value_set_uint (value, har_message_get_version (self));
    break;
  case HAR_MESSAGE_COOKIES:
    g_value_set_boxed (value, har_message_get_cookies (self));
    break;
  case HAR_MESSAGE_HEADERS:
    g_value_set_boxed (value, har_message_get_headers (self));
    break;
  case HAR_MESSAGE_HEADERS_SIZE:
    g_value_set_int (value, har_message_get_headers_size (self));
    break;
  case HAR_MESSAGE_BODY_SIZE:
    g_value_set_int (value, har_message_get_body_size (self));
    break;
  case HAR_MESSAGE_HTTP_VERSION:
    g_value_set_string (value, har_message_get_http_version (self));
    break;
  //case HAR_MESSAGE_HTTP_HEADERS:
  //  g_value_set_object (value, har_message_get_http_headers (self));
  //  break;

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
    printf(g_strdup_value_contents(value));
    har_message_set_version (self, g_value_get_uint (value));
    break;
  case HAR_MESSAGE_COOKIES:
    har_message_set_cookies (self, g_value_get_boxed (value));
    break;
  case HAR_MESSAGE_HEADERS:
    har_message_set_headers (self, g_value_get_boxed (value));
    break;
  case HAR_MESSAGE_HEADERS_SIZE:
    har_message_set_headers_size (self, g_value_get_int (value));
    break;
  case HAR_MESSAGE_BODY_SIZE:
    har_message_set_body_size (self, g_value_get_int (value));
    break;
  case HAR_MESSAGE_HTTP_VERSION:
    har_message_set_http_version (self, g_value_get_string (value));
    break;
  //case HAR_MESSAGE_HTTP_HEADERS:
  //  har_message_set_http_headers (self, g_value_get_object (value));
  //  break;

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

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_COMMENT,
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarMessage */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_VERSION,
    g_param_spec_uint ("httpVersionNumber", "http-version-number", "HTTP version number.", 
                       9,  /* HTTP/0.9 minimum */
                       20, /* HTTP/2.0 maximum */
                       11, /* HTTP/1.1 default */
                       FLAGS));

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_COOKIES,
    g_param_spec_boxed ("cookies", "cookies", "TODO.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_HEADERS,
    g_param_spec_boxed ("headers", "headers", "TODO.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_HEADERS_SIZE,
    g_param_spec_int ("headersSize", "headers-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_BODY_SIZE,
    g_param_spec_int ("bodySize", "body-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_HTTP_VERSION,
    g_param_spec_string ("httpVersion", "http-version", "TODO.", NULL, FLAGS));
  //g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_MESSAGE_HTTP_HEADERS,
  //  g_param_spec_object ("httpHeaders", "http-headers", "TODO.", NULL, FLAGS));

#undef FLAGS

}


static void 
har_message_init (HarMessage * self)
{
  g_return_if_fail (self != NULL);
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, HAR_TYPE_MESSAGE, HarMessagePrivate);
  g_return_if_fail (self->priv != NULL);

  self->priv->_http_version = "";
  self->priv->_http_version_number = 0;
  self->priv->_headers_size = -1;
  self->priv->_body_size = -1;
  self->cookies = NULL;
  self->headers = har_headers_new();
}


HarMessage * 
har_message_new (void) {
  HarMessage * result;
  result = g_object_new (HAR_TYPE_MESSAGE, NULL);
  har_message_init(result);
  return result;
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
  return self->priv->_http_version_number;
}

void har_message_set_version (HarMessage * self, guint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_http_version_number = value;
  g_object_notify ((GObject *) self, "httpVersionNumber");
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

GSList * har_message_get_headers (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->headers->list;
}

void har_message_set_headers (HarMessage * self, GSList * value)
{
  g_return_if_fail (self != NULL);
  self->headers->list = value;
  g_object_notify ((GObject *) self, "headers");
}

//HarMessageBody * har_message_get_body (HarMessage * self)
//{
//  g_return_val_if_fail (self != NULL, NULL);
//  return self->body;
//}
//
//void har_message_set_body (HarMessage * self, HarMessageBody * value)
//{
//  g_return_if_fail (self != NULL);
//  self->body = value;
//  g_object_notify ((GObject *) self, "bodyData");
//}

gint har_message_get_headers_size (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, -1);
  return self->priv->_headers_size;
}

void har_message_set_headers_size (HarMessage * self, gint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_headers_size = value;
  g_object_notify ((GObject *) self, "headersSize");
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
  g_object_notify ((GObject *) self, "bodySize");
}

const gchar * har_message_get_http_version (HarMessage * self)
{
  g_return_val_if_fail (self != NULL, 0);
  return self->priv->_http_version;
}

void har_message_set_http_version (HarMessage * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  g_return_if_fail (value != NULL);
  self->priv->_http_version = g_strdup(value); //, strnlen(value, 16));
  har_message_set_version(self, har_parse_http_version_string(value, strlen(value)));
  g_object_notify ((GObject *) self, "httpVersion");
}

//HarHeaders * har_message_get_http_headers (HarMessage * self)
//{
//  g_return_val_if_fail (self != NULL, 0);
//  return self->headers;
//}
//
//void har_message_set_http_headers (HarMessage * self, HarHeaders * value)
//{
//  g_return_if_fail (self != NULL);
//  self->headers = value;
//  g_object_notify ((GObject *) self, "httpHeaders");
//}

