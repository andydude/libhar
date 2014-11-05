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
"        \"startedDateTime\": \"2014-11-04T15:49:21.041Z\","
"        \"time\": 548.2499599456787,"
"        \"request\": {"
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
"        },"
"        \"response\": {"
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
"        },"
"        \"cache\": {},"
"        \"timings\": {"
"          \"blocked\": 0.612000003457069,"
"          \"dns\": 15.83499996922913,"
"          \"connect\": 1.8860000418499006,"
"          \"send\": 0.13499998021869786,"
"          \"wait\": 528.7259999895472,"
"          \"receive\": 1.0559599613767432,"
"          \"ssl\": -1"
"        },"
"        \"connection\": \"68150\","
"        \"pageref\": \"page_2\""
"      }";

    char * s2 = "WTF0";
    GError * error;
    gsize length = strlen(s);

    printf("%s\n", s);

    error = NULL;
    HarEntry * entry = HAR_ENTRY (json_gobject_from_data (HAR_TYPE_ENTRY, s, length, &error));
    if (error || !entry) {
        printf("WTF\n");
    }

    printf("request = %lx\n", (gintptr)(entry->request));
    printf("request.postData = %lx\n", (gintptr)(HAR_REQUEST_BODY (entry->request->body)));
    printf("response = %lx\n", (gintptr)(entry->response));
    printf("response.content = %lx\n", (gintptr)(HAR_RESPONSE_BODY (entry->response->body)));
printf("cache = %lx\n", (gintptr)(entry->cache));
printf("timings = %lx\n", (gintptr)(entry->timings));
printf("timeouts = %lx\n", (gintptr)(entry->timeouts));
    
    length  = 0;
    s2 = json_gobject_to_data(G_OBJECT (entry), &length);
    if (!s) {
        printf("WTF2\n");
    }
    printf("%s\n", s2);

    s2 = json_gobject_to_data(G_OBJECT (entry), &length);
    if (!s) {
        printf("WTF2\n");
    }
    printf("%s\n", s2);

    return 0;
}
