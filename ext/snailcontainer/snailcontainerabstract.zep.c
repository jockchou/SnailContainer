
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(SnailContainer_SnailContainerAbstract) {

	ZEPHIR_REGISTER_CLASS(SnailContainer, SnailContainerAbstract, snailcontainer, snailcontainerabstract, snailcontainer_snailcontainerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(snailcontainer_snailcontainerabstract_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(SnailContainer_SnailContainerAbstract, get) {

}

PHP_METHOD(SnailContainer_SnailContainerAbstract, has) {

}

