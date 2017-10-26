#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([threadpool], [0.0.1], [maplefreez@163.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([confuse], [conf_init], [], [echo "We need libConfUse!!!"; exit 1;], [])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h], [string.h], [unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNC([malloc], [AC_DEFINE([HAVE_MALLOC], 1, [Define if function malloc exists.])])

AC_OUTPUT
