/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-cache.h"


/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_TYPE(HarCache, har_cache, HAR_TYPE_OBJECT)


static void 
har_cache_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarCache * self;
  self = HAR_CACHE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_CACHE_COMMENT:
    g_value_set_string (value, har_cache_get_comment (self));
    break;

    /* HarCache */
  case HAR_CACHE_BEFORE_REQUEST:
    g_value_set_object (value, har_cache_get_before_request (self));
    break;
  case HAR_CACHE_AFTER_REQUEST:
    g_value_set_object (value, har_cache_get_after_request (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cache_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarCache * self;
  self = HAR_CACHE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_CACHE_COMMENT:
    har_cache_set_comment (self, g_value_get_string (value));
    break;

    /* HarCache */
  case HAR_CACHE_BEFORE_REQUEST:
    har_cache_set_before_request (self, g_value_get_object (value));
    break;
  case HAR_CACHE_AFTER_REQUEST:
    har_cache_set_after_request (self, g_value_get_object (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_cache_class_init (HarCacheClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_cache_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_cache_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarCache */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_BEFORE_REQUEST, 
    g_param_spec_object ("before-request", "beforeRequest", "TODO.", HAR_TYPE_CACHE_ENTRY, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_CACHE_AFTER_REQUEST, 
    g_param_spec_object ("after-request", "afterRequest", "TODO.", HAR_TYPE_CACHE_ENTRY, FLAGS));

#undef FLAGS

}


static void 
har_cache_init (HarCache * self)
{
  g_return_if_fail (self != NULL);

  self->before_request = har_cache_entry_new();
  self->after_request = har_cache_entry_new();
}


HarCache * 
har_cache_new (void)
{
  return g_object_new (HAR_TYPE_CACHE, NULL);
}


const gchar * 
har_cache_get_comment (HarCache * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_cache_set_comment (HarCache * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


HarCacheEntry * 
har_cache_get_before_request (HarCache * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->before_request;
}


void 
har_cache_set_before_request (HarCache * self, HarCacheEntry * value)
{
  g_return_if_fail (self != NULL);
  self->before_request = value;
  g_object_notify ((GObject *) self, "before-request");
}


HarCacheEntry * 
har_cache_get_after_request (HarCache * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->after_request;
}


void 
har_cache_set_after_request (HarCache * self, HarCacheEntry * value)
{
  g_return_if_fail (self != NULL);
  self->after_request = value;
  g_object_notify ((GObject *) self, "after-request");
}

