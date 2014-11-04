/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_OBJECT_H__
#define __HAR_OBJECT_H__

#include <glib.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>

/*
 * Type macros.
 */

#define HAR_TYPE_OBJECT             (har_object_get_type())
#define HAR_OBJECT(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_OBJECT, HarObject)
#define HAR_OBJECT_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_OBJECT, HarObjectClass)
#define HAR_IS_OBJECT(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_OBJECT)
#define HAR_IS_OBJECT_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_OBJECT)
#define HAR_OBJECT_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_OBJECT, HarObjectClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarObject HarObject;
typedef struct _HarObjectClass HarObjectClass;

struct _HarObject
{
  /*< private >*/
  GObject parent_instance;
  /*< public >*/

  const gchar * comment;
};

struct _HarObjectClass
{
  /*< private >*/
  GObjectClass parent_class;
};

enum _HarObjectProperties {
  HAR_OBJECT_DUMMY_PROPERTY,

  /* HarObject */
  HAR_OBJECT_COMMENT,

  HAR_OBJECT_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_object_get_type:
 *
 * Returns: (type GType): the #HarObject #GType.
 */
GType har_object_get_type (void) G_GNUC_CONST;

/**
 * har_object_new:
 *
 * Returns: (transfer full): a #HarObject.
 */
HarObject * har_object_new (void);

/**
 * har_object_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_object_get_comment (HarObject * self);

/**
 * har_object_set_comment:
 *
 */
void har_object_set_comment (HarObject * self, const gchar * value);

G_END_DECLS

#endif
