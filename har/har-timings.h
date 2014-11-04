/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_TIMINGS_H__
#define __HAR_TIMINGS_H__

#include <glib.h>
#include <glib-object.h>

#include "har-object.h"

/*
 * Type macros.
 */

#define HAR_TYPE_TIMINGS             (har_timings_get_type())
#define HAR_TIMINGS(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_TIMINGS, HarTimings)
#define HAR_TIMINGS_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_TIMINGS, HarTimingsClass)
#define HAR_IS_TIMINGS(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_TIMINGS)
#define HAR_IS_TIMINGS_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_TIMINGS)
#define HAR_TIMINGS_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_TIMINGS, HarTimingsClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarTimings HarTimings;
typedef struct _HarTimingsClass HarTimingsClass;
typedef struct _HarTimingsPrivate HarTimingsPrivate;

struct _HarTimings
{
  /*< private >*/
  HarObject parent_instance;
  HarTimingsPrivate * priv;

  /*< public >*/
  gdouble dns;
  gdouble connect;
  gdouble ssl;
  gdouble send;
  gdouble wait;
  gdouble receive;
  gdouble redirect;
};

struct _HarTimingsClass
{
  /*< private >*/
  HarObjectClass parent_class;
};

enum _HarTimingsProperties {
  HAR_TIMINGS_DUMMY_PROPERTY,

  /* HarObject */
  HAR_TIMINGS_COMMENT,

  /* HarTimings */
  HAR_TIMINGS_DNS,
  HAR_TIMINGS_CONNECT,
  HAR_TIMINGS_SSL,
  HAR_TIMINGS_SEND,
  HAR_TIMINGS_WAIT,
  HAR_TIMINGS_RECEIVE,
  HAR_TIMINGS_REDIRECT,
  HAR_TIMINGS_TOTAL,

  HAR_TIMINGS_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_timings_get_type:
 *
 * Returns: (transfer full) (type HarTimings): the #GType #HarTimings.
 */
GType har_timings_get_type (void) G_GNUC_CONST;

/**
 * har_timings_new:
 *
 * Returns: (transfer full) (type HarTimings): a #HarTimings.
 */
HarTimings * har_timings_new (void);

/**
 * har_timings_sum_total:
 *
 * Returns: a double.
 */
gdouble har_timings_sum_total (HarTimings * self);

/**
 * har_timings_get_comment:
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_timings_get_comment (HarTimings * self);

/**
 * har_timings_set_comment:
 * @value: (type utf8) (transfer full): a string.
 */
void har_timings_set_comment (HarTimings * self, const gchar * value);

gdouble har_timings_get_dns (HarTimings * self);
void har_timings_set_dns (HarTimings * self, gdouble value);

gdouble har_timings_get_connect (HarTimings * self);
void har_timings_set_connect (HarTimings * self, gdouble value);

gdouble har_timings_get_ssl (HarTimings * self);
void har_timings_set_ssl (HarTimings * self, gdouble value);

gdouble har_timings_get_send (HarTimings * self);
void har_timings_set_send (HarTimings * self, gdouble value);

gdouble har_timings_get_wait (HarTimings * self);
void har_timings_set_wait (HarTimings * self, gdouble value);

gdouble har_timings_get_receive (HarTimings * self);
void har_timings_set_receive (HarTimings * self, gdouble value);

gdouble har_timings_get_redirect (HarTimings * self);
void har_timings_set_redirect (HarTimings * self, gdouble value);

gdouble har_timings_get_total (HarTimings * self);
void har_timings_set_total (HarTimings * self, gdouble value);

G_END_DECLS

#endif
