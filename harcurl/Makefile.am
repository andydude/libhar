AM_CFLAGS = -Wall \
	$(CURL_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(HAR_CFLAGS) \
	$(JSON_GLIB_CFLAGS) \
	$(SOUP_CFLAGS) \
	$(NONE)

AM_LDFLAGS = \
	$(CURL_LIBS) \
	$(GLIB_LIBS) \
	$(HAR_LIBS) \
	$(JSON_GLIB_LIBS) \
	$(SOUP_LIBS) \
	$(NONE)

bin_PROGRAMS = harcurl
harcurl_SOURCES = \
	curl-easy.h \
	curl-easy.c \
	harcurl-main.c
