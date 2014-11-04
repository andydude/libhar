m4_define([har_version], [0.2.0])
AC_PREREQ(2.69)
AC_INIT([Har], [har_version])

AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build/autotools])
AC_CONFIG_SRCDIR([har])
AC_CONFIG_HEADER([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries
PKG_CHECK_MODULES([GOBJECT], [gobject-2.0 >= 2.42])

# Checks for typedefs, structures, and compiler characteristics
AC_PROG_CC_STDC

AM_INIT_AUTOMAKE([-Wall -Werror foreign -Wno-portability])
AM_PATH_GLIB_2_0
AM_PROG_AR
AM_SILENT_RULES([yes])
LT_INIT

# Compiler flags
HAR_CFLAGS="$GOBJECT_CFLAGS"
HAR_LIBS="$GOBJECT_LIBS"
AC_SUBST(HAR_CFLAGS)
AC_SUBST(HAR_LIBS)

# Versioning
HAR_MAJOR_VERSION=0
HAR_MINOR_VERSION=2
HAR_MICRO_VERSION=0
HAR_VERSION=har_version
AC_SUBST(HAR_MAJOR_VERSION)
AC_SUBST(HAR_MINOR_VERSION)
AC_SUBST(HAR_MICRO_VERSION)
AC_SUBST(HAR_VERSION)

# Dependancies
GOBJECT_INTROSPECTION_CHECK([1.38.0])
dnl PKG_CHECK_MODULES([gobject], [gobject-2.0])
dnl PKG_CHECK_MODULES([gobject-introspection], [gobject-introspection-1.0])
PKG_CHECK_MODULES([GLIB], [glib-2.0])
PKG_CHECK_MODULES([GIO], [gio-2.0 gio-unix-2.0])
PKG_CHECK_MODULES([JSON_GLIB], [json-glib-1.0])
PKG_CHECK_MODULES([SOUP], [libsoup-2.4])
PKG_CHECK_MODULES([CURL], [libcurl])

# Output
AC_CONFIG_FILES([
	Makefile
	har/Makefile
	harcurl/Makefile
])

AC_OUTPUT
