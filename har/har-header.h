/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_HEADER_H__
#define __HAR_HEADER_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_HEADER             (har_header_get_type())
#define HAR_HEADER(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_HEADER, HarHeader)
#define HAR_HEADER_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_HEADER, HarHeaderClass)
#define HAR_IS_HEADER(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_HEADER)
#define HAR_IS_HEADER_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_HEADER)
#define HAR_HEADER_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_HEADER, HarHeaderClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarHeader HarHeader;
typedef struct _HarHeaderClass HarHeaderClass;

struct _HarHeader
{
  HarObject parent_instance;
  const gchar * name;
  const gchar * value;
};

struct _HarHeaderClass
{
  HarObjectClass parent_class;
};

enum _HarHeaderProperties {
  HAR_HEADER_DUMMY_PROPERTY,

  /* HarObject */
  HAR_HEADER_COMMENT,

  /* HarHeader */
  HAR_HEADER_NAME,
  HAR_HEADER_VALUE,
  
  HAR_HEADER_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_header_get_type:
 *
 * Returns: (type GType): the #HarHeader #GType.
 */
GType har_header_get_type (void) G_GNUC_CONST;

/**
 * har_header_new:
 *
 * Returns: (transfer full): a #HarHeader.
 */
HarHeader * har_header_new (void);

/**
 * har_header_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_header_get_comment (HarHeader * self);

/**
 * har_header_set_comment:
 *
 */
void har_header_set_comment (HarHeader * self, const gchar * value);

/**
 * har_header_get_name:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_header_get_name (HarHeader * self);

/**
 * har_header_set_name:
 *
 */
void har_header_set_name (HarHeader * self, const gchar * value);

/**
 * har_header_get_value:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_header_get_value (HarHeader * self);

/**
 * har_header_set_value:
 *
 */
void har_header_set_value (HarHeader * self, const gchar * value);

G_END_DECLS

#endif
