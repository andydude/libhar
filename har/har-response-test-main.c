#include <glib.h>
#include <har.h>
#include <har/har-message-utils.h>
#include <json-glib/json-glib.h>
#include <stdio.h>
#include <string.h>

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Har"


static void
har_response_body_dump (HarResponseBody * self)
{
    g_info("entry.response.content = 0x%lx", (gintptr)self);
    g_info("entry.response.content.charset = %s", har_response_body_get_charset(self));
    g_info("entry.response.content.compressedSize = %d", har_response_body_get_compressed_size(self));
    //g_info("entry.response.content.compressedText = %d", har_response_body_get_compressed_size(self));
    g_info("entry.response.content.compression = %d", har_response_body_get_compression(self));
    g_info("entry.response.content.encoding = %s", har_response_body_get_encoding(self));
    //g_info("entry.response.content.mediaType = %s", har_response_body_get_media_type(self));
    g_info("entry.response.content.mimeType = %s", har_response_body_get_mime_type(self));
    g_info("entry.response.content.size = %d", har_response_body_get_size(self));

    GBytes * bytes = har_response_body_get_text(self);
    gsize size; gchar * text = g_bytes_unref_to_data(bytes, &size);
    g_info("entry.response.content.text = size %d", size);
}


static void
har_response_dump (HarResponse * self)
{
    g_info("entry.response = 0x%lx", (gintptr)self);
    //g_info("entry.response.content = {}");
    //g_info("entry.response.cookies = []");
    //g_info("entry.response.headers = []");
    g_info("entry.response.bodySize = %d", har_response_get_body_size(self));
    g_info("entry.response.headersSize = %d", har_response_get_headers_size(self));
    g_info("entry.response.httpVersion = %s", har_response_get_http_version(self));
    g_info("entry.response.httpVersionNumber = %d", har_response_get_version(self));
    g_info("entry.response.redirectURL = %s", har_response_get_redirect_url(self));
    g_info("entry.response.status = %d", har_response_get_status(self));
    g_info("entry.response.statusText = %s", har_response_get_reason(self));
}


static const gchar *
get_json_data_for_har_response (void)
{
    return "{"
"          \"status\": 200,"
"          \"statusText\": \"OK\","
"          \"httpVersion\": \"HTTP/1.1\","
"          \"headers\": ["
"            {"
"              \"name\": \"Date\","
"              \"value\": \"Tue, 04 Nov 2014 15:49:20 GMT\""
"            },"
"            {"
"              \"name\": \"Via\","
"              \"value\": \"1.1 vegur\""
"            },"
"            {"
"              \"name\": \"Server\","
"              \"value\": \"gunicorn/18.0\""
"            },"
"            {"
"              \"name\": \"Content-Type\","
"              \"value\": \"application/json\""
"            },"
"            {"
"              \"name\": \"Access-Control-Allow-Origin\","
"              \"value\": \"*\""
"            },"
"            {"
"              \"name\": \"Access-Control-Allow-Credentials\","
"              \"value\": \"true\""
"            },"
"            {"
"              \"name\": \"Connection\","
"              \"value\": \"keep-alive\""
"            },"
"            {"
"              \"name\": \"Content-Length\","
"              \"value\": \"704\""
"            }"
"          ],"
"          \"cookies\": [],"
"          \"content\": {"
"            \"size\": 704,"
"            \"mimeType\": \"application/json\","
"            \"compression\": 0,"
"            \"text\": \"{\\n  \\\"args\\\": {}, \\n  \\\"headers\\\": {\\n    \\\"Accept\\\": \\\"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\\\", \\n    \\\"Accept-Encoding\\\": \\\"gzip,deflate,sdch\\\", \\n    \\\"Accept-Language\\\": \\\"en-US,en;q=0.8\\\", \\n    \\\"Connect-Time\\\": \\\"2\\\", \\n    \\\"Connection\\\": \\\"close\\\", \\n    \\\"Cookie\\\": \\\"_gauges_unique_year=1; _gauges_unique=1; _gauges_unique_month=1\\\", \\n    \\\"Host\\\": \\\"httpbin.org\\\", \\n    \\\"Total-Route-Time\\\": \\\"0\\\", \\n    \\\"User-Agent\\\": \\\"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.2125.111 Safari/537.36\\\", \\n    \\\"Via\\\": \\\"1.1 vegur\\\", \\n    \\\"X-Request-Id\\\": \\\"85acc03b-d415-4081-a35c-29e9f34949cc\\\"\\n  }, \\n  \\\"origin\\\": \\\"108.48.76.162\\\", \\n  \\\"url\\\": \\\"http://httpbin.org/get\\\"\\n}\""
"          },"
"          \"redirectURL\": \"\","
"          \"headersSize\": 244,"
"          \"bodySize\": 704"
"        }";
}


