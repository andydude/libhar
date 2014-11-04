/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_REQUEST_BODY_H__
#define __HAR_REQUEST_BODY_H__

#include <glib.h>
#include <glib-object.h>

#include "har-message-body.h"

/*
 * Type macros.
 */

#define HAR_TYPE_REQUEST_BODY             (har_request_body_get_type())
#define HAR_REQUEST_BODY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_REQUEST_BODY, HarRequestBody)
#define HAR_REQUEST_BODY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_REQUEST_BODY, HarRequestBodyClass)
#define HAR_IS_REQUEST_BODY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_REQUEST_BODY)
#define HAR_IS_REQUEST_BODY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_REQUEST_BODY)
#define HAR_REQUEST_BODY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_REQUEST_BODY, HarRequestBodyClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarRequestBody HarRequestBody;
typedef struct _HarRequestBodyClass HarRequestBodyClass;

struct _HarRequestBody
{
  HarMessageBody parent_instance;
  GSList * params;
};

struct _HarRequestBodyClass
{
  HarMessageBodyClass parent_class;
};

enum _HarRequestBodyProperties {
  HAR_REQUEST_BODY_DUMMY_PROPERTY,

  /* HarObject */
  HAR_REQUEST_BODY_COMMENT,

  /* HarMessageBody */
  HAR_REQUEST_BODY_COMPRESSED_LENGTH,
  HAR_REQUEST_BODY_COMPRESSION,
  HAR_REQUEST_BODY_ENCODING,
  HAR_REQUEST_BODY_MIME_TYPE,
  HAR_REQUEST_BODY_CHARSET,
  HAR_REQUEST_BODY_LENGTH,
  HAR_REQUEST_BODY_TEXT,

  /* HarRequestBody */
  HAR_REQUEST_BODY_PARAMS,

  HAR_REQUEST_BODY_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_request_body_get_type:
 *
 * Returns: (type GType): the #HarRequestBody #GType.
 */
GType har_request_body_get_type (void) G_GNUC_CONST;

/**
 * har_request_body_new:
 *
 * Returns: (transfer full): a #HarRequestBody.
 */
HarRequestBody * har_request_body_new (void);

/**
 * har_request_body_get_comment:
 * @self: a #HarRequestBody.
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_request_body_get_comment (HarRequestBody * self);

/**
 * har_request_body_set_comment:
 * @self: a #HarRequestBody.
 * @value: a string.
 */
void har_request_body_set_comment (HarRequestBody * self, const gchar * value);

/**
 * har_request_body_get_compressed_size:
 * @self: a #HarRequestBody.
 */
gint har_request_body_get_compressed_size (HarRequestBody * self);

/**
 * har_request_body_set_compressed_size:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_compressed_size (HarRequestBody * self, gint value);

/**
 * har_request_body_get_compression:
 * @self: a #HarRequestBody.
 */
gint har_request_body_get_compression (HarRequestBody * self);

/**
 * har_request_body_set_compression:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_compression (HarRequestBody * self, gint value);

/**
 * har_request_body_get_encoding:
 * @self: a #HarRequestBody.
 */
const gchar * har_request_body_get_encoding (HarRequestBody * self);

/**
 * har_request_body_set_encoding:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_encoding (HarRequestBody * self, const gchar * value);

/**
 * har_request_body_get_mime_type:
 * @self: a #HarRequestBody.
 */
const gchar * har_request_body_get_mime_type (HarRequestBody * self);

/**
 * har_request_body_set_mime_type:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_mime_type (HarRequestBody * self, const gchar * value);

/**
 * har_request_body_get_charset:
 * @self: a #HarRequestBody.
 */
const gchar * har_request_body_get_charset (HarRequestBody * self);

/**
 * har_request_body_set_charset:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_charset (HarRequestBody * self, const gchar * value);

/**
 * har_request_body_get_size:
 * @self: a #HarRequestBody.
 */
gint har_request_body_get_size (HarRequestBody * self);

/**
 * har_request_body_set_size:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_size (HarRequestBody * self, gint value);

/**
 * har_request_body_get_text:
 * @self: a #HarRequestBody.
 */
GBytes * har_request_body_get_text (HarRequestBody * self);

/**
 * har_request_body_set_text:
 * @self: a #HarRequestBody.
 */
void har_request_body_set_text (HarRequestBody * self, GBytes * value);

/**
 * har_request_body_get_params:
 * @self: a #HarRequestBody.
 *
 * Returns: (transfer none) (element-type HarPostParam): a #GSList of #HarPostParam.
 */
GSList * har_request_body_get_params (HarRequestBody * self);

/**
 * har_request_body_set_params:
 * @self: a #HarRequestBody.
 * @value: (transfer full) (element-type HarPostParam): a #GSList of #HarPostParam.
 */
void har_request_body_set_params (HarRequestBody * self, GSList * value);

G_END_DECLS

#endif
