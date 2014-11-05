/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#include "har-response.h"
#include "gslist.h"

/*
 * Forward declarations.
 */

static void har_response_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec);


static void har_response_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec);

/*
 * Method definitions.
 */


G_DEFINE_TYPE_WITH_PRIVATE(HarResponse, har_response, HAR_TYPE_MESSAGE)



static void 
har_response_get_property (
    GObject * object, 
    guint property_id, 
    GValue * value, 
    GParamSpec * pspec) 
{
  HarResponse * self = HAR_RESPONSE (object);
  switch (property_id) {

    /* HarObject */
  case HAR_RESPONSE_COMMENT:
    g_value_set_string (value, har_response_get_comment (self));
    break;

    /* HarMessage */
  case HAR_RESPONSE_VERSION:
    g_value_set_int (value, har_response_get_version (self));
    break;
  case HAR_RESPONSE_COOKIES:
    g_value_set_boxed (value, har_response_get_cookies (self));
    break;
  case HAR_RESPONSE_HEADERS:
    g_value_set_boxed (value, har_response_get_headers (self));
    break;
  case HAR_RESPONSE_BODY:
    g_value_set_object (value, har_response_get_body (self));
    break;
  case HAR_RESPONSE_HEADERS_SIZE:
    g_value_set_int (value, har_response_get_headers_size (self));
    break;
  case HAR_RESPONSE_BODY_SIZE:
    g_value_set_int (value, har_response_get_body_size (self));
    break;
  case HAR_RESPONSE_HTTP_VERSION:
    g_value_set_string (value, har_response_get_http_version (self));
    break;
  //case HAR_RESPONSE_HTTP_HEADERS:
  //  g_value_set_object (value, har_response_get_http_headers (self));
  //  break;

    /* HarResponse */
  case HAR_RESPONSE_STATUS:
    g_value_set_uint (value, har_response_get_status (self));
    break;
  case HAR_RESPONSE_REASON:
    g_value_set_string (value, har_response_get_reason (self));
    break;
  case HAR_RESPONSE_REDIRECT_URL:
    g_value_set_string (value, har_response_get_redirect_url (self));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_response_set_property (
    GObject * object, 
    guint property_id, 
    const GValue * value, 
    GParamSpec * pspec) 
{
  HarResponse * self = G_TYPE_CHECK_INSTANCE_CAST (object, HAR_TYPE_RESPONSE, HarResponse);
  switch (property_id) {

    /* HarObject */
  case HAR_RESPONSE_COMMENT:
    har_response_set_comment (self, g_value_get_string (value));
    break;

    /* HarMessage */
  case HAR_RESPONSE_VERSION:
    har_response_set_version (self, g_value_get_int (value));
    break;
  case HAR_RESPONSE_COOKIES:
    har_response_set_cookies (self, g_value_get_boxed (value));
    break;
  case HAR_RESPONSE_HEADERS:
    har_response_set_headers (self, g_value_get_boxed (value));
    break;
  case HAR_RESPONSE_BODY:
    har_response_set_body (self, g_value_get_object (value));
    break;
  case HAR_RESPONSE_HEADERS_SIZE:
    har_response_set_headers_size (self, g_value_get_int (value));
    break;
  case HAR_RESPONSE_BODY_SIZE:
    har_response_set_body_size (self, g_value_get_int (value));
    break;
  case HAR_RESPONSE_HTTP_VERSION:
    har_response_set_http_version (self, g_value_get_string (value));
    break;
  //case HAR_RESPONSE_HTTP_HEADERS:
  //  har_response_set_http_headers (self, g_value_get_object (value));
  //  break;

    /* HarResponse */
  case HAR_RESPONSE_STATUS:
    har_response_set_status (self, g_value_get_uint (value));
    break;
  case HAR_RESPONSE_REASON:
    har_response_set_reason (self, g_value_get_string (value));
    break;
  case HAR_RESPONSE_REDIRECT_URL:
    har_response_set_redirect_url (self, g_value_get_string (value));
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}


static void 
har_response_class_init (HarResponseClass * klass)
{
  G_OBJECT_CLASS (klass)->get_property = (GObjectGetPropertyFunc) &har_response_get_property;
  G_OBJECT_CLASS (klass)->set_property = (GObjectSetPropertyFunc) &har_response_set_property;
  
#define FLAGS (G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE)

  /* HarObject */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_COMMENT, 
    g_param_spec_string ("comment", "comment", "comment", NULL, FLAGS));

  /* HarMessage */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_VERSION,
    g_param_spec_uint ("httpVersionNumber", "http-version-number", "HTTP version number.", 
                       9,  /* HTTP/0.9 minimum */
                       20, /* HTTP/2.0 maximum */
                       11, /* HTTP/1.1 default */
                       FLAGS));

  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_COOKIES, 
    g_param_spec_boxed ("cookies", "cookies", "Cookies.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_HEADERS, 
    g_param_spec_boxed ("headers", "headers", "Headers.", G_TYPE_SLIST, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_HEADERS_SIZE, 
    g_param_spec_int ("headersSize", "headers-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_BODY_SIZE, 
    g_param_spec_int ("bodySize", "body-size", "TODO.", -1, G_MAXINT, -1, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_HTTP_VERSION,
    g_param_spec_string ("httpVersion", "http-version", "TODO.", NULL, FLAGS));
  //g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_HTTP_HEADERS,
  //  g_param_spec_object ("httpHeaders", "http-headers", "TODO.", NULL, FLAGS));

  /* HarResponse */
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_BODY, 
    g_param_spec_object ("content", "response body", "TODO.", HAR_TYPE_RESPONSE_BODY, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_STATUS, 
    g_param_spec_uint ("status", "status-code", "TODO.", 0, G_MAXUINT, 0, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_REASON, 
    g_param_spec_string ("statusText", "reason-phrase", "TODO.", NULL, FLAGS));
  g_object_class_install_property (G_OBJECT_CLASS (klass), HAR_RESPONSE_REDIRECT_URL, 
    g_param_spec_string ("redirectURL", "redirect-url", "TODO.", NULL, FLAGS));

#undef FLAGS

}


static void 
har_response_init (HarResponse * self)
{
  g_return_if_fail (self != NULL);
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, HAR_TYPE_RESPONSE, HarResponsePrivate);
  g_return_if_fail (self->priv != NULL);

  self->body = har_response_body_new ();
  self->priv->_redirect_url = "";
  self->priv->_reason = "";
  self->status = 0;
}


HarResponse * 
har_response_new (void) {
  return g_object_new (HAR_TYPE_RESPONSE, NULL);
}


const gchar * har_response_get_comment (HarResponse* self)
{
  return har_object_get_comment (HAR_OBJECT (self));
}

void har_response_set_comment (HarResponse * self, const gchar * value)
{
  har_object_set_comment (HAR_OBJECT (self), value);
}

guint har_response_get_version (HarResponse* self)
{
  return har_message_get_version (HAR_MESSAGE (self));
}

void har_response_set_version (HarResponse * self, guint value)
{
  har_message_set_version (HAR_MESSAGE (self), value);
}

GSList * har_response_get_cookies (HarResponse* self)
{
    return har_message_get_cookies (HAR_MESSAGE (self));
}

void har_response_set_cookies (HarResponse * self, GSList * value)
{
    har_message_set_cookies (HAR_MESSAGE (self), value);
}

GSList * har_response_get_headers (HarResponse* self)
{
    return har_message_get_headers (HAR_MESSAGE (self));
}

void har_response_set_headers (HarResponse * self, GSList * value)
{
    har_message_set_headers (HAR_MESSAGE (self), value);
}

HarResponseBody * har_response_get_body (HarResponse* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->body;
}

void har_response_set_body (HarResponse * self, HarResponseBody * value)
{
  g_return_if_fail (self != NULL);
  self->body = value;
  g_object_notify ((GObject *) self, "content");
}

gint har_response_get_headers_size (HarResponse* self)
{
    return har_message_get_headers_size (HAR_MESSAGE (self));
}

void har_response_set_headers_size (HarResponse * self, gint value)
{
    har_message_set_headers_size (HAR_MESSAGE (self), value);
}

gint har_response_get_body_size (HarResponse* self)
{
    return har_message_get_body_size (HAR_MESSAGE (self));
}

void har_response_set_body_size (HarResponse * self, gint value)
{
    har_message_set_body_size (HAR_MESSAGE (self), value);
}


const gchar * har_response_get_http_version (HarResponse * self)
{
  return har_message_get_http_version (HAR_MESSAGE (self));
}

void har_response_set_http_version (HarResponse * self, const gchar * value)
{
  har_message_set_http_version (HAR_MESSAGE (self), value);
}

//HarHeaders * har_response_get_http_headers (HarResponse * self)
//{
//  return har_message_get_http_headers (HAR_MESSAGE (self));
//}
//
//void har_response_set_http_headers (HarResponse * self, HarHeaders * value)
//{
//  har_message_set_http_headers (HAR_MESSAGE (self), value);
//}



guint har_response_get_status (HarResponse* self)
{
  g_return_val_if_fail (self != NULL, 0);
  return self->status;
}

void har_response_set_status (HarResponse * self, guint value)
{
  g_return_if_fail (self != NULL);
  self->status = value;
  g_object_notify ((GObject *) self, "status");
}

const gchar * har_response_get_reason (HarResponse* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_reason;
}

void har_response_set_reason (HarResponse * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_reason = g_strdup (value);
  g_object_notify ((GObject *) self, "statusText");
}

const gchar * har_response_get_redirect_url (HarResponse* self)
{
  g_return_val_if_fail (self != NULL, NULL);
  return self->priv->_redirect_url;
}

void har_response_set_redirect_url (HarResponse * self, const gchar * value)
{
  g_return_if_fail (self != NULL);
  self->priv->_redirect_url = g_strdup (value);
  g_object_notify ((GObject *) self, "redirectURL");
}