static const gchar *
get_json_data_for_har_response_body (void)
{
    return "{"
        "  \"size\": 704,"
        "  \"mimeType\": \"application/json\","
        "  \"compression\": 0,"
        "  \"text\": \"{\\n  \\\"args\\\": {}, \\n  \\\"headers\\\": {\\n    \\\"Accept\\\": \\\"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\\\", \\n    \\\"Accept-Encoding\\\": \\\"gzip,deflate,sdch\\\", \\n    \\\"Accept-Language\\\": \\\"en-US,en;q=0.8\\\", \\n    \\\"Connect-Time\\\": \\\"2\\\", \\n    \\\"Connection\\\": \\\"close\\\", \\n    \\\"Cookie\\\": \\\"_gauges_unique_year=1; _gauges_unique=1; _gauges_unique_month=1\\\", \\n    \\\"Host\\\": \\\"httpbin.org\\\", \\n    \\\"Total-Route-Time\\\": \\\"0\\\", \\n    \\\"User-Agent\\\": \\\"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.2125.111 Safari/537.36\\\", \\n    \\\"Via\\\": \\\"1.1 vegur\\\", \\n    \\\"X-Request-Id\\\": \\\"85acc03b-d415-4081-a35c-29e9f34949cc\\\"\\n  }, \\n  \\\"origin\\\": \\\"108.48.76.162\\\", \\n  \\\"url\\\": \\\"http://httpbin.org/get\\\"\\n}\""
        "}";
}


static void
test_har_response_body (void)
{
    GError * error;
    const gchar * s = get_json_data_for_har_response_body ();
    gsize length = strlen(s);

    g_info("old = %s", s);

    // From
    HarResponseBody * body = HAR_RESPONSE_BODY (json_gobject_from_data (
                             HAR_TYPE_RESPONSE_BODY, s, length, &error));

    if (error || !body) {
        if (error)
            g_error(error->message);
        else
            g_error("No response body");
    }

    // Dump Memory
    har_response_body_dump(body);

    // To
    s = json_gobject_to_data(G_OBJECT (body), &length);
    if (!s) {
        g_error("No response body JSON");
    }

    // Dump JSON
    g_info("new = %s", s);
}


static void
test_har_response (void)
{
    GError * error;
    const gchar * s = get_json_data_for_har_response();
    gsize length = strlen(s);

    g_info("old = %s", s);

    // From
    HarResponse * resp = HAR_RESPONSE (json_gobject_from_data (
                         HAR_TYPE_RESPONSE, s, length, &error));

    if (error || !resp) {
        if (error)
            g_error(error->message);
        else
            g_error("No response");
    }

    // Dump Memory
    har_response_dump(resp);

    // To
    s = json_gobject_to_data(G_OBJECT (resp), &length);
    if (!s) {
        g_error("No response JSON");
    }

    // Dump JSON
    g_info("new = %s", s);
}


int main(int argc, char ** argv)
{
    har_init();

    g_test_init (&argc, &argv, NULL);
    g_test_add_func ("/har/response-body", test_har_response_body);
    g_test_add_func ("/har/response", test_har_response);
    return g_test_run ();
}
