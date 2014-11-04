#include <glib.h>
#include <json-glib/json-glib.h>
#include <har-object.h>
#include <har-timings.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char * s = "{\"dns\": 2.0}";
    char * s2 = "WTF0";
    GError * error;
    gsize length = strlen(s);

    printf("Init starting ...\n");
    //g_type_init();
    //g_thread_init();
    //g_object_init();
    printf("Init started\n");

    HarObject * object1 = har_object_new();
    printf("HarObject created\n");

    HarTimings * timings1 = har_timings_new();
    printf("HarTimings created\n");

    error = NULL;
    HarTimings * timings = HAR_TIMINGS (json_gobject_from_data (HAR_TYPE_TIMINGS, s, length, &error));
    if (error || !timings) {
        printf("WTF\n");
    }

    printf("dns = %f\n", timings->dns);
    printf("ssl = %f\n", timings->ssl);
    
    length  = 0;
    s2 = json_gobject_to_data(G_OBJECT (timings), &length);
    if (!s) {
        printf("WTF2\n");
    }

    printf("%s\n", s2);

    return 0;
}
