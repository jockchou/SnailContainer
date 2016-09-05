
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Snail service provider interface.
 *
 */
ZEPHIR_INIT_CLASS(SnailContainer_ServiceProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailContainer, ServiceProviderInterface, snailcontainer, serviceproviderinterface, snailcontainer_serviceproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Registers services on the given container.
 *
 * This method should only be used to configure services and parameters.
 * It should not get services.
 *
 * @param container A SnailContainer instance
 */
ZEPHIR_DOC_METHOD(SnailContainer_ServiceProviderInterface, register);

