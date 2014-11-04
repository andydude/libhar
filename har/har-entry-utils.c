#include "har-entry-utils.h"

CURLcode har_entry_perform(HarEntry * self, CURL *hnd)
{
    CURLcode result;
    har_entry_transform_to_curl_easy(self, hnd);
    result = curl_easy_perform(hnd);
    har_entry_transform_from_curl_easy(self, hnd);
    return result;
}

HarEntry * har_entry_from_bytes(GBytes * bytes)
{
    HarEntry * result;
    GError * error;
    gchar * contents;
    gsize length;

    contents = g_bytes_unref_to_data(bytes, &length);
    if (contents == NULL) {
      /* TODO */
    }

    error = NULL;
    result = HAR_ENTRY (json_gobject_from_data (HAR_TYPE_ENTRY, contents, length, &error));
    if (result == NULL) {
      /* TODO */
    }

    return result;
}

HarEntry * har_entry_from_string(GString * str)
{
    HarEntry * result;
    GError * error;
    gchar * contents;
    gsize length;

    contents = str->str;
    length = str->len;

    error = NULL;
    result = HAR_ENTRY (json_gobject_from_data (HAR_TYPE_ENTRY, contents, length, &error));
    if (result == NULL) {
      /* TODO */
    }

    return result;
}

HarEntry * har_entry_from_file(GFile * file)
{
    HarEntry * result;
    GError * error;
    gchar * contents;
    gsize length;

    error = NULL;
    if (!g_file_load_contents (file, NULL, &contents, &length, NULL, &error)) {
      /* TODO */
    }

    error = NULL;
    result = HAR_ENTRY (json_gobject_from_data (HAR_TYPE_ENTRY, contents, length, &error));
    if (result == NULL) {
      /* TODO */
    }

    return result;
}

HarEntry * har_entry_from_stream(GInputStream * stream)
{
    HarEntry * result;
    GError * error;
    gchar * buffer = g_malloc0(8000);
    gsize length = 8000;

    error = NULL;
    if (!g_input_stream_read (stream, buffer, length, NULL, &error)) {
      /* TODO */
      g_free(buffer);
      return NULL;
    }

    error = NULL;
    result = HAR_ENTRY (json_gobject_from_data (HAR_TYPE_ENTRY, buffer, length, &error));
    if (result == NULL) {
      /* TODO */
      g_free(buffer);
      return NULL;
    }

    g_free(buffer);

    return result;
}

HarEntry * har_entry_from_unix_file(FILE * file)
{
  GInputStream * istream = g_unix_input_stream_new(0, FALSE);
  HarEntry * entry = har_entry_from_file(istream);
  g_object_unref(istream);
  return entry;
}
