/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_REQUEST_H__
#define __HAR_REQUEST_H__

#include <glib.h>
#include <glib-object.h>

#include "har-message-body.h"
#include "har-message.h"
#include "har-request-body.h"

/*
 * Type macros.
 */

#define HAR_TYPE_REQUEST             (har_request_get_type())
#define HAR_REQUEST(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_REQUEST, HarRequest)
#define HAR_REQUEST_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_REQUEST, HarRequestClass)
#define HAR_IS_REQUEST(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_REQUEST)
#define HAR_IS_REQUEST_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_REQUEST)
#define HAR_REQUEST_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_REQUEST, HarRequestClass)

#define HarPostParams GSList
#define HarQueryParams GSList
#define HarCookies GSList

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarRequest HarRequest;
typedef struct _HarRequestClass HarRequestClass;
typedef struct _HarRequestPrivate HarRequestPrivate;

struct _HarRequestPrivate {
  /*< private >*/
  gboolean _auto_method;
};

struct _HarRequest
{
  HarMessage parent_instance;
  HarRequestPrivate * priv;
  const gchar * method;
  const gchar * url;
  GSList * query;
};

struct _HarRequestClass
{
  HarObjectClass parent_class;
};

enum _HarRequestProperties {
  HAR_REQUEST_DUMMY_PROPERTY,

  /* HarObject */
  HAR_REQUEST_COMMENT,

  /* HarMessage */
  HAR_REQUEST_VERSION,
  HAR_REQUEST_COOKIES,
  HAR_REQUEST_HEADERS,
  HAR_REQUEST_BODY,
  HAR_REQUEST_HEADERS_SIZE,
  HAR_REQUEST_BODY_SIZE,

  /* HarRequest */
  HAR_REQUEST_METHOD,
  HAR_REQUEST_URL,
  HAR_REQUEST_QUERY,

  HAR_REQUEST_N_PROPERTIES
};

/*
 * Method definitions.
 */


GType har_request_get_type (void) G_GNUC_CONST;
HarRequest * har_request_new (void);

const gchar * har_request_get_comment (HarRequest * self);
void har_request_set_comment (HarRequest * self, const gchar * value);

guint har_request_get_version (HarRequest * self);
void har_request_set_version (HarRequest * self, guint value);

/**
 * har_request_get_cookies:
 * @self: a #HarRequest.
 *
 * Returns: (transfer none) (element-type HarCookie): a #GSList of #HarCookie.
 */
GSList * har_request_get_cookies (HarRequest * self);

/**
 * har_request_set_cookies:
 * @self: a #HarRequest.
 * @value: (transfer full) (element-type HarCookie): a #GSList of #HarCookie.
 */
void har_request_set_cookies (HarRequest * self, GSList * value);

/**
 * har_request_get_headers:
 * @self: a #HarRequest.
 *
 * Returns: (transfer none) (type HarHeaders): a #HarHeaders.
 */
HarHeaders * har_request_get_headers (HarRequest * self);

/**
 * har_request_set_headers:
 * @self: a #HarRequest.
 * @value: (transfer full) (type HarHeaders): a #HarHeaders.
 */
void har_request_set_headers (HarRequest * self, HarHeaders * value);

/**
 * har_request_get_body:
 * @self: a #HarRequest.
 *
 * Returns: (transfer none) (type HarRequestBody): a #HarRequestBody.
 */
HarRequestBody * har_request_get_body (HarRequest * self);

/**
 * har_request_set_body:
 * @self: a #HarRequest.
 * @value: (transfer full) (type HarRequestBody): a #HarRequestBody.
 */
void har_request_set_body (HarRequest * self, HarRequestBody * value);

gint har_request_get_headers_size (HarRequest * self);
void har_request_set_headers_size (HarRequest * self, gint value);

gint har_request_get_body_size (HarRequest * self);
void har_request_set_body_size (HarRequest * self, gint value);

const gchar * har_request_get_method (HarRequest * self);
void har_request_set_method (HarRequest * self, const gchar * value);

const gchar * har_request_get_url (HarRequest * self);
void har_request_set_url (HarRequest * self, const gchar * value);

/**
 * har_request_get_query:
 * @self: a #HarRequest.
 *
 * Returns: (transfer none) (element-type HarQueryParam): a #GSList of #HarQueryParam.
 */
GSList * har_request_get_query (HarRequest * self);

/**
 * har_request_set_query:
 * @self: a #HarRequest.
 * @value: (transfer full) (element-type HarQueryParam): a #GSList of #HarQueryParam.
 */
void har_request_set_query (HarRequest * self, GSList * value);

G_END_DECLS

#endif
