/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_RESPONSE_H__
#define __HAR_RESPONSE_H__

#include <glib.h>
#include <glib-object.h>

#include "har-message-body.h"
#include "har-message.h"
#include "har-response-body.h"

/*
 * Type macros.
 */

#define HAR_TYPE_RESPONSE             (har_response_get_type())
#define HAR_RESPONSE(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_RESPONSE, HarResponse)
#define HAR_RESPONSE_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_RESPONSE, HarResponseClass)
#define HAR_IS_RESPONSE(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_RESPONSE)
#define HAR_IS_RESPONSE_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_RESPONSE)
#define HAR_RESPONSE_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_RESPONSE, HarResponseClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarResponse HarResponse;
typedef struct _HarResponseClass HarResponseClass;
typedef struct _HarResponsePrivate HarResponsePrivate;

struct _HarResponsePrivate
{
  /*< private >*/
  const gchar * _reason;
  const gchar * _redirect_url;
};

struct _HarResponse
{
  /*< private >*/
  HarMessage parent_instance;
  HarResponsePrivate * priv;
  /*< public >*/

  guint status;
};

struct _HarResponseClass
{
  HarMessageClass parent_class;
};

enum _HarResponseProperties {
  HAR_RESPONSE_DUMMY_PROPERTY,

  /* HarObject */
  HAR_RESPONSE_COMMENT,

  /* HarMessage */
  HAR_RESPONSE_VERSION,
  HAR_RESPONSE_COOKIES,
  HAR_RESPONSE_HEADERS,
  HAR_RESPONSE_BODY,
  HAR_RESPONSE_HEADERS_SIZE,
  HAR_RESPONSE_BODY_SIZE,

  /* HarResponse */
  HAR_RESPONSE_STATUS,
  HAR_RESPONSE_REASON,
  HAR_RESPONSE_REDIRECT_URL,

  HAR_RESPONSE_N_PROPERTIES
};

/*
 * Method definitions.
 */

GType har_response_get_type (void) G_GNUC_CONST;
HarResponse * har_response_new (void);

const gchar * har_response_get_comment (HarResponse * self);
void har_response_set_comment (HarResponse * self, const gchar * value);

guint har_response_get_version (HarResponse * self);
void har_response_set_version (HarResponse * self, guint value);

/**
 * har_response_get_cookies:
 * @self: a #HarResponse.
 *
 * Returns: (transfer none) (element-type HarCookie): a #GSList of #HarCookie.
 */
GSList * har_response_get_cookies (HarResponse * self);

/**
 * har_response_set_cookies:
 * @self: a #HarResponse.
 * @value: (transfer full) (element-type HarCookie): a #GSList of #HarCookie.
 */
void har_response_set_cookies (HarResponse * self, GSList * value);

/**
 * har_response_get_headers:
 * @self: a #HarResponse.
 *
 * Returns: (transfer none) (type HarHeaders): a #HarHeaders.
 */
HarHeaders * har_response_get_headers (HarResponse * self);

/**
 * har_response_set_headers:
 * @self: a #HarResponse.
 * @value: (transfer full) (type HarHeaders): a #HarHeaders.
 */
void har_response_set_headers (HarResponse * self, HarHeaders * value);

/**
 * har_response_get_body:
 * @self: a #HarResponse.
 *
 * Returns: (transfer none) (type HarResponseBody): a #HarResponseBody.
 */

HarResponseBody * har_response_get_body (HarResponse * self);
/**
 * har_response_set_body:
 * @self: a #HarResponse.
 * @value: (transfer full) (type HarResponseBody): a #HarResponseBody.
 */
void har_response_set_body (HarResponse * self, HarResponseBody * value);

gint har_response_get_headers_size (HarResponse * self);
void har_response_set_headers_size (HarResponse * self, gint value);

gint har_response_get_body_size (HarResponse * self);
void har_response_set_body_size (HarResponse * self, gint value);

guint har_response_get_status (HarResponse * self);
void har_response_set_status (HarResponse * self, guint value);

const gchar * har_response_get_reason (HarResponse * self);
void har_response_set_reason (HarResponse * self, const gchar * value);

const gchar * har_response_get_redirect_url (HarResponse * self);
void har_response_set_redirect_url (HarResponse * self, const gchar * value);

G_END_DECLS

#endif
