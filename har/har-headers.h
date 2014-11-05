/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_HEADERS_H__
#define __HAR_HEADERS_H__

#include <glib.h>
#include <glib-object.h>

#include "har-header.h"

/*
 * Type macros.
 */

#define HAR_TYPE_HEADERS             (har_headers_get_type())
#define HAR_HEADERS(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_HEADERS, HarHeaders)
#define HAR_HEADERS_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_HEADERS, HarHeadersClass)
#define HAR_IS_HEADERS(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_HEADERS)
#define HAR_IS_HEADERS_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_HEADERS)
#define HAR_HEADERS_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_HEADERS, HarHeadersClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarHeaders HarHeaders;
typedef struct _HarHeadersClass HarHeadersClass;
typedef struct _HarHeadersPrivate HarHeadersPrivate;

struct _HarHeaders
{
  HarObject parent_instance;
  GSList * list;
};

struct _HarHeadersClass
{
  HarObjectClass parent_class;
};

enum _HarHeadersProperties {
  HAR_HEADERS_DUMMY_PROPERTY,

  /* HarObject */
  HAR_HEADERS_COMMENT,

  /* HarHeaders */
  HAR_HEADERS_LIST,
  
  HAR_HEADERS_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_headers_get_type:
 *
 * Returns: (type GType): the #HarHeaders #GType.
 */
GType har_headers_get_type (void) G_GNUC_CONST;

/**
 * har_headers_new:
 *
 * Returns: (transfer full): a #HarHeaders.
 */
HarHeaders * har_headers_new (void);

/**
 * har_headers_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_headers_get_comment (HarHeaders * self);

/**
 * har_headers_set_comment:
 *
 */
void har_headers_set_comment (HarHeaders * self, const gchar * value);

/**
 * har_headers_get_list:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_headers_get_list (HarHeaders * self);

/**
 * har_headers_set_list:
 *
 */
void har_headers_set_list (HarHeaders * self, const gchar * value);

/**
 * har_headers_get_accept:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_headers_get_accept (HarHeaders * self);

/**
 * har_headers_set_accept:
 *
 */
void har_headers_set_accept (HarHeaders * self, const gchar * value);

G_END_DECLS

#endif
