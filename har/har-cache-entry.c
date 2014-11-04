/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-cache-entry.h"

/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarCacheEntry, har_cache_entry, HAR_TYPE_OBJECT)


static void 
har_cache_entry_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarCacheEntry * self;
  self = HAR_CACHE_ENTRY (object);
  switch (property_id) {

    /* HarObject */
  case HAR_CACHE_ENTRY_COMMENT:
    g_value_set_string (value, har_cache_entry_get_comment (self));
    break;

    /* HarCacheEntry */
  case HAR_CACHE_ENTRY_EXPIRES:
    g_value_set_boxed (value, har_cache_entry_get_expires (self));
    break;
  case HAR_CACHE_ENTRY_LAST_ACCESS:
    g_value_set_boxed (value, har_cache_entry_get_last_access (self));
    break;
  case HAR_CACHE_ENTRY_ETAG:
    g_value_set_string (value, har_cache_entry_get_etag (self));
    break;
  case HAR_CACHE_ENTRY_HIT_COUNT:
    g_value_set_int (value, har_cache_entry_get_hit_count (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cache_entry_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarCacheEntry * self;
  self = HAR_CACHE_ENTRY (object);
  switch (property_id) {

    /* HarObject */
  case HAR_CACHE_ENTRY_COMMENT:
    har_cache_entry_set_comment (self, g_value_get_string (value));
    break;

    /* HarCacheEntry */
  case HAR_CACHE_ENTRY_EXPIRES:
    har_cache_entry_set_expires (self, g_value_get_boxed (value));
    break;
  case HAR_CACHE_ENTRY_LAST_ACCESS:
    har_cache_entry_set_last_access (self, g_value_get_boxed (value));
    break;
  case HAR_CACHE_ENTRY_ETAG:
    har_cache_entry_set_etag (self, g_value_get_string (value));
    break;
  case HAR_CACHE_ENTRY_HIT_COUNT:
    har_cache_entry_set_hit_count (self, g_value_get_int (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cache_entry_class_init (HarCacheEntryClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_cache_entry_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_cache_entry_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_ENTRY_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarCacheEntry */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_ENTRY_EXPIRES, 
    g_param_spec_boxed ("expires", "expires", "TODO.", G_TYPE_DATE_TIME, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_ENTRY_LAST_ACCESS, 
    g_param_spec_boxed ("last-access", "lastAccess", "TODO.", G_TYPE_DATE_TIME, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_ENTRY_ETAG, 
    g_param_spec_string ("etag", "etag", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_ENTRY_HIT_COUNT, 
    g_param_spec_int ("hit-count", "hitCount", "TODO.", -1.0, G_MAXINT, -1.0, FLAGS));

#undef FLAGS

}


static void 
har_cache_entry_init (HarCacheEntry * self)
{
  g_return_if_fail (self != NULL);
}


HarCacheEntry * 
har_cache_entry_new (void)
{
  return g_object_new (HAR_TYPE_CACHE_ENTRY, NULL);
}


const gchar * 
har_cache_entry_get_comment (HarCacheEntry * self)
{
    return har_object_get_comment (HAR_OBJECT (self));
}

void 
har_cache_entry_set_comment (HarCacheEntry * self, const gchar * value)
{
    har_object_set_comment (HAR_OBJECT (self), value);
}


GDateTime * 
har_cache_entry_get_expires (HarCacheEntry * self)
{
    g_return_val_if_fail (self != NULL, NULL);
    return self->expires;
}

void 
har_cache_entry_set_expires (HarCacheEntry * self, GDateTime * value)
{
  g_return_if_fail (self != NULL);
}

GDateTime * 
har_cache_entry_get_last_access (HarCacheEntry * self)
{
    g_return_val_if_fail (self != NULL, NULL);
    return self->last_access;
}

void 
har_cache_entry_set_last_access (HarCacheEntry * self, GDateTime * value)
{
  g_return_if_fail (self != NULL);
}

const gchar * 
har_cache_entry_get_etag (HarCacheEntry * self)
{
    g_return_val_if_fail (self != NULL, NULL);
    return self->etag;
}

void 
har_cache_entry_set_etag (HarCacheEntry * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
}

gint 
har_cache_entry_get_hit_count (HarCacheEntry * self)
{
    g_return_val_if_fail (self != NULL, -1);
    return self->hit_count;
}

void 
har_cache_entry_set_hit_count (HarCacheEntry * self, gint value)
{
  g_return_if_fail (self != NULL);
}
