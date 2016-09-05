
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * No entry was found in the container.
 */
ZEPHIR_INIT_CLASS(SnailContainer_Exception_NotFoundException) {

	ZEPHIR_REGISTER_INTERFACE(SnailContainer\\Exception, NotFoundException, snailcontainer, exception_notfoundexception, NULL);

	zend_class_implements(snailcontainer_exception_notfoundexception_ce TSRMLS_CC, 1, snailcontainer_exception_containerexception_ce);
	return SUCCESS;

}

