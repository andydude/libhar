#include <glib.h>
#include <har.h>
#include <har/har-message-utils.h>
#include <json-glib/json-glib.h>
#include <stdio.h>
#include <string.h>

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Har"

#define FORMAT "%Y-%m-%dT%H:%M:%SZ"

static void
har_cache_entry_dump (HarCacheEntry * self, gchar * name)
{
    g_info("entry.cache.(cacheEntry) = 0x%lx", (gintptr)self);
    g_info("entry.cache.(cacheEntry).comment = %s",
           har_cache_entry_get_comment(self));
    g_info("entry.cache.(cacheEntry).expires = %s",
           g_date_time_format(har_cache_entry_get_expires(self), FORMAT));
    g_info("entry.cache.(cacheEntry).expires = %s",
           g_date_time_format(har_cache_entry_get_last_access(self), FORMAT));
    g_info("entry.cache.(cacheEntry).lastAccess = %s",
           har_cache_entry_get_etag(self));
    g_info("entry.cache.(cacheEntry).lastAccess = %d",
           har_cache_entry_get_hit_count(self));
}


static void
har_cache_dump (HarCache * self)
{
    g_info("entry.cache = 0x%lx", (gintptr)self);
    g_info("entry.cache.beforeRequest = ...");
    har_cache_entry_dump(har_cache_get_before_request(self), NULL);
    g_info("entry.cache.afterRequest = ...");
    har_cache_entry_dump(har_cache_get_after_request(self), NULL);
}


static const gchar *
get_json_data_for_har_cache_entry (void)
{
    return ("{"
            "    \"expires\": \"2009-04-16T15:50:36\","
            "    \"lastAccess\": \"2009-16-02T15:50:34\","
            "    \"eTag\": \"\","
            "    \"hitCount\": 0,"
            "    \"comment\": \"\""
            "}");
}

static const gchar *
get_json_data_for_har_cache (void)
{
    return ("{"
            "    \"beforeRequest\": {"
            "        \"expires\": \"2009-04-16T15:50:36\","
            "        \"lastAccess\": \"2009-16-02T15:50:34\","
            "        \"eTag\": \"\","
            "        \"hitCount\": 0,"
            "        \"comment\": \"\""
            "    },"
            "    \"afterRequest\": {"
            "        \"expires\": \"2009-04-16T15:50:36\","
            "        \"lastAccess\": \"2009-16-02T15:50:34\","
            "        \"eTag\": \"\","
            "        \"hitCount\": 0,"
            "        \"comment\": \"\""
            "    }"
            "}");
}


static void
test_har_cache_entry (void)
{
    GError * error;
    const gchar * s = get_json_data_for_har_cache_entry ();
    gsize length = strlen(s);

    g_info("old = %s", s);

    // From
    HarCacheEntry * cache_entry = HAR_CACHE_ENTRY (json_gobject_from_data (
                                  HAR_TYPE_CACHE_ENTRY, s, length, &error));

    if (error || !cache_entry) {
        if (error)
            g_error(error->message);
        else
            g_error("No cache entry");
    }

    // Dump Memory
    har_cache_entry_dump(cache_entry, NULL);

    // To
    s = json_gobject_to_data(G_OBJECT (cache_entry), &length);
    if (!s) {
        g_error("No cache entry JSON");
    }

    // Dump JSON
    g_info("new = %s", s);
}


static void
test_har_cache (void)
{
    GError * error;
    const gchar * s = get_json_data_for_har_cache();
    gsize length = strlen(s);

    g_info("old = %s", s);

    // From
    HarCache * cache = HAR_CACHE (json_gobject_from_data (
                       HAR_TYPE_CACHE, s, length, &error));

    if (error || !cache) {
        if (error)
            g_error(error->message);
        else
            g_error("No cache");
    }

    // Dump Memory
    har_cache_dump(cache);

    // To
    s = json_gobject_to_data(G_OBJECT (cache), &length);
    if (!s) {
        g_error("No cache JSON");
    }

    // Dump JSON
    g_info("new = %s", s);
}


int main(int argc, char ** argv)
{
    har_init();

    g_test_init (&argc, &argv, NULL);
    g_test_add_func ("/har/cache-entry", test_har_cache_entry);
    g_test_add_func ("/har/cache", test_har_cache);
    return g_test_run ();
}
