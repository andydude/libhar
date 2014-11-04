/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#include "har-entry.h"

/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_TYPE_WITH_PRIVATE(HarEntry, har_entry, HAR_TYPE_OBJECT)


static void 
har_entry_get_property (
                        GObject * object, 
                        guint property_id, 
                        GValue * value, 
                        GParamSpec * pspec) 
{
  HarEntry * self = G_TYPE_CHECK_INSTANCE_CAST (object, HAR_TYPE_ENTRY, HarEntry);
  switch (property_id) {

    /* HarObject */
  case HAR_ENTRY_COMMENT:
    g_value_set_string (value, har_entry_get_comment (self));
    break;

    /* HarEntry */
  case HAR_ENTRY_STARTED:
    g_value_set_boxed (value, har_entry_get_started (self));
    break;
  case HAR_ENTRY_TIME:
    g_value_set_double (value, har_entry_get_time (self));
    break;
  case HAR_ENTRY_REQUEST:
    g_value_set_object (value, har_entry_get_request (self));
    break;
  case HAR_ENTRY_RESPONSE:
    g_value_set_object (value, har_entry_get_response (self));
    break;
  case HAR_ENTRY_CACHE:
    g_value_set_object (value, har_entry_get_cache (self));
    break;
  case HAR_ENTRY_TIMINGS:
    g_value_set_object (value, har_entry_get_timings (self));
    break;
  case HAR_ENTRY_TIMEOUTS:
    g_value_set_object (value, har_entry_get_timeouts (self));
    break;
  case HAR_ENTRY_SERVER_IP_ADDRESS:
    g_value_set_string (value, har_entry_get_server_ip_address (self));
    break;
  case HAR_ENTRY_SERVER_PORT:
    g_value_set_int (value, har_entry_get_server_port (self));
    break;
  case HAR_ENTRY_CLIENT_IP_ADDRESS:
    g_value_set_string (value, har_entry_get_client_ip_address (self));
    break;
  case HAR_ENTRY_CLIENT_PORT:
    g_value_set_int (value, har_entry_get_client_port (self));
    break;
  case HAR_ENTRY_CONNECTION:
    g_value_set_string (value, har_entry_get_connection (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_entry_set_property (
                        GObject * object, 
                        guint property_id, 
                        const GValue * value, 
                        GParamSpec * pspec) 
{
  HarEntry * self = G_TYPE_CHECK_INSTANCE_CAST (object, HAR_TYPE_ENTRY, HarEntry);
  switch (property_id) {

    /* HarObject */
  case HAR_OBJECT_COMMENT:
    har_entry_set_comment (self, g_value_get_string (value));
    break;

    /* HarEntry */
  case HAR_ENTRY_STARTED:
    har_entry_set_started (self, g_value_get_boxed (value));
    break;
  case HAR_ENTRY_TIME:
    har_entry_set_time (self, g_value_get_double (value));
    break;
  case HAR_ENTRY_REQUEST:
    har_entry_set_request (self, g_value_get_object (value));
    break;
  case HAR_ENTRY_RESPONSE:
    har_entry_set_response (self, g_value_get_object (value));
    break;
  case HAR_ENTRY_CACHE:
    har_entry_set_cache (self, g_value_get_object (value));
    break;
  case HAR_ENTRY_TIMINGS:
    har_entry_set_timings (self, g_value_get_object (value));
    break;
  case HAR_ENTRY_TIMEOUTS:
    har_entry_set_timeouts (self, g_value_get_object (value));
    break;
  case HAR_ENTRY_SERVER_IP_ADDRESS:
    har_entry_set_server_ip_address (self, g_value_get_string (value));
    break;
  case HAR_ENTRY_CLIENT_IP_ADDRESS:
    har_entry_set_client_ip_address (self, g_value_get_string (value));
    break;
  case HAR_ENTRY_SERVER_PORT:
    har_entry_set_server_port (self, g_value_get_int (value));
    break;
  case HAR_ENTRY_CLIENT_PORT:
    har_entry_set_client_port (self, g_value_get_int (value));
    break;
  case HAR_ENTRY_CONNECTION:
    har_entry_set_connection (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_entry_finalize (GObject * object) {
  HarEntry * self = HAR_ENTRY (object);
  if (self->started)
    g_date_time_unref (self->started);
  if (self->request)
    g_object_unref (self->request);
  if (self->response)
    g_object_unref (self->response);
  if (self->cache)
    g_object_unref (self->cache);
  if (self->timings)
    g_object_unref (self->timings);
  if (self->timeouts)
    g_object_unref (self->timeouts);
  G_OBJECT_CLASS (har_entry_parent_class)->finalize (object);
}


static void 
har_entry_class_init (HarEntryClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_entry_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_entry_set_property;
  G_OBJECT_CLASS (klass)->finalize = (GObjectFinalizeFunc) &har_entry_finalize;

#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarEntry */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_STARTED, 
    g_param_spec_boxed ("started", "started", "Date/time of the start of the request.", G_TYPE_DATE_TIME, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_TIME, 
    g_param_spec_double ("time", "time", "Total elapsed time of the request in milliseconds.", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_REQUEST, 
    g_param_spec_object ("request", "request", "request", HAR_TYPE_REQUEST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_RESPONSE, 
    g_param_spec_object ("response", "response", "response", HAR_TYPE_RESPONSE, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_CACHE, 
    g_param_spec_object ("cache", "cache", "cache", HAR_TYPE_CACHE, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_SERVER_IP_ADDRESS, 
    g_param_spec_string ("server-ip-address", "serverIPAddress", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_SERVER_PORT, 
    g_param_spec_uint ("server-port", "serverPort", "TODO.", 0, G_MAXUINT, 0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_CLIENT_IP_ADDRESS, 
    g_param_spec_string ("client-ip-address", "clientIPAddress", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_CLIENT_PORT, 
    g_param_spec_uint ("client-port", "clientPort", "TODO.", 0, G_MAXUINT, 0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_CONNECTION, 
    g_param_spec_string ("connection", "connection", "Connection information, may be a pointer or ID.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_TIMINGS, 
    g_param_spec_object ("timings", "timings", "TODO.", HAR_TYPE_TIMINGS, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_ENTRY_TIMEOUTS, 
    g_param_spec_object ("timeouts", "timeouts", "TODO.", HAR_TYPE_TIMINGS, FLAGS));
  // TODO: add _PARSE
#undef FLAGS

}


static void 
har_entry_init (HarEntry * self) 
{
  g_return_if_fail (self != NULL);
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, HAR_TYPE_ENTRY, HarEntryPrivate);
  g_return_if_fail (self->priv != NULL);

  self->priv->_time = -1.0;
  self->started = NULL;
  self->request = har_request_new ();
  self->response = har_response_new ();
  self->cache = har_cache_new ();
  self->timings = har_timings_new ();
  self->timeouts = har_timings_new ();
}


HarEntry * 
har_entry_new (void)
{
  return g_object_new (HAR_TYPE_ENTRY, NULL);
}


const gchar * 
har_entry_get_comment (HarEntry * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_entry_set_comment (HarEntry * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


GDateTime * har_entry_get_started (HarEntry * self) {
  g_return_val_if_fail (self != NULL, NULL);
  return self->started;
}


void har_entry_set_started (HarEntry * self, GDateTime * value) {
  g_return_if_fail (self != NULL);
  if (self->started)
    g_date_time_unref (self->started);
  if (value)
    value = g_date_time_ref(value);
  self->started = value;
  g_object_notify ((GObject *) self, "started");
}


gdouble har_entry_get_time (HarEntry * self) {
  g_return_val_if_fail (self != NULL, 0.0);
  return self->priv->_time;
}


void har_entry_set_time (HarEntry * self, gdouble value) {
  g_return_if_fail (self != NULL);
  self->priv->_time = value;
  g_object_notify ((GObject *) self, "time");
}


HarRequest * har_entry_get_request (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->request;
}
void har_entry_set_request (HarEntry * self, HarRequest * value)
{
  g_return_if_fail (self != NULL);
  self->request = value;
  g_object_notify ((GObject *) self, "request");
}


HarResponse * har_entry_get_response (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->response;
}
void har_entry_set_response (HarEntry * self, HarResponse * value)
{
  g_return_if_fail (self != NULL);
  self->response = value;
  g_object_notify ((GObject *) self, "response");
}


HarCache * har_entry_get_cache (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->cache;
}
void har_entry_set_cache (HarEntry * self, HarCache * value)
{
  g_return_if_fail (self != NULL);
  self->cache = value;
  g_object_notify ((GObject *) self, "cache");
}

const gchar * har_entry_get_server_ip_address (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_server_ip_address;
}


void har_entry_set_server_ip_address (HarEntry * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_server_ip_address = value;
  g_object_notify ((GObject *) self, "request");
}


guint har_entry_get_server_port (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, 0);
  return self->priv->_server_port;
}


void har_entry_set_server_port (HarEntry * self, guint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_server_port = value;
  g_object_notify ((GObject *) self, "request");
}


const gchar * har_entry_get_client_ip_address (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_client_ip_address;
}


void har_entry_set_client_ip_address (HarEntry * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_client_ip_address = value;
  g_object_notify ((GObject *) self, "request");
}


guint har_entry_get_client_port (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, 0);
  return self->priv->_client_port;
}


void har_entry_set_client_port (HarEntry * self, guint value)
{
  g_return_if_fail (self != NULL);
  self->priv->_client_port = value;
  g_object_notify ((GObject *) self, "request");
}


const gchar * har_entry_get_connection (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_connection;
}


void har_entry_set_connection (HarEntry * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_connection = value;
  g_object_notify ((GObject *) self, "request");
}


HarTimings * har_entry_get_timings (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->timings;
}


void har_entry_set_timings (HarEntry * self, HarTimings * value)
{
  g_return_if_fail (self != NULL);
  self->timings = value;
  g_object_notify ((GObject *) self, "request");
}


HarTimings * har_entry_get_timeouts (HarEntry * self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->timeouts;
}


void har_entry_set_timeouts (HarEntry * self, HarTimings * value)
{
  g_return_if_fail (self != NULL);
  self->timeouts = value;
  g_object_notify ((GObject *) self, "request");
}


//
//static GParamSpec * har_entry_properties[HAR_ENTRY_N_PROPERTIES] = {
//  NULL, 
//
//  /* HAR_ENTRY_STARTED */
//  g_param_spec_boxed (
//                      "started", "startedDateTime", "", 
//                      G_TYPE_DATE_TIME, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                      G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_TIME */
//  g_param_spec_double (
//                       "time", "time", "", 
//                       -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_REQUEST */
//  g_param_spec_object (
//                       "request", "request", "Request information.", 
//                       HAR_TYPE_REQUEST, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_RESPONSE */
//  g_param_spec_object (
//                       "response", "response", "Response information.", 
//                       HAR_TYPE_RESPONSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_CACHE */
//  g_param_spec_object (
//                       "cache", "cache", "Cache information.", 
//                       HAR_TYPE_CACHE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_ENTRY */
//  g_param_spec_object (
//                       "entry", "entry", "Collection of timing information.", 
//                       HAR_TYPE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_TIMEOUTS */
//  g_param_spec_object (
//                       "timeouts", "timeouts", "Collection of timeouts, the maximums for entry.", 
//                       HAR_TYPE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_SERVER_IP_ADDRESS */
//  g_param_spec_string (
//                       "server-ip-address", "serverIPAddress", "IP address of the server.", 
//                       NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_CLIENT_IP_ADDRESS */
//  g_param_spec_string (
//                       "client-ip-address", "clientIPAddress", "IP address of the client.", 
//                       NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_SERVER_PORT */
//  g_param_spec_int (
//                    "server-port", "serverPort", "Port number of the socket on the server.", 
//                    G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                    G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_CLIENT_PORT */
//  g_param_spec_int (
//                    "client-port", "clientPort", "Port number of the socket on the client.", 
//                    G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                    G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//  /* HAR_ENTRY_CONNECTION */
//  g_param_spec_string (
//                       "connection", "connection", "", 
//                       NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | 
//                       G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE),
//
//};
//




