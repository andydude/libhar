/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_RESPONSE_BODY_H__
#define __HAR_RESPONSE_BODY_H__

#include <glib.h>
#include <glib-object.h>

#include "har-message-body.h"

/*
 * Type macros.
 */

#define HAR_TYPE_RESPONSE_BODY             (har_response_body_get_type())
#define HAR_RESPONSE_BODY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_RESPONSE_BODY, HarResponseBody)
#define HAR_RESPONSE_BODY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_RESPONSE_BODY, HarResponseBodyClass)
#define HAR_IS_RESPONSE_BODY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_RESPONSE_BODY)
#define HAR_IS_RESPONSE_BODY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_RESPONSE_BODY)
#define HAR_RESPONSE_BODY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_RESPONSE_BODY, HarResponseBodyClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarResponseBody HarResponseBody;
typedef struct _HarResponseBodyClass HarResponseBodyClass;

struct _HarResponseBody
{
  HarMessageBody parent_instance;
};

struct _HarResponseBodyClass
{
  HarMessageBodyClass parent_class;
};

enum _HarResponseBodyProperties {
  HAR_RESPONSE_BODY_DUMMY_PROPERTY,

  /* HarObject */
  HAR_RESPONSE_BODY_COMMENT,
  HAR_RESPONSE_BODY_METADATA,

  /* HarResponseBody */
  HAR_RESPONSE_BODY_VERSION,
  HAR_RESPONSE_BODY_COOKIES,
  HAR_RESPONSE_BODY_HEADERS,
  HAR_RESPONSE_BODY_BODY,
  HAR_RESPONSE_BODY_HEADERS_SIZE,
  HAR_RESPONSE_BODY_BODY_SIZE,

  HAR_RESPONSE_BODY_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_response_body_get_type:
 *
 * Returns: (type GType): the #HarResponseBody #GType.
 */
GType har_response_body_get_type (void) G_GNUC_CONST;

/**
 * har_response_body_new:
 *
 * Returns: (transfer full): a #HarResponseBody.
 */
HarResponseBody * har_response_body_new (void);

/**
 * har_response_body_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_response_body_get_comment (HarResponseBody * self);

/**
 * har_response_body_set_comment:
 *
 */
void har_response_body_set_comment (HarResponseBody * self, const gchar * value);

/**
 * har_response_body_get_compressed_size:
 */
gint har_response_body_get_compressed_size (HarResponseBody * self);

/**
 * har_response_body_set_compressed_size:
 */
void har_response_body_set_compressed_size (HarResponseBody * self, gint value);

/**
 * har_response_body_get_compression:
 */
gint har_response_body_get_compression (HarResponseBody * self);

/**
 * har_response_body_set_compression:
 */
void har_response_body_set_compression (HarResponseBody * self, gint value);

/**
 * har_response_body_get_encoding:
 */
const gchar * har_response_body_get_encoding (HarResponseBody * self);

/**
 * har_response_body_set_encoding:
 */
void har_response_body_set_encoding (HarResponseBody * self, const gchar * value);

/**
 * har_response_body_get_mime_type:
 */
const gchar * har_response_body_get_mime_type (HarResponseBody * self);

/**
 * har_response_body_set_mime_type:
 */
void har_response_body_set_mime_type (HarResponseBody * self, const gchar * value);

/**
 * har_response_body_get_charset:
 */
const gchar * har_response_body_get_charset (HarResponseBody * self);

/**
 * har_response_body_set_charset:
 */
void har_response_body_set_charset (HarResponseBody * self, const gchar * value);

/**
 * har_response_body_get_size:
 */
gint har_response_body_get_size (HarResponseBody * self);

/**
 * har_response_body_set_size:
 */
void har_response_body_set_size (HarResponseBody * self, gint value);

/**
 * har_response_body_get_text:
 */
GBytes * har_response_body_get_text (HarResponseBody * self);

/**
 * har_response_body_set_text:
 */
void har_response_body_set_text (HarResponseBody * self, GBytes * value);

G_END_DECLS

#endif
