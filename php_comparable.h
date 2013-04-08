/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_COMPARABLE_H
#define PHP_COMPARABLE_H

extern zend_module_entry comparable_module_entry;
#define phpext_comparable_ptr &comparable_module_entry

#ifdef PHP_WIN32
#	define PHP_COMPARABLE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_COMPARABLE_API __attribute__ ((visibility("default")))
#else
#	define PHP_COMPARABLE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(comparable);

ZEND_BEGIN_MODULE_GLOBALS(comparable)
	HashTable orig_create_object_handlers;
ZEND_END_MODULE_GLOBALS(comparable)

#ifdef ZTS
#define COMPARABLE_G(v) TSRMG(comparable_globals_id, zend_comparable_globals *, v)
#else
#define COMPARABLE_G(v) (comparable_globals.v)
#endif

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
