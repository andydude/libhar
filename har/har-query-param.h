/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_QUERYPARAM_H__
#define __HAR_QUERYPARAM_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_QUERY_PARAM             (har_query_param_get_type())
#define HAR_QUERY_PARAM(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_QUERY_PARAM, HarQueryParam)
#define HAR_QUERY_PARAM_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_QUERY_PARAM, HarQueryParamClass)
#define HAR_IS_QUERY_PARAM(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_QUERY_PARAM)
#define HAR_IS_QUERY_PARAM_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_QUERY_PARAM)
#define HAR_QUERY_PARAM_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_QUERY_PARAM, HarQueryParamClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarQueryParam HarQueryParam;
typedef struct _HarQueryParamClass HarQueryParamClass;

struct _HarQueryParam
{
  HarObject parent_instance;
  const gchar * name;
  const gchar * value;
};

struct _HarQueryParamClass
{
  HarObjectClass parent_class;
};

enum _HarQueryParamProperties {
  HAR_QUERY_PARAM_DUMMY_PROPERTY,

  /* HarObject */
  HAR_QUERY_PARAM_COMMENT,
  HAR_QUERY_PARAM_METADATA,

  /* HarQueryParam */
  HAR_QUERY_PARAM_NAME,
  HAR_QUERY_PARAM_VALUE,
  
  HAR_QUERY_PARAM_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_query_param_get_type:
 *
 * Returns: (type GType): the #HarQueryParam #GType.
 */
GType har_query_param_get_type (void) G_GNUC_CONST;

/**
 * har_query_param_new:
 *
 * Returns: (transfer full): a #HarQueryParam.
 */
HarQueryParam * har_query_param_new (void);

/**
 * har_query_param_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_query_param_get_comment (HarQueryParam * self);

/**
 * har_query_param_set_comment:
 *
 */
void har_query_param_set_comment (HarQueryParam * self, const gchar * value);

/**
 * har_query_param_get_name:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_query_param_get_name (HarQueryParam * self);

/**
 * har_query_param_set_name:
 *
 */
void har_query_param_set_name (HarQueryParam * self, const gchar * value);

/**
 * har_query_param_get_value:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_query_param_get_value (HarQueryParam * self);

/**
 * har_query_param_set_value:
 *
 */
void har_query_param_set_value (HarQueryParam * self, const gchar * value);

G_END_DECLS

#endif
