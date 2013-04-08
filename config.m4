dnl $Id$
dnl config.m4 for extension comparable

PHP_ARG_ENABLE(comparable, whether to enable comparable support,
[  --enable-comparable           Enable comparable support])

if test "$PHP_COMPARABLE" != "no"; then
  PHP_NEW_EXTENSION(comparable, comparable.c, $ext_shared)
fi
