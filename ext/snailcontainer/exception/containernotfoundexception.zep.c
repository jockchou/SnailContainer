
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_exceptions.h"


/**
 * No entry was found in the container.
 */
ZEPHIR_INIT_CLASS(SnailContainer_Exception_ContainerNotFoundException) {

	ZEPHIR_REGISTER_CLASS_EX(SnailContainer\\Exception, ContainerNotFoundException, snailcontainer, exception_containernotfoundexception, spl_ce_RuntimeException, NULL, 0);

	zend_class_implements(snailcontainer_exception_containernotfoundexception_ce TSRMLS_CC, 1, snailcontainer_exception_containerexception_ce);
	return SUCCESS;

}

