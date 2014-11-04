/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_ENTRY_H__
#define __HAR_ENTRY_H__

#include <glib.h>
#include <glib-object.h>

#include "har-cache.h"
#include "har-request.h"
#include "har-response.h"
#include "har-timings.h"

/*
 * Type macros.
 */

#define HAR_TYPE_ENTRY             (har_entry_get_type())
#define HAR_ENTRY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), HAR_TYPE_ENTRY, HarEntry)
#define HAR_ENTRY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  HAR_TYPE_ENTRY, HarEntryClass)
#define HAR_IS_ENTRY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), HAR_TYPE_ENTRY)
#define HAR_IS_ENTRY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  HAR_TYPE_ENTRY)
#define HAR_ENTRY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  HAR_TYPE_ENTRY, HarEntryClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _HarEntry HarEntry;
typedef struct _HarEntryClass HarEntryClass;
typedef struct _HarEntryPrivate HarEntryPrivate;

struct _HarEntryPrivate 
{
  /*< private >*/
  gdouble _time;
  const gchar * _server_ip_address;
  guint _server_port;
  const gchar * _client_ip_address;
  guint _client_port;
  const gchar * _connection;
};

struct _HarEntry
{
  /*< private >*/
  HarObject parent_instance;
  HarEntryPrivate * priv;
  /*< public >*/

  GDateTime * started;
  HarRequest * request;
  HarResponse * response;
  HarCache * cache;
  HarTimings * timings;
  HarTimings * timeouts;
};

struct _HarEntryClass
{
  /*< private >*/
  HarObjectClass parent_class;
};

enum _HarEntryProperties {
  HAR_ENTRY_DUMMY_PROPERTY,

  /* HarObject */
  HAR_ENTRY_COMMENT,

  /* HarEntry */
  HAR_ENTRY_STARTED,
  HAR_ENTRY_TIME,
  HAR_ENTRY_REQUEST,
  HAR_ENTRY_RESPONSE,
  HAR_ENTRY_CACHE,
  HAR_ENTRY_SERVER_IP_ADDRESS,
  HAR_ENTRY_SERVER_PORT,
  HAR_ENTRY_CLIENT_IP_ADDRESS,
  HAR_ENTRY_CLIENT_PORT,
  HAR_ENTRY_CONNECTION,
  HAR_ENTRY_TIMINGS,
  HAR_ENTRY_TIMEOUTS,

  HAR_ENTRY_N_PROPERTIES
};

/*
 * Method definitions.
 */

/**
 * har_entry_get_type:
 *
 * Returns: (type GType): the #HarEntry #GType.
 */
GType har_entry_get_type (void) G_GNUC_CONST;

/**
 * har_entry_new:
 *
 * Returns: (transfer full): a #HarEntry.
 */
HarEntry * har_entry_new (void);

/**
 * har_entry_get_comment:
 * @self: a #HarEntry.
 *
 * Returns: (type utf8) (transfer none): a string.
 */
const gchar * har_entry_get_comment (HarEntry * self);

/**
 * har_entry_set_comment:
 * @self: a #HarEntry.
 * @value: a string.
 *
 */
void har_entry_set_comment (HarEntry * self, const gchar * value);

/**
 * har_entry_get_started:
 * @self: a #HarEntry.
 *
 * Returns: (transfer none): a #GDateTime.
 */
GDateTime * har_entry_get_started (HarEntry * self);

/**
 * har_entry_set_started:
 * @self: a #HarEntry.
 * @value: a #GDateTime.
 */
void har_entry_set_started (HarEntry * self, GDateTime * value);

/**
 * har_entry_get_time:
 * @self: a #HarEntry.
 *
 * Returns: (transfer none): a #gdouble.
 */
gdouble har_entry_get_time (HarEntry * self);

/**
 * har_entry_set_time:
 * @self: a #HarEntry.
 * @value: a double.
 */
void har_entry_set_time (HarEntry * self, gdouble value);

/**
 * har_entry_get_request:
 * @self: a #HarEntry.
 *
 * Returns: (transfer none): a #HarRequest.
 */
HarRequest * har_entry_get_request (HarEntry * self);

/**
 * har_entry_set_request:
 * @self: a #HarEntry.
 * @value: (transfer full): a #HarRequest.
 */
void har_entry_set_request (HarEntry * self, HarRequest * value);

/**
 * har_entry_get_response:
 *
 * Returns: (transfer none): a #HarRequest.
 */
HarResponse * har_entry_get_response (HarEntry * self);

/**
 * har_entry_set_response:
 * @self: a #HarEntry.
 * @value: (transfer full): a #HarResponse.
 */
void har_entry_set_response (HarEntry * self, HarResponse * value);

/**
 * har_entry_get_cache:
 *
 * Returns: (transfer none): a #HarCache.
 */
HarCache * har_entry_get_cache (HarEntry * self);

/**
 * har_entry_set_cache:
 * @self: a #HarEntry.
 * @value: (transfer full): a #HarCache.
 */
void har_entry_set_cache (HarEntry * self, HarCache * value);

/**
 * har_entry_get_server_ip_address:
 *
 * Returns: (transfer none): a string.
 */
const gchar * har_entry_get_server_ip_address (HarEntry * self);

/**
 * har_entry_set_server_ip_address:
 * @self: a #HarEntry.
 * @value: (transfer full): a string.
 */
void har_entry_set_server_ip_address (HarEntry * self, const gchar * value);

/**
 * har_entry_get_server_port:
 *
 * Returns: (transfer none): a number.
 */
guint har_entry_get_server_port (HarEntry * self);

/**
 * har_entry_set_server_port:
 * @self: a #HarEntry.
 * @value: (transfer full): a number.
 */
void har_entry_set_server_port (HarEntry * self, guint value);

/**
 * har_entry_get_client_ip_address:
 *
 * Returns: (transfer none): a string.
 */
const gchar * har_entry_get_client_ip_address (HarEntry * self);

/**
 * har_entry_set_client_ip_address:
 * @self: a #HarEntry.
 * @value: (transfer full): a string.
 */
void har_entry_set_client_ip_address (HarEntry * self, const gchar * value);

/**
 * har_entry_get_client_port:
 *
 * Returns: (transfer none): a number.
 */
guint har_entry_get_client_port (HarEntry * self);

/**
 * har_entry_set_client_port:
 * @self: a #HarEntry.
 * @value: (transfer full): a number.
 */
void har_entry_set_client_port (HarEntry * self, guint value);

/**
 * har_entry_get_connection:
 *
 * Returns: (transfer none): a string.
 */
const gchar * har_entry_get_connection (HarEntry * self);

/**
 * har_entry_set_connection:
 * @self: a #HarEntry.
 * @value: (transfer full): a string.
 */
void har_entry_set_connection (HarEntry * self, const gchar * value);

/**
 * har_entry_get_timings:
 *
 * Returns: (transfer none): a #HarTimings.
 */
HarTimings * har_entry_get_timings (HarEntry * self);

/**
 * har_entry_set_timings:
 * @self: a #HarEntry.
 * @value: (transfer full): a #HarTimings.
 */
void har_entry_set_timings (HarEntry * self, HarTimings * value);

/**
 * har_entry_get_timeouts:
 *
 * Returns: (transfer none): a #HarTimings.
 */
HarTimings * har_entry_get_timeouts (HarEntry * self);

/**
 * har_entry_set_timeouts:
 * @self: a #HarEntry.
 * @value: (transfer full): a #HarTimings.
 */
void har_entry_set_timeouts (HarEntry * self, HarTimings * value);

G_END_DECLS

#endif

