/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "curl-easy.h"


/*
 * Forward declarations.
 */

/*
 * Method definitions.
 */


G_DEFINE_BOXED_TYPE(CurlEasy, curl_easy, curl_easy_duphandle, curl_easy_cleanup) 

GValue * curl_easy_new (void)
{
    GValue * result = g_new0 (GValue, 1);
    g_value_init(result, CURL_TYPE_EASY);
    return result;
}
