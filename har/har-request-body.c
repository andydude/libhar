/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-request-body.h"

/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */

G_DEFINE_TYPE(HarRequestBody, har_request_body, HAR_TYPE_MESSAGE_BODY)



static void
har_request_body_get_property (
    GObject * object,
    guint property_id,
    GValue * value,
    GParamSpec * pspec)
{
    HarRequestBody * self = HAR_REQUEST_BODY (object);
  switch (property_id) {

    /* HarObject */
  case HAR_REQUEST_BODY_COMMENT:
    g_value_set_string (value, har_request_body_get_comment (self));
    break;

      /* HarMessageBody */
  case HAR_REQUEST_BODY_COMPRESSED_LENGTH:
    g_value_set_int (value, har_request_body_get_compressed_size (self));
    break;
  case HAR_REQUEST_BODY_COMPRESSION:
    g_value_set_int (value, har_request_body_get_compression (self));
    break;
  case HAR_REQUEST_BODY_ENCODING:
    g_value_set_string (value, har_request_body_get_encoding (self));
    break;
  case HAR_REQUEST_BODY_MIME_TYPE:
    g_value_set_string (value, har_request_body_get_mime_type (self));
    break;
  case HAR_REQUEST_BODY_CHARSET:
    g_value_set_string (value, har_request_body_get_charset (self));
    break;
  case HAR_REQUEST_BODY_LENGTH:
    g_value_set_int (value, har_request_body_get_size (self));
    break;
  case HAR_REQUEST_BODY_TEXT:
    g_value_set_boxed (value, har_request_body_get_text (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_request_body_set_property (
    GObject * object,
    guint property_id,
    const GValue * value,
    GParamSpec * pspec)
{
  HarRequestBody * self = HAR_REQUEST_BODY (object);
  switch (property_id) {

    /* HarObject */
  case HAR_REQUEST_BODY_COMMENT:
    har_request_body_set_comment (self, g_value_get_string (value));
    break;

      /* HarMessageBody */
  case HAR_REQUEST_BODY_COMPRESSED_LENGTH:
    har_request_body_set_compressed_size (self, g_value_get_int (value));
    break;
  case HAR_REQUEST_BODY_COMPRESSION:
    har_request_body_set_compression (self, g_value_get_int (value));
    break;
  case HAR_REQUEST_BODY_ENCODING:
    har_request_body_set_encoding (self, g_value_get_string (value));
    break;
  case HAR_REQUEST_BODY_MIME_TYPE:
    har_request_body_set_mime_type (self, g_value_get_string (value));
    break;
  case HAR_REQUEST_BODY_CHARSET:
    har_request_body_set_charset (self, g_value_get_string (value));
    break;
  case HAR_REQUEST_BODY_LENGTH:
    har_request_body_set_size (self, g_value_get_int (value));
    break;
  case HAR_REQUEST_BODY_TEXT:
    har_request_body_set_text (self, g_value_get_boxed (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void
har_request_body_class_init (HarRequestBodyClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = har_request_body_get_property;
  G_OBJECT_CLASS (klass)->set_property = har_request_body_set_property;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_COMMENT,
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarMessageBody */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_COMPRESSED_LENGTH,
    g_param_spec_int ("compressedSize", "compressedSize", "", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_COMPRESSION,
    g_param_spec_int ("compression", "compression", "", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_ENCODING,
    g_param_spec_string ("encoding", "encoding", "", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_MIME_TYPE,
    g_param_spec_string ("mimeType", "mime-type", "", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_CHARSET,
    g_param_spec_string ("charset", "charset", "", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_LENGTH,
    g_param_spec_int ("size", "size", "", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_REQUEST_BODY_TEXT,
    g_param_spec_boxed ("text", "text", "", G_TYPE_BYTES, FLAGS));

#undef FLAGS

}


static void
har_request_body_init (HarRequestBody * self)
{
  g_return_if_fail (self != NULL);
}


HarRequestBody *
har_request_body_new (void)
{
  return g_object_new (HAR_TYPE_REQUEST_BODY, NULL);
}



const gchar * har_request_body_get_comment (HarRequestBody * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void har_request_body_set_comment (HarRequestBody * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


gint har_request_body_get_compressed_size (HarRequestBody * self)
{
  return har_message_body_get_compressed_size (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_compressed_size (HarRequestBody * self, gint value)
{
  har_message_body_set_compressed_size (HAR_MESSAGE_BODY (self), value);
}


gint har_request_body_get_compression (HarRequestBody * self)
{
  return har_message_body_get_compression (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_compression (HarRequestBody * self, gint value)
{
  har_message_body_set_compression (HAR_MESSAGE_BODY (self), value);
}


const gchar * har_request_body_get_encoding (HarRequestBody * self)
{
  return har_message_body_get_encoding (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_encoding (HarRequestBody * self, const gchar * value)
{
  har_message_body_set_encoding (HAR_MESSAGE_BODY (self), value);
}


const gchar * har_request_body_get_mime_type (HarRequestBody * self)
{
  return har_message_body_get_mime_type (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_mime_type (HarRequestBody * self, const gchar * value)
{
  har_message_body_set_mime_type (HAR_MESSAGE_BODY (self), value);
}


const gchar * har_request_body_get_charset (HarRequestBody * self)
{
  return har_message_body_get_charset (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_charset (HarRequestBody * self, const gchar * value)
{
  har_message_body_set_charset (HAR_MESSAGE_BODY (self), value);
}


gint har_request_body_get_size (HarRequestBody * self)
{
  return har_message_body_get_size (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_size (HarRequestBody * self, gint value)
{
  har_message_body_set_size (HAR_MESSAGE_BODY (self), value);
}


GBytes * har_request_body_get_text (HarRequestBody * self)
{
  return har_message_body_get_text (HAR_MESSAGE_BODY (self));
}


void har_request_body_set_text (HarRequestBody * self, GBytes * value)
{
  har_message_body_set_text (HAR_MESSAGE_BODY (self), value);
}


