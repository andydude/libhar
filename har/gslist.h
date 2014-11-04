/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_G_SLIST_H__
#define __HAR_G_SLIST_H__

#include <glib.h>
#include <glib-object.h>

/*
 * Type macros.
 */

#define G_TYPE_SLIST             (g_slist_get_type())
#define G_SLIST(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), G_TYPE_SLIST, GSlist)
#define G_SLIST_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  G_TYPE_SLIST, GSlistClass)
#define G_IS_SLIST(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), G_TYPE_SLIST)
#define G_IS_SLIST_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  G_TYPE_SLIST)
#define G_SLIST_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  G_TYPE_SLIST, GSlistClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

//typedef struct _GSList GSList;
//typedef struct _GSListClass GSListClass;
//
//struct _GSList
//{
//  /*< private >*/
//  GObject parent_instance;
//  /*< public >*/
//
//  const gchar * comment;
//};
//
//struct _GSListClass
//{
//  /*< private >*/
//  GObjectClass parent_class;
//};
//

GType g_slist_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif
