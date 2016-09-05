
extern zend_class_entry *snailcontainer_snailcontainerabstract_ce;

ZEPHIR_INIT_CLASS(SnailContainer_SnailContainerAbstract);

PHP_METHOD(SnailContainer_SnailContainerAbstract, get);
PHP_METHOD(SnailContainer_SnailContainerAbstract, has);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainerabstract_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailcontainer_snailcontainerabstract_has, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailcontainer_snailcontainerabstract_method_entry) {
	PHP_ME(SnailContainer_SnailContainerAbstract, get, arginfo_snailcontainer_snailcontainerabstract_get, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(SnailContainer_SnailContainerAbstract, has, arginfo_snailcontainer_snailcontainerabstract_has, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
