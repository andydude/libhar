/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_POSTPARAM_H__
#define __HAR_POSTPARAM_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_POST_PARAM             (har_post_param_get_type())
#define HAR_POST_PARAM(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_POST_PARAM, HarPostParam)
#define HAR_POST_PARAM_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_POST_PARAM, HarPostParamClass)
#define HAR_IS_POST_PARAM(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_POST_PARAM)
#define HAR_IS_POST_PARAM_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_POST_PARAM)
#define HAR_POST_PARAM_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_POST_PARAM, HarPostParamClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarPostParam HarPostParam;
typedef struct _HarPostParamClass HarPostParamClass;

struct _HarPostParam
{
  HarObject parent_instance;
  const gchar * name;
  const gchar * value;
};

struct _HarPostParamClass
{
  HarObjectClass parent_class;
};

enum _HarPostParamProperties {
  HAR_POST_PARAM_DUMMY_PROPERTY,

  /* HarObject */
  HAR_POST_PARAM_COMMENT,
  HAR_POST_PARAM_METADATA,

  /* HarPostParam */
  HAR_POST_PARAM_NAME,
  HAR_POST_PARAM_VALUE,
  
  HAR_POST_PARAM_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_post_param_get_type:
 *
 * Returns: (type GType): the #HarPostParam #GType.
 */
GType har_post_param_get_type (void) G_GNUC_CONST;

/**
 * har_post_param_new:
 *
 * Returns: (transfer full): a #HarPostParam.
 */
HarPostParam * har_post_param_new (void);

/**
 * har_post_param_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_post_param_get_comment (HarPostParam * self);

/**
 * har_post_param_set_comment:
 *
 */
void har_post_param_set_comment (HarPostParam * self, const gchar * value);

/**
 * har_post_param_get_name:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_post_param_get_name (HarPostParam * self);

/**
 * har_post_param_set_name:
 *
 */
void har_post_param_set_name (HarPostParam * self, const gchar * value);

/**
 * har_post_param_get_value:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_post_param_get_value (HarPostParam * self);

/**
 * har_post_param_set_value:
 *
 */
void har_post_param_set_value (HarPostParam * self, const gchar * value);

G_END_DECLS

#endif
