
extern zend_class_entry *snailcontainer_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(SnailContainer_ServiceProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_serviceproviderinterface_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, SnailContainer\\SnailContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailcontainer_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailContainer_ServiceProviderInterface, register, arginfo_snailcontainer_serviceproviderinterface_register)
	PHP_FE_END
};
