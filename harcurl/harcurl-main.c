#include <stdio.h>
#include <glib.h>
#include <curl/curl.h>
#include <json-glib/json-glib.h>
#include <json-glib/json-gobject.h>
#include <har/har-entry.h>
#include <har/har-entry-curl.h>

int main(int argc, char *argv[]) {
  CURLcode ret;
  CURL * hnd;
  HarEntry * entry;
  
  if (argc > 1) {
      printf("Usage: harcurl < request.har > response.har \n");
      return EXIT_FAILURE;
  }

  /* har entry init */
  entry = har_entry_from_unix_file(stdin);

  /* curl init */
  hnd = curl_easy_init();

  /* transform */
  har_entry_transform_to_curl_easy(entry, hnd);

  /* perform */
  ret = curl_easy_perform(hnd);

  /* transform */
  har_entry_transform_from_curl_easy(entry, hnd);

  /* curl free */
  curl_easy_cleanup(hnd);
  hnd = NULL;

  /* har entry free */
  g_object_unref(entry);
  entry = NULL;

  return (int)ret;
}
