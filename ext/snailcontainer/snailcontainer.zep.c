
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(SnailContainer_SnailContainer) {

	ZEPHIR_REGISTER_CLASS(SnailContainer, SnailContainer, snailcontainer, snailcontainer, snailcontainer_snailcontainer_method_entry, 0);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("values"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("keys"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("raw"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("frozen"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("factories"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailcontainer_snailcontainer_ce, SL("protects"), ZEND_ACC_PRIVATE TSRMLS_CC);

	snailcontainer_snailcontainer_ce->create_object = zephir_init_properties_SnailContainer_SnailContainer;

	zend_class_implements(snailcontainer_snailcontainer_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(snailcontainer_snailcontainer_ce TSRMLS_CC, 1, snailcontainer_containerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailContainer_SnailContainer, __construct) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *key = NULL, *val = NULL, *_0, *_1, **_4;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &values_param);

	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("factories"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("protects"), _1 TSRMLS_CC);
	zephir_is_iterable(values, &_3, &_2, 0, 0, "snailcontainer/SnailContainer.zep", 24);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(val, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_5, 0, key, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailContainer_SnailContainer, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *_0 = NULL, *_1$$3, _2$$3, *_3$$3 = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, 0, id);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, snailcontainer_exception_containernotfoundexception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Identifier \"%s\" is not defined.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, id);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "snailcontainer/SnailContainer.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, id);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailContainer_SnailContainer, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, 0, id);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailContainer_SnailContainer, offsetExists) {

	zval *id_param = NULL, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, id));

}

PHP_METHOD(SnailContainer_SnailContainer, offsetGet) {

	zend_bool _5, _9, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *raw = NULL, *val = NULL, *_0, *_4, *_6, *_7, *_8, *_10, *_11, *_13, *_14, *_17, *_18, *_1$$3, _2$$3, *_3$$3 = NULL, *_15$$4, *_16$$4;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, id))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Identifier \"%s\" is not defined.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, id);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 3, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "snailcontainer/SnailContainer.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("raw"), PH_NOISY_CC);
	_5 = zephir_array_isset(_4, id);
	if (!(_5)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("protects"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_8, _7, id, PH_READONLY, "snailcontainer/SnailContainer.zep", 56 TSRMLS_CC);
		_5 = zephir_array_isset(_6, _8);
	}
	_9 = _5;
	if (!(_9)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_11, _10, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 57 TSRMLS_CC);
		_9 = !(Z_TYPE_P(_11) == IS_OBJECT);
	}
	_12 = _9;
	if (!(_12)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_14, _13, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 58 TSRMLS_CC);
		_12 = !((zephir_method_exists_ex(_14, SS("__invoke") TSRMLS_CC) == SUCCESS));
	}
	if (_12) {
		_15$$4 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_16$$4, _15$$4, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 60 TSRMLS_CC);
		RETURN_CTOR(_16$$4);
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(raw);
	zephir_array_fetch(&raw, _17, id, PH_NOISY, "snailcontainer/SnailContainer.zep", 63 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
	if (zephir_array_isset(_18, raw)) {
		ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(raw, NULL, 0, this_ptr);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_ZVAL_FUNCTION(&val, raw, NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("values"), id, val TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("raw"), id, raw TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("frozen"), id, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	RETURN_CCTOR(val);

}

PHP_METHOD(SnailContainer_SnailContainer, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *value, *_0, *_1$$3, _2$$3, *_3$$3 = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	zephir_get_strval(id, id_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frozen"), PH_NOISY_CC);
	if (zephir_array_isset(_0, id)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, spl_ce_RuntimeException);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Cannot override frozen service \"%s\".", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, id);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "snailcontainer/SnailContainer.zep", 79 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("values"), id, value TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("keys"), id, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailContainer_SnailContainer, offsetUnset) {

	zval *id_param = NULL, *_0, *_1$$3, *_2$$3, *_9$$3, *_10$$3, *_11$$3, *_12$$3, *_3$$4, *_4$$4, *_5$$4, *_6$$4, *_7$$4, *_8$$4;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
	if (zephir_array_isset(_0, id)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 90 TSRMLS_CC);
		if (Z_TYPE_P(_2$$3) == IS_OBJECT) {
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("protects"), PH_NOISY_CC);
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
			zephir_array_fetch(&_5$$4, _4$$4, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 91 TSRMLS_CC);
			zephir_array_unset(&_3$$4, _5$$4, PH_SEPARATE);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
			_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
			zephir_array_fetch(&_8$$4, _7$$4, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 92 TSRMLS_CC);
			zephir_array_unset(&_6$$4, _8$$4, PH_SEPARATE);
		}
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		zephir_array_unset(&_9$$3, id, PH_SEPARATE);
		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("frozen"), PH_NOISY_CC);
		zephir_array_unset(&_10$$3, id, PH_SEPARATE);
		_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("raw"), PH_NOISY_CC);
		zephir_array_unset(&_11$$3, id, PH_SEPARATE);
		_12$$3 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
		zephir_array_unset(&_12$$3, id, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailContainer_SnailContainer, factory) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!((zephir_method_exists_ex(callback, SS("__invoke") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Service definition is not a Closure or invokable object.", "snailcontainer/SnailContainer.zep", 105);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "attach", NULL, 0, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(callback, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailContainer_SnailContainer, protect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!((zephir_method_exists_ex(callback, SS("__invoke") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Service definition is not a Closure or invokable object.", "snailcontainer/SnailContainer.zep", 114);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("protects"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "attach", NULL, 0, callback);
	zephir_check_call_status();
	RETVAL_ZVAL(callback, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailContainer_SnailContainer, raw) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *_0, *_4, *_7, *_8, *_1$$3, _2$$3, *_3$$3 = NULL, *_5$$4, *_6$$4;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, id))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Identifier \"%s\" is not defined.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, id);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 3, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "snailcontainer/SnailContainer.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("raw"), PH_NOISY_CC);
	if (zephir_array_isset(_4, id)) {
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("raw"), PH_NOISY_CC);
		zephir_array_fetch(&_6$$4, _5$$4, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 126 TSRMLS_CC);
		RETURN_CTOR(_6$$4);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
	zephir_array_fetch(&_8, _7, id, PH_NOISY | PH_READONLY, "snailcontainer/SnailContainer.zep", 128 TSRMLS_CC);
	RETURN_CTOR(_8);

}

PHP_METHOD(SnailContainer_SnailContainer, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

PHP_METHOD(SnailContainer_SnailContainer, register) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *provider, *values_param = NULL, *key = NULL, *val = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &provider, &values_param);

	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}


	ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(values, &_1, &_0, 0, 0, "snailcontainer/SnailContainer.zep", 146);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_3, 0, key, val);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

zend_object_value zephir_init_properties_SnailContainer_SnailContainer(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("frozen"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("frozen"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("raw"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("raw"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("keys"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("keys"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("values"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

