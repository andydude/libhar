/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_MESSAGE_H__
#define __HAR_MESSAGE_H__

#include <glib.h>
#include <glib-object.h>

#include "har-headers.h"
#include "har-message-body.h"

/*
 * Type macros.
 */

#define HAR_TYPE_MESSAGE             (har_message_get_type())
#define HAR_MESSAGE(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_MESSAGE, HarMessage)
#define HAR_MESSAGE_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_MESSAGE, HarMessageClass)
#define HAR_IS_MESSAGE(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_MESSAGE)
#define HAR_IS_MESSAGE_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_MESSAGE)
#define HAR_MESSAGE_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_MESSAGE, HarMessageClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarMessage HarMessage;
typedef struct _HarMessageClass HarMessageClass;
typedef struct _HarMessagePrivate HarMessagePrivate;

struct _HarMessage
{
  HarObject parent_instance;
  HarMessagePrivate * priv;
  GSList * cookies;
  HarHeaders * headers;
};

struct _HarMessageClass
{
  HarObjectClass parent_class;
};

enum _HarMessageProperties {
  HAR_MESSAGE_DUMMY_PROPERTY,

  /* HarObject */
  HAR_MESSAGE_COMMENT,

  /* HarMessage */
  HAR_MESSAGE_VERSION,
  HAR_MESSAGE_COOKIES,
  HAR_MESSAGE_HEADERS,
  HAR_MESSAGE_BODY,
  HAR_MESSAGE_HEADERS_SIZE,
  HAR_MESSAGE_BODY_SIZE,
  HAR_MESSAGE_HTTP_VERSION,
  //HAR_MESSAGE_HTTP_HEADERS,

  HAR_MESSAGE_N_PROPERTIES
};

/*
 * Method definitions.
 */

HarMessage * har_message_new (void);

GType har_message_get_type (void) G_GNUC_CONST;

/**
 * har_message_get_comment:
 * @self: a #HarMessage.
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_message_get_comment (HarMessage * self);

/**
 * har_message_set_comment:
 * @self: a #HarMessage.
 * @value: a string.
 */
void har_message_set_comment (HarMessage * self, const gchar * value);

/**
 * har_message_get_version:
 * @self: a #HarMessage.
 *
 * Returns: a number.
 */
guint har_message_get_version (HarMessage * self);

/**
 * har_message_set_version:
 * @self: a #HarMessage.
 * @value: a number.
 */
void har_message_set_version (HarMessage * self, guint value);

/**
 * har_message_get_cookies:
 * @self: a #HarMessage.
 *
 * Returns: (transfer none) (element-type HarCookie): a #GSList of #HarCookie.
 */
GSList * har_message_get_cookies (HarMessage * self);

/**
 * har_message_set_cookies:
 * @self: a #HarMessage.
 * @value: (transfer full) (element-type HarCookie): a #GSList of #HarCookie.
 */
void har_message_set_cookies (HarMessage * self, GSList * value);

/**
 * har_message_get_headers:
 * @self: a #HarMessage.
 *
 * Returns: (transfer none) (element-type HarHeader): a #GSList of #HarHeader.
 */
GSList * har_message_get_headers (HarMessage * self);

/**
 * har_message_set_headers:
 * @self: a #HarMessage.
 * @value: (transfer full) (element-type HarHeader): a #GSList of #HarHeader.
 */
void har_message_set_headers (HarMessage * self, GSList * value);

///**
// * har_message_get_body:
// * @self: a #HarMessage.
// *
// * Returns: (transfer none) (type HarMessageBody): a #HarMessageBody.
// */
//HarMessageBody * har_message_get_body (HarMessage * self);
//
///**
// * har_message_set_body:
// * @self: a #HarMessage.
// * @value: (transfer full) (type HarMessageBody): a #HarMessageBody.
// */
//void har_message_set_body (HarMessage * self, HarMessageBody * value);

/**
 * har_message_get_headers_size:
 * @self: a #HarMessage.
 *
 * Returns: a number.
 */
gint har_message_get_headers_size (HarMessage * self);

/**
 * har_message_set_headers_size:
 * @self: a #HarMessage.
 * @value: a number.
 */
void har_message_set_headers_size (HarMessage * self, gint value);

/**
 * har_message_get_body_size:
 * @self: a #HarMessage.
 *
 * Returns: a number.
 */
gint har_message_get_body_size (HarMessage * self);

/**
 * har_message_set_body_size:
 * @self: a #HarMessage.
 * @value: a number.
 */
void har_message_set_body_size (HarMessage * self, gint value);

/**
 * har_message_get_http_version:
 * @self: a #HarMessage.
 *
 * Returns: a number.
 */
const gchar * har_message_get_http_version (HarMessage * self);

/**
 * har_message_set_http_version:
 * @self: a #HarMessage.
 * @value: a number.
 */
void har_message_set_http_version (HarMessage * self, const gchar * value);

///**
// * har_message_get_http_headers:
// * @self: a #HarMessage.
// *
// * Returns: a number.
// */
//HarHeaders * har_message_get_http_headers (HarMessage * self);
//
///**
// * har_message_set_http_headers:
// * @self: a #HarMessage.
// * @value: a number.
// */
//void har_message_set_http_headers (HarMessage * self, HarHeaders * value);


G_END_DECLS

#endif
