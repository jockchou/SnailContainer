
extern zend_class_entry *snailcontainer_containerinterface_ce;

ZEPHIR_INIT_CLASS(SnailContainer_ContainerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_containerinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_containerinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailcontainer_containerinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailContainer_ContainerInterface, get, arginfo_snailcontainer_containerinterface_get)
	PHP_ABSTRACT_ME(SnailContainer_ContainerInterface, has, arginfo_snailcontainer_containerinterface_has)
	PHP_FE_END
};
