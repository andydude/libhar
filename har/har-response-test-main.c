#include <glib.h>
#include <har.h>
#include <har/har-message-utils.h>
#include <json-glib/json-glib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    har_init();

    char * s = "{"
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

    char * s2 = "WTF0";
    GError * error;
    gsize length = strlen(s);

    printf("%s\n", s);

    error = NULL;
    HarResponse * resp = HAR_RESPONSE (json_gobject_from_data (HAR_TYPE_RESPONSE, s, length, &error));
    if (error || !resp) {
        printf("WTF\n");
    }

    GBytes * body_bytes = har_response_body_get_text(HAR_RESPONSE_BODY (resp->body));
    printf("DONE");
    char * body_text;
    gsize body_size;
    body_text = g_bytes_unref_to_data(body_bytes, &body_size);
    printf("response.content.text = %s\n", body_text);

    printf("response.status = %d\n", resp->status);
    printf("response.statusText = %s\n", resp->priv->_reason);
    printf("response.content = %lx\n", (gintptr)resp->body);
    printf("response.content.mimeType = %s\n", 
           har_response_body_get_mime_type(resp->body));
    printf("response.content.charset = %s\n",
           har_response_body_get_charset(resp->body));
    printf("response.content.encoding = %s\n",
           har_response_body_get_encoding(resp->body));
    printf("response.content.size = %d\n",
           har_response_body_get_size(resp->body));

    length  = 0;
    s2 = json_gobject_to_data(G_OBJECT (resp), &length);
    if (!s) {
        printf("WTF2\n");
    }
    printf("%s\n", s2);

    s2 = json_gobject_to_data(G_OBJECT (resp), &length);
    if (!s) {
        printf("WTF2\n");
    }
    printf("%s\n", s2);

    return 0;
}
