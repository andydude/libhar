/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_MESSAGE_BODY_H__
#define __HAR_MESSAGE_BODY_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_MESSAGE_BODY             (har_message_body_get_type())
#define HAR_MESSAGE_BODY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_MESSAGE_BODY, HarMessageBody)
#define HAR_MESSAGE_BODY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_MESSAGE_BODY, HarMessageBodyClass)
#define HAR_IS_MESSAGE_BODY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_MESSAGE_BODY)
#define HAR_IS_MESSAGE_BODY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_MESSAGE_BODY)
#define HAR_MESSAGE_BODY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_MESSAGE_BODY, HarMessageBodyClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarMessageBody HarMessageBody;
typedef struct _HarMessageBodyClass HarMessageBodyClass;
typedef struct _HarMessageBodyPrivate HarMessageBodyPrivate;

struct _HarMessageBodyPrivate
{
  gint _length;
  gint _compressed_length; /* */
  gint _compression;
  const gchar * _encoding;
  const gchar * _mime_type;
  const gchar * _charset;
  GBytes * _content;
};

struct _HarMessageBody
{
  HarObject parent_instance;
  HarMessageBodyPrivate * priv;
};

struct _HarMessageBodyClass
{
  HarObjectClass parent_class;
};

enum _HarMessageBodyProperties {
  HAR_MESSAGE_BODY_DUMMY_PROPERTY,

  /* HarObject */
  HAR_MESSAGE_BODY_COMMENT,

  /* HarMessageBody */
  HAR_MESSAGE_BODY_COMPRESSED_LENGTH,
  HAR_MESSAGE_BODY_COMPRESSION,
  HAR_MESSAGE_BODY_ENCODING,
  HAR_MESSAGE_BODY_MIME_TYPE,
  HAR_MESSAGE_BODY_CHARSET,
  HAR_MESSAGE_BODY_LENGTH, /* HAR_MESSAGE_BODY_SIZE was taken */
  HAR_MESSAGE_BODY_TEXT,

  HAR_MESSAGE_BODY_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_message_body_get_type:
 *
 * Returns: (type GType): the #HarMessageBody #GType.
 */
GType har_message_body_get_type (void) G_GNUC_CONST;

/**
 * har_message_body_new:
 *
 * Returns: (transfer full): a #HarMessageBody.
 */
HarMessageBody * har_message_body_new (void);

/**
 * har_message_body_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_message_body_get_comment (HarMessageBody * self);

/**
 * har_message_body_set_comment:
 *
 */
void har_message_body_set_comment (HarMessageBody * self, const gchar * value);

/**
 * har_message_body_get_compressed_size:
 */
gint har_message_body_get_compressed_size (HarMessageBody * self);

/**
 * har_message_body_set_compressed_size:
 */
void har_message_body_set_compressed_size (HarMessageBody * self, gint value);

/**
 * har_message_body_get_compression:
 */
gint har_message_body_get_compression (HarMessageBody * self);

/**
 * har_message_body_set_compression:
 */
void har_message_body_set_compression (HarMessageBody * self, gint value);

/**
 * har_message_body_get_encoding:
 */
const gchar * har_message_body_get_encoding (HarMessageBody * self);

/**
 * har_message_body_set_encoding:
 */
void har_message_body_set_encoding (HarMessageBody * self, const gchar * value);

/**
 * har_message_body_get_mime_type:
 */
const gchar * har_message_body_get_mime_type (HarMessageBody * self);

/**
 * har_message_body_set_mime_type:
 */
void har_message_body_set_mime_type (HarMessageBody * self, const gchar * value);

/**
 * har_message_body_get_charset:
 */
const gchar * har_message_body_get_charset (HarMessageBody * self);

/**
 * har_message_body_set_charset:
 */
void har_message_body_set_charset (HarMessageBody * self, const gchar * value);

/**
 * har_message_body_get_size:
 */
gint har_message_body_get_size (HarMessageBody * self);

/**
 * har_message_body_set_size:
 */
void har_message_body_set_size (HarMessageBody * self, gint value);

/**
 * har_message_body_get_text:
 */
GBytes * har_message_body_get_text (HarMessageBody * self);

/**
 * har_message_body_set_text:
 */
void har_message_body_set_text (HarMessageBody * self, GBytes * value);

G_END_DECLS

#endif
