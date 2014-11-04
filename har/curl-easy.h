/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libcurl - Library of HTTP Archive (CURL) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __CURL_EASY_H__
#define __CURL_EASY_H__

#include <glib.h>
#include <glib-object.h>
#include <curl/curl.h>
#include "curl-easy.h"

/*
 * Type macros.
 */

#define CURL_TYPE_EASY             (curl_easy_get_type())
#define CURL_EASY(obj)             G_TYPE_CHECK_INSTANCE_CAST((obj), CURL_TYPE_EASY, CurlEasy)
#define CURL_EASY_CLASS(klass)     G_TYPE_CHECK_CLASS_CAST((klass),  CURL_TYPE_EASY, CurlEasyClass)
#define CURL_IS_EASY(obj)          G_TYPE_CHECK_INSTANCE_TYPE((obj), CURL_TYPE_EASY)
#define CURL_IS_EASY_CLASS(klass)  G_TYPE_CHECK_CLASS_TYPE((klass),  CURL_TYPE_EASY)
#define CURL_EASY_GET_CLASS(obj)   G_TYPE_INSTANCE_GET_CLASS((obj),  CURL_TYPE_EASY, CurlEasyClass)

G_BEGIN_DECLS

/*
 * Forward declarations.
 */

typedef struct _CurlEasy CurlEasy;
typedef struct _CurlEasyClass CurlEasyClass;

struct _CurlEasy
{
  GObject parent_instance;
  CURL * handle;
};

struct _CurlEasyClass
{
  GObjectClass parent_class;
};

enum _CurlEasyProperties {
	CURL_EASY_DUMMY_PROPERTY,
    CURL_EASY_N_PROPERTIES
};

/*
 * Method definitions.
 */

CurlEasy * curl_easy_new (void);

G_END_DECLS

#endif
