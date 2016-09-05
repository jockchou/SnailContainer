
extern zend_class_entry *snailcontainer_snailcontainer_ce;

ZEPHIR_INIT_CLASS(SnailContainer_SnailContainer);

PHP_METHOD(SnailContainer_SnailContainer, __construct);
PHP_METHOD(SnailContainer_SnailContainer, get);
PHP_METHOD(SnailContainer_SnailContainer, has);
PHP_METHOD(SnailContainer_SnailContainer, offsetExists);
PHP_METHOD(SnailContainer_SnailContainer, offsetGet);
PHP_METHOD(SnailContainer_SnailContainer, offsetSet);
PHP_METHOD(SnailContainer_SnailContainer, offsetUnset);
PHP_METHOD(SnailContainer_SnailContainer, factory);
PHP_METHOD(SnailContainer_SnailContainer, protect);
PHP_METHOD(SnailContainer_SnailContainer, raw);
PHP_METHOD(SnailContainer_SnailContainer, keys);
PHP_METHOD(SnailContainer_SnailContainer, register);
zend_object_value zephir_init_properties_SnailContainer_SnailContainer(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_has, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_factory, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_protect, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_raw, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainer_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, SnailContainer\\ServiceProviderInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailcontainer_snailcontainer_method_entry) {
	PHP_ME(SnailContainer_SnailContainer, __construct, arginfo_snailcontainer_snailcontainer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailContainer_SnailContainer, get, arginfo_snailcontainer_snailcontainer_get, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, has, arginfo_snailcontainer_snailcontainer_has, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, offsetExists, arginfo_snailcontainer_snailcontainer_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, offsetGet, arginfo_snailcontainer_snailcontainer_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, offsetSet, arginfo_snailcontainer_snailcontainer_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, offsetUnset, arginfo_snailcontainer_snailcontainer_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, factory, arginfo_snailcontainer_snailcontainer_factory, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, protect, arginfo_snailcontainer_snailcontainer_protect, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, raw, arginfo_snailcontainer_snailcontainer_raw, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainer, register, arginfo_snailcontainer_snailcontainer_register, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
