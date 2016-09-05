
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(SnailContainer_ContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailContainer, ContainerInterface, snailcontainer, containerinterface, snailcontainer_containerinterface_method_entry);

	return SUCCESS;

}

/**
 * Finds an entry of the container by its identifier and returns it.
 *
 * @param string id Identifier of the entry to look for.
 *
 * @throws NotFoundException  No entry was found for this identifier.
 * @throws ContainerException Error while retrieving the entry.
 *
 * @return mixed Entry.
 */
ZEPHIR_DOC_METHOD(SnailContainer_ContainerInterface, get);

/**
 * Returns true if the container can return an entry for the given identifier.
 * Returns false otherwise.
 * 
 * `has(id)` returning true does not mean that `get(id)` will not throw an exception.
 * It does however mean that `get(id)` will not throw a `NotFoundException`.
 *
 * @param string id Identifier of the entry to look for.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(SnailContainer_ContainerInterface, has);

