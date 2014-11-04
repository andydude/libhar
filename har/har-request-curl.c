/* -*- mode: c; c-basic-offset: 2; tab-width: 80; -*- */
/* libhar - Library of HTTP Archive (HAR) classes
 * Copyright (C) 2014-2015  Andrew Robbins
 *
 * This library ("it") is free software; it is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License ("LGPLv3") <https://www.gnu.org/licenses/lgpl.html>.
 */
#include "har-request-curl.h"
#include "har-message-utils.h"

#include <string.h>

void har_request_transform_from_curl_easy (
    HarRequest * self, const CURL * hnd)
{
}

void har_request_transform_to_curl_easy (
    const HarRequest * self_q, CURL * hnd)
{
    HarRequest * self = HAR_REQUEST (self_q);

    //curl_easy_setopt(curl_easy->handle, CURLOPT_VERBOSE, 
    //                 har_client_options_get_verbose(har_clnt_opts));

    //curl_easy_setopt(curl_easy->handle, CURLOPT_HEADER, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_NOPROGRESS, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_NOSIGNAL, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_WILDCARDMATCH, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_WRITEFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_WRITEDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_READFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_READDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_IOCTLFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_IOCTLDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_SEEKFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_SEEKDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_SOCKOPTFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_SOCKOPTDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_OPENSOCKETFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_OPENSOCKETDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_CLOSESOCKETFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(curl_easy->handle, CURLOPT_CLOSESOCKETDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //
    //curl_easy_setopt(hnd, CURLOPT_PROGRESSFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROGRESSDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_XFERINFOFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_XFERINFODATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_HEADERFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_HEADERDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_DEBUGFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_DEBUGDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_SSL_CTX_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_SSL_CTX_DATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CONV_TO_NETWORK_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CONV_FROM_NETWORK_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CONV_FROM_UTF8_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_INTERLEAVEFUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_INTERLEAVEDATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CHUNK_BGN_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CHUNK_END_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_CHUNK_DATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_FNMATCH_FUNCTION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_FNMATCH_DATA, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_ERRORBUFFER, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_STDERR, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_FAILONERROR, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROTOCOLS, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_REDIR_PROTOCOLS, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXY, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYPORT, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYTYPE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_NOPROXY, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_HTTPPROXYTUNNEL, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_SOCKS5_GSSAPI_SERVICE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_SOCKS5_GSSAPI_NEC, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_INTERFACE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_LOCALPORT, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_LOCALPORTRANGE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_DNS_CACHE_TIMEOUT, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_DNS_USE_GLOBAL_CACHE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PORT, 
    //                 har_request_get_port(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TCP_NODELAY, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_ADDRESS_SCOPE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TCP_KEEPIDLE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TCP_KEEPINTVL, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_NETRC, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_NETRC_FILE, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_USERPWD, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYUSERPWD, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_USERNAME, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PASSWORD, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_LOGIN_OPTIONS, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYUSERNAME, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYPASSWORD, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_HTTPAUTH, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TLSAUTH_USERNAME, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_TLSAUTH_PASSWORD, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PROXYAUTH, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_SASL_IR, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_XOAUTH2_BEARER, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_AUTOREFERER, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_ACCEPT_ENCODING, 
    //                 har_headers_get_accept_encoding (har_request_get_headers (har_clnt_opts)));
    //
    //curl_easy_setopt(hnd, CURLOPT_TRANSFER_ENCODING, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_FOLLOWLOCATION, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_UNRESTRICTED_AUTH, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_POSTREDIR, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, CURLOPT_PUT, 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //
    //// ...
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    // ...
    //
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));
    //curl_easy_setopt(hnd, , 
    //                 har_client_options_get_verbose(har_clnt_opts));

    /* httpVersion */
    {
      gint version = har_request_get_version(self);
      gchar * version_str = har_render_http_version_string(version);
      curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, version_str);
      g_free(version_str);
    }

    /* method */
    {
        const gchar * method = har_request_get_method(self);
        gboolean auto_method = self->priv->_auto_method;

        /* libcurl has a very complicated way to set 'method' */
        if (!g_ascii_strcasecmp(method, "GET")) {
          gint curl_method = auto_method ? 0 : CURLOPT_HTTPGET;
          curl_easy_setopt(hnd, curl_method, TRUE);
        } else if (!g_ascii_strcasecmp(method, "POST")) {
          gint curl_method = auto_method ? CURLOPT_POST : CURLOPT_HTTPPOST;
          curl_easy_setopt(hnd, curl_method, TRUE);
        } else if (!g_ascii_strcasecmp(method, "PUT")) {
          gint curl_method = CURLOPT_PUT;
          curl_easy_setopt(hnd, curl_method, TRUE);
        } else if (!g_ascii_strcasecmp(method, "HEAD")) {
          gint curl_method = CURLOPT_NOBODY;
          curl_easy_setopt(hnd, curl_method, TRUE);
        } else {

          /* Make sure that we pass the method in uppercase. */
          gchar * curl_method = g_ascii_strup(method, strnlen(method, 16));
          curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, curl_method);

          /* "Before [libcurl] version 7.17.0, strings were not copied" 
           * but they are now. This provides a minimum version number
           * for which libcurl we are compatible with.
           */
          g_free(curl_method);
        }
        
        /* Other methods to consider adding:
         * CURLOPT_COPYPOSTFIELDS
         * CURLOPT_POSTFIELDS
         */
    }

    /* url */
    {
      const gchar * url = har_request_get_url(self);
      curl_easy_setopt(hnd, CURLOPT_URL, url);
    }

}
