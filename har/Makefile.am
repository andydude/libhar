# preamble

NULL =
AM_CPPFLAGS =
AM_CFLAGS =
AM_LDFLAGS = 
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
DISTCLEANFILES =
lib_LTLIBRARIES =
bin_PROGRAMS =

AM_CFLAGS += \
	$(CURL_CFLAGS) \
	$(INTROSPECTION_CFLAGS) \
	$(JSON_GLIB_CFLAGS) \
	$(SOUP_CFLAGS) \
	$(NULL)

AM_LDFLAGS += \
	$(CURL_LIBS) \
	$(INTROSPECTION_LIBS) \
	$(JSON_GLIB_LIBS) \
	$(SOUP_LIBS) \
	$(NULL)

source_h = \
	$(top_srcdir)/har.h \
	$(top_srcdir)/har/har-object.h \
	$(top_srcdir)/har/har-cache-entry.h \
	$(top_srcdir)/har/har-cache.h \
	$(top_srcdir)/har/har-cookie.h \
	$(top_srcdir)/har/har-entry.h \
	$(top_srcdir)/har/har-header.h \
	$(top_srcdir)/har/har-headers.h \
	$(top_srcdir)/har/har-message-body.h \
	$(top_srcdir)/har/har-message-utils.h \
	$(top_srcdir)/har/har-message.h \
	$(top_srcdir)/har/har-post-param.h \
	$(top_srcdir)/har/har-query-param.h \
	$(top_srcdir)/har/har-request-body.h \
	$(top_srcdir)/har/har-request.h \
	$(top_srcdir)/har/har-response-body.h \
	$(top_srcdir)/har/har-response.h \
	$(top_srcdir)/har/har-timings.h \
	$(top_srcdir)/har/gslist.h \
	$(NULL)


source_c = \
	har-object.c \
	har-cache-entry.c \
	har-cache.c \
	har-cookie.c \
	har-entry.c \
	har-header.c \
	har-headers.c \
	har-message-body.c \
	har-message-utils.c \
	har-message.c \
	har-post-param.c \
	har-query-param.c \
	har-request-body.c \
	har-request.c \
	har-response-body.c \
	har-response.c \
	har-timings.c \
	gslist.c \
	$(NULL)

lib_LTLIBRARIES += libhar.la
libhar_la_SOURCES = $(source_c) $(source_h)
libhar_la_LDFLAGS = -release 0.3 -version-info 0:3

harincludedir = $(includedir)/har
harinclude_DATA = \
	$(source_h) \
	$(NULL)

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
introspection_sources = $(libhar_la_SOURCES)

Har-1.gir: libhar.la
Har_1_gir_INCLUDES = GObject-2.0
Har_1_gir_CFLAGS = $(AM_CFLAGS)
Har_1_gir_PACKAGES =
Har_1_gir_LIBS = libhar.la
Har_1_gir_FILES = $(introspection_sources)
Har_1_gir_NAMESPACE = Har
INTROSPECTION_GIRS += Har-1.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif
