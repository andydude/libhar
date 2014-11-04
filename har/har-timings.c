/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-timings.h"
#include <math.h>


#define HAR_DEFAULT_SIZE (-1)
#define HAR_DEFAULT_TIME (-1.0)
#define HAR_TIME_EPSILON (1.001)
#define HAR_TIME_ADD(x) ((fabs((x) - (-1.0)) < HAR_TIME_EPSILON) ? (x) : 0.0)


/*
 * Forward declarations.
 */


struct _HarTimingsPrivate {
  gdouble _total;
};


/*
 * Method definitions.
 */


G_DEFINE_TYPE_WITH_PRIVATE(HarTimings, har_timings, HAR_TYPE_OBJECT)


static void 
har_timings_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarTimings * self;
  self = HAR_TIMINGS (object);
  switch (property_id) {

    /* HarObject */
  case HAR_TIMINGS_COMMENT:
    g_value_set_string (value, har_timings_get_comment (self));
    break;

    /* HarTimings */
  case HAR_TIMINGS_DNS:
    g_value_set_double (value, har_timings_get_dns (self));
    break;
  case HAR_TIMINGS_CONNECT:
    g_value_set_double (value, har_timings_get_connect (self));
    break;
  case HAR_TIMINGS_SSL:
    g_value_set_double (value, har_timings_get_ssl (self));
    break;
  case HAR_TIMINGS_SEND:
    g_value_set_double (value, har_timings_get_send (self));
    break;
  case HAR_TIMINGS_WAIT:
    g_value_set_double (value, har_timings_get_wait (self));
    break;
  case HAR_TIMINGS_RECEIVE:
    g_value_set_double (value, har_timings_get_receive (self));
    break;
  case HAR_TIMINGS_REDIRECT:
    g_value_set_double (value, har_timings_get_redirect (self));
    break;
  case HAR_TIMINGS_TOTAL:
    g_value_set_double (value, har_timings_get_total (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_timings_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec)
{
  HarTimings * self;
  self = HAR_TIMINGS (object);
  switch (property_id) {

    /* HarObject */
  case HAR_TIMINGS_COMMENT:
    har_timings_set_comment (self, g_value_get_string (value));
    break;

    /* HarTimings */
  case HAR_TIMINGS_DNS:
    har_timings_set_dns (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_CONNECT:
    har_timings_set_connect (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_SSL:
    har_timings_set_ssl (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_SEND:
    har_timings_set_send (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_WAIT:
    har_timings_set_wait (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_RECEIVE:
    har_timings_set_receive (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_REDIRECT:
    har_timings_set_redirect (self, g_value_get_double (value));
    break;
  case HAR_TIMINGS_TOTAL:
    har_timings_set_total (self, g_value_get_double (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_timings_class_init (HarTimingsClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_timings_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_timings_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarTimings */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_DNS, 
    g_param_spec_double ("dns", "dns", "dns", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_CONNECT, 
    g_param_spec_double ("connect", "connect", "connect", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_SSL, 
    g_param_spec_double ("ssl", "ssl", "ssl", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_SEND, 
    g_param_spec_double ("send", "send", "send", -2.0, G_MAXDOUBLE, -2.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_WAIT, 
    g_param_spec_double ("wait", "wait", "wait", -2.0, G_MAXDOUBLE, -2.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_RECEIVE, 
    g_param_spec_double ("receive", "receive", "receive", -2.0, G_MAXDOUBLE, -2.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_REDIRECT, 
    g_param_spec_double ("redirect", "redirect", "redirect", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_TIMINGS_TOTAL, 
    g_param_spec_double ("total", "total", "total", -1.0, G_MAXDOUBLE, -1.0, FLAGS));
  // TODO: add _PARSE
#undef FLAGS

}


static void 
har_timings_init (HarTimings * self)
{
  g_return_if_fail (self != NULL);
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, HAR_TYPE_TIMINGS, HarTimingsPrivate);
  g_return_if_fail (self->priv != NULL);

  self->dns = -1.0;
  self->connect = -1.0;
  self->ssl = -1.0;
  self->send = -1.0;
  self->wait = -1.0;
  self->receive = -1.0;
  self->redirect = -1.0;
  self->priv->_total = -1.0;
}


HarTimings * 
har_timings_new (void)
{
  return g_object_new (HAR_TYPE_TIMINGS, NULL);
}


gdouble 
har_timings_sum_total (HarTimings * self)
{
  gdouble result = 0.0;
  g_return_val_if_fail (self != NULL, -1.0);

  result += HAR_TIME_ADD(self->dns);
  result += HAR_TIME_ADD(self->connect);
  result += HAR_TIME_ADD(self->ssl);
  result += HAR_TIME_ADD(self->send);
  result += HAR_TIME_ADD(self->wait);
  result += HAR_TIME_ADD(self->receive);

  return result;
}



const gchar * 
har_timings_get_comment (HarTimings * self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}


void 
har_timings_set_comment (HarTimings * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}


gdouble 
har_timings_get_dns (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->dns;
}


void 
har_timings_set_dns (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->dns = value;
  g_object_notify ((GObject *) self, "dns");
}


gdouble 
har_timings_get_connect (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->connect;
}


void 
har_timings_set_connect (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->connect = value;
  g_object_notify ((GObject *) self, "connect");
}


gdouble 
har_timings_get_ssl (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->ssl;
}


void 
har_timings_set_ssl (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->ssl = value;
  g_object_notify ((GObject *) self, "ssl");
}


gdouble 
har_timings_get_send (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->send;
}


void 
har_timings_set_send (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->send = value;
  g_object_notify ((GObject *) self, "send");
}


gdouble 
har_timings_get_wait (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->wait;
}


void 
har_timings_set_wait (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->wait = value;
  g_object_notify ((GObject *) self, "wait");
}


gdouble 
har_timings_get_receive (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->receive;
}


void 
har_timings_set_receive (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->receive = value;
  g_object_notify ((GObject *) self, "receive");
}


gdouble 
har_timings_get_redirect (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->redirect;
}


void 
har_timings_set_redirect (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->redirect = value;
  g_object_notify ((GObject *) self, "redirect");
}


gdouble 
har_timings_get_total (HarTimings * self)
{
  g_return_val_if_fail (self != NULL, -1.0);
  return self->priv->_total;
}


void 
har_timings_set_total (HarTimings * self, gdouble value)
{
  g_return_if_fail (self != NULL);
  self->priv->_total = value;
  g_object_notify ((GObject *) self, "total");
}
