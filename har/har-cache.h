/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_CACHE_H__
#define __HAR_CACHE_H__

#include <glib.h>
#include <glib-object.h>

#include "har-cache-entry.h"

/*
 * Type macros.
 */

#define HAR_TYPE_CACHE             (har_cache_get_type())
#define HAR_CACHE(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_CACHE, HarCache)
#define HAR_CACHE_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_CACHE, HarCacheClass)
#define HAR_IS_CACHE(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_CACHE)
#define HAR_IS_CACHE_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_CACHE)
#define HAR_CACHE_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_CACHE, HarCacheClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarCache HarCache;
typedef struct _HarCacheClass HarCacheClass;

struct _HarCache
{
  /*< private >*/
  HarObject parent_instance;
  /*< public >*/

  HarCacheEntry * before_request;
  HarCacheEntry * after_request;
};

struct _HarCacheClass
{
  /*< private >*/
  HarObjectClass parent_class;
};

enum _HarCacheProperties {
  HAR_CACHE_DUMMY_PROPERTY,

  /* HarObject */
  HAR_CACHE_COMMENT,

  /* HarCache */
  HAR_CACHE_BEFORE_REQUEST,
  HAR_CACHE_AFTER_REQUEST,

  HAR_CACHE_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_cache_get_type:
 *
 * Returns: (type GType): the #HarCache #GType.
 */
GType har_cache_get_type (void) G_GNUC_CONST;

/**
 * har_cache_new:
 *
 * Returns: (transfer full): a #HarCache.
 */
HarCache * har_cache_new (void);

/**
 * har_cache_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_cache_get_comment (HarCache * self);

/**
 * har_cache_set_comment:
 *
 */
void har_cache_set_comment (HarCache * self, const gchar * value);

/**
 * har_cache_get_before_request:
 *
 * Returns: (transfer full): a #HarCacheEntry.
 */
HarCacheEntry * har_cache_get_before_request (HarCache * self);

/**
 * har_cache_set_before_request:
 * @value: (transfer full): a #HarCacheEntry.
 */
void har_cache_set_before_request (HarCache * self, HarCacheEntry * value);

/**
 * har_cache_get_after_request:
 *
 * Returns: (transfer full): a #HarCacheEntry.
 */
HarCacheEntry * har_cache_get_after_request (HarCache * self);

/**
 * har_cache_set_after_request:
 * @value: (transfer full): a #HarCacheEntry.
 */
void har_cache_set_after_request (HarCache * self, HarCacheEntry * value);

G_END_DECLS

#endif
