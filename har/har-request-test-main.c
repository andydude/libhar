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
"          \"method\": \"GET\","
"          \"url\": \"http://httpbin.org/get\","
"          \"httpVersion\": \"HTTP/1.1\","
"          \"headers\": ["
"            {"
"              \"name\": \"Accept\","
"              \"value\": \"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\""
"            },"
"            {"
"              \"name\": \"Connection\","
"              \"value\": \"keep-alive\""
"            },"
"            {"
"              \"name\": \"Accept-Encoding\","
"              \"value\": \"gzip,deflate,sdch\""
"            },"
"            {"
"              \"name\": \"Cookie\","
"              \"value\": \"_gauges_unique_year=1; _gauges_unique=1; _gauges_unique_month=1\""
"            },"
"            {"
"              \"name\": \"Host\","
"              \"value\": \"httpbin.org\""
"            },"
"            {"
"              \"name\": \"Accept-Language\","
"              \"value\": \"en-US,en;q=0.8\""
"            },"
"            {"
"              \"name\": \"User-Agent\","
"              \"value\": \"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.2125.111 Safari/537.36\""
"            }"
"          ],"
"          \"queryString\": [],"
"          \"cookies\": ["
"            {"
"              \"name\": \"_gauges_unique_year\","
"              \"value\": \"1\","
"              \"expires\": null,"
"              \"httpOnly\": false,"
"              \"secure\": false"
"            },"
"            {"
"              \"name\": \"_gauges_unique\","
"              \"value\": \"1\","
"              \"expires\": null,"
"              \"httpOnly\": false,"
"              \"secure\": false"
"            },"
"            {"
"              \"name\": \"_gauges_unique_month\","
"              \"value\": \"1\","
"              \"expires\": null,"
"              \"httpOnly\": false,"
"              \"secure\": false"
"            }"
"          ],"
"          \"headersSize\": 424,"
"          \"bodySize\": 0"
"        }";

    char * s2 = "WTF0";
    GError * error;
    gsize length = strlen(s);

    error = NULL;
    HarRequest * entry = HAR_REQUEST (json_gobject_from_data (HAR_TYPE_REQUEST, s, length, &error));
    if (error || !entry) {
        printf("WTF\n");
    }
    
    printf("--- deserialization END\n");
    printf("--- serialization BEGIN\n");

    length  = 0;
    s2 = json_gobject_to_data(G_OBJECT (entry), &length);
    if (!s) {
        printf("WTF2\n");
    }
    printf("%s\n", s2);

    return 0;
}
