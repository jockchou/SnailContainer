
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Base interface representing a generic exception in a container.
 */
ZEPHIR_INIT_CLASS(SnailContainer_Exception_ContainerException) {

	ZEPHIR_REGISTER_INTERFACE(SnailContainer\\Exception, ContainerException, snailcontainer, exception_containerexception, NULL);

	return SUCCESS;

}

