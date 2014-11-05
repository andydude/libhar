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
#include <curl/easy.h>

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

//typedef CURL CurlEasy;
//typedef CURLM CurlMulti;
//

typedef CURL CurlEasy;

//struct _CurlEasy
//{
//  GValue parent_value;
//};

/*
 * Method definitions.
 */

/**
 * curl_easy_get_type:
 */
GType curl_easy_get_type (void);

/**
 * curl_easy_new:
 */
GValue * curl_easy_new (void);

G_END_DECLS

#endif
