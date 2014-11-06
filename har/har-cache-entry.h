/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_CACHEENTRY_H__
#define __HAR_CACHEENTRY_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_CACHE_ENTRY             (har_cache_entry_get_type())
#define HAR_CACHE_ENTRY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_CACHE_ENTRY, HarCacheEntry)
#define HAR_CACHE_ENTRY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_CACHE_ENTRY, HarCacheEntryClass)
#define HAR_IS_CACHE_ENTRY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_CACHE_ENTRY)
#define HAR_IS_CACHE_ENTRY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_CACHE_ENTRY)
#define HAR_CACHE_ENTRY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_CACHE_ENTRY, HarCacheEntryClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarCacheEntry HarCacheEntry;
typedef struct _HarCacheEntryClass HarCacheEntryClass;

struct _HarCacheEntry
{
  /*< private >*/
  HarObject parent_instance;

  /*< public >*/
  GDateTime * expires;
  GDateTime * last_access;
  gchar * etag;
  gint hit_count;
};

struct _HarCacheEntryClass
{
  /*< private >*/
  HarObjectClass parent_class;
};

enum _HarCacheEntryProperties {
  HAR_CACHE_ENTRY_DUMMY_PROPERTY,

  /* HarObject */
  HAR_CACHE_ENTRY_COMMENT,

  /* HarCacheEntry */
  HAR_CACHE_ENTRY_EXPIRES,
  HAR_CACHE_ENTRY_LAST_ACCESS,
  HAR_CACHE_ENTRY_ETAG,
  HAR_CACHE_ENTRY_HIT_COUNT,
  
  HAR_CACHE_ENTRY_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_cache_entry_get_type:
 *
 * Returns: (type GType): the #HarCacheEntry #GType.
 */
GType har_cache_entry_get_type (void) G_GNUC_CONST;

/**
 * har_cache_entry_new:
 *
 * Returns: (constructor) (transfer full): a #HarCacheEntry.
 */
HarCacheEntry * har_cache_entry_new (void);

/**
 * har_cache_entry_get_comment:
 *
 * Returns: (type utf8) (transfer full): a string.
 */
const gchar * har_cache_entry_get_comment (HarCacheEntry * self);

/**
 * har_cache_entry_set_comment:
 * @self: (inout): a #HarCacheEntry.
 * @value: (in) (transfer full): a string.
 *
 */
void har_cache_entry_set_comment (HarCacheEntry * self, const gchar * value);


/**
 * har_cache_entry_get_expires:
 * @self: (inout): a #HarCacheEntry.
 *
 * Returns: (transfer full): a #GDateTime.
 */
GDateTime * har_cache_entry_get_expires (HarCacheEntry * self);

/**
 * har_cache_entry_set_expires:
 * @self: (inout): a #HarCacheEntry.
 * @value: (in) (transfer full): a #GDateTime.
 *
 */
void har_cache_entry_set_expires (HarCacheEntry * self, GDateTime * value);

/**
 * har_cache_entry_get_last_access:
 * @self: (inout): a #HarCacheEntry.
 *
 * Returns: (transfer full): a #GDateTime.
 */
GDateTime * har_cache_entry_get_last_access (HarCacheEntry * self);

/**
 * har_cache_entry_set_last_access:
 * @self: (inout): a #HarCacheEntry.
 * @value: (in) (transfer full): a #GDateTime.
 *
 */
void har_cache_entry_set_last_access (HarCacheEntry * self, GDateTime * value);

/**
 * har_cache_entry_get_etag:
 * @self: (inout): a #HarCacheEntry.
 *
 * Returns: (transfer full): a string.
 */
const gchar * har_cache_entry_get_etag (HarCacheEntry * self);

/**
 * har_cache_entry_set_etag:
 * @self: (inout): a #HarCacheEntry.
 * @value: (type utf8) (transfer full): a string.
 *
 */
void har_cache_entry_set_etag (HarCacheEntry * self, const gchar * value);

/**
 * har_cache_entry_get_hit_count:
 * @self: (inout): a #HarCacheEntry.
 *
 * Returns: a number.
 */
gint har_cache_entry_get_hit_count (HarCacheEntry * self);

/**
 * har_cache_entry_set_hit_count:
 * @self: (inout): a #HarCacheEntry.
 * @value: (in): a number.
 *
 */
void har_cache_entry_set_hit_count (HarCacheEntry * self, gint value);

G_END_DECLS

#endif
