/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */

#ifndef __HAR_MESSAGE_UTILS_H__
#define __HAR_MESSAGE_UTILS_H__

#include <glib.h>
#include <gmodule.h>
#include <json-glib/json-glib.h>

void har_init (void);

guint har_parse_http_version_string(const gchar * version, gsize version_length);

const gchar * har_render_http_version_string(guint version_number);

//JsonNode *
//har_slist_serialize(GSList * boxed);
//
//GSList * 
//har_slist_deserialize(JsonNode *node);

#endif
