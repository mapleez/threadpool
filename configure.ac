#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libthreadpool], [0.0.1], [maplefreez@163.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AM_PROG_AR
AC_PROG_RANLIB

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	tests/Makefile
])
# AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# AC_CHECK_LIB([confuse], [conf_init], [], [echo "We need libConfUse!!!"; exit 1;], [])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h], [string.h], [unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNC([malloc], [AC_DEFINE([HAVE_MALLOC], 1, [Define if function malloc exists.])])

AC_OUTPUT
