/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-response-curl.h"


void har_response_transform_from_curl_easy (
    HarResponse * self, const CURL * hnd)
{
}


void har_response_transform_to_curl_easy (
    const HarResponse * self, CURL * hnd)
{
}

/*
static void _value_transform_soup_message_har_response (const GValue *src_value, GValue *dest_value)
{
}
static void _value_transform_har_response_soup_message (const GValue *src_value, GValue *dest_value)
{
}
static void _value_transform_curl_easy_har_response (const GValue *src_value, GValue *dest_value)
{
}
static void _value_transform_har_response_curl_easy (const GValue *src_value, GValue *dest_value)
{
    HarResponse * har_response;
    CurlEasy * curl_easy;

    g_return_if_fail (src_value != NULL);
    g_return_if_fail (dest_value != NULL);
    g_return_if_fail (G_IS_VALUE (src_value));
    g_return_if_fail (G_IS_VALUE (dest_value));
    g_return_if_fail (G_VALUE_HOLDS (src_value, HAR_TYPE_RESPONSE));
    g_return_if_fail (G_VALUE_HOLDS (dest_value, CURL_TYPE_EASY));

    har_response = HAR_RESPONSE (g_value_peek_pointer (src_value));
    curl_easy = CURL_EASY (g_value_peek_pointer (dest_value));
    
}
*/
