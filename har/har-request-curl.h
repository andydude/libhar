/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include <curl/curl.h>

#include "curl-easy.h"
#include "har-request.h"

/**
 * har_request_transform_from_curl_easy:
 */
void har_request_transform_from_curl_easy(HarRequest * self, const CURL * hnd);

/**
 * har_request_transform_to_curl_easy:
 */
void har_request_transform_to_curl_easy(const HarRequest * self, CURL * hnd);
