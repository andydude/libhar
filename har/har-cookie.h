/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_COOKIE_H__
#define __HAR_COOKIE_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_COOKIE             (har_cookie_get_type())
#define HAR_COOKIE(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_COOKIE, HarCookie)
#define HAR_COOKIE_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_COOKIE, HarCookieClass)
#define HAR_IS_COOKIE(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_COOKIE)
#define HAR_IS_COOKIE_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_COOKIE)
#define HAR_COOKIE_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_COOKIE, HarCookieClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarCookie HarCookie;
typedef struct _HarCookieClass HarCookieClass;

struct _HarCookie
{
  HarObject parent_instance;
  const gchar * name;
  const gchar * value;
};

struct _HarCookieClass
{
  HarObjectClass parent_class;
};

enum _HarCookieProperties {
  HAR_COOKIE_DUMMY_PROPERTY,

  /* HarObject */
  HAR_COOKIE_COMMENT,

  /* HarCookie */
  HAR_COOKIE_NAME,
  HAR_COOKIE_VALUE,
  
  HAR_COOKIE_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_cookie_get_type:
 *
 * Returns: (type GType): the #HarCookie #GType.
 */
GType har_cookie_get_type (void) G_GNUC_CONST;

/**
 * har_cookie_new:
 *
 * Returns: (transfer full): a #HarCookie.
 */
HarCookie * har_cookie_new (void);

/**
 * har_cookie_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_cookie_get_comment (HarCookie * self);

/**
 * har_cookie_set_comment:
 *
 */
void har_cookie_set_comment (HarCookie * self, const gchar * value);

/**
 * har_cookie_get_name:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_cookie_get_name (HarCookie * self);

/**
 * har_cookie_set_name:
 *
 */
void har_cookie_set_name (HarCookie * self, const gchar * value);

/**
 * har_cookie_get_value:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_cookie_get_value (HarCookie * self);

/**
 * har_cookie_set_value:
 *
 */
void har_cookie_set_value (HarCookie * self, const gchar * value);

G_END_DECLS

#endif
