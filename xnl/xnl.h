#pragma once

#include <assert.h>

#ifdef _WIN32
#define XI_STDCALL __stdcall
#define XI_CDECL __cdecl
#define XI_FASTCALL __fastcall
#define XI_PASCAL __pascal
#define XNLEXPORT extern "C"
#else
#define XI_STDCALL __attribute__((__stdcall__))
#define XI_CDECL __attribute__((__cdecl__))
#define XI_FASTCALL __attribute__((regparm(3)))
#define XI_PASCAL
#define XNLEXPORT extern "C" __attribute__ ((visibility("default")))
#endif

typedef int xbool;
typedef const char * xstring;
typedef void* xptr;

class XObject;
class XMethod;
class XContext;
class XObjectId;

#if  defined(_WIN32)||defined(_DRIVER)
typedef 	__int32				xint;
typedef 	signed __int64		xlong;
typedef		unsigned char		xbyte;
typedef 	unsigned short 		xchar;
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__)
typedef 	int32_t				xint;
typedef 	signed	long long   xlong;
typedef		unsigned char		xbyte;
typedef 	unsigned short		xchar;
#endif


class XNLEnv {
public:
	enum XDataType {
		t_nilptr = 0,//是空指针
		t_byte = 1,
		t_char = 2,
		t_short = 3,
		t_int = 4,
		t_long = 5,
		t_double = 6,
		t_bool = 7,
		t_string = 8,
		t_type = 9,
		t_object = 10,
	};
	/**	注意XNLMain中的参数XNLEnv不可永久保存
	需要使用此函数获取一个env实例以永久保存
	*/
	virtual XNLEnv * getEnv() = 0;

	/**	用以销毁getEnv 获取的实例*/
	virtual void releaseEnv(XNLEnv * env) = 0;

	//用来获取类成员方法
	virtual int getClassId(const char * path) = 0;

	//注意 此值需要释放
	virtual XObject * getClass(int id) = 0;

	//用来获取类成员方法
	virtual int getMethodId(const char * path) = 0;

	//注意该方法取得的函数是被派生类重写的函数
	virtual XMethod * getVirtualMethod(XObject * object, int id) = 0;

	//注意该方法取得的函数是path中类的方法
	virtual XMethod * getDynamicMethod(XObject * object, int classId, int id) = 0;

	//注意该方法取得的函数是静态函数
	virtual XMethod * getStaticMethod(XObject * object, int id) = 0;

	//用来获取全局的变量或者方法
	virtual int getObjectId(XObject * object, const char * path) = 0;
	virtual XObject * getObject(XObject * object, int id) = 0;

	//用来获取类成员变量
	virtual int getFieldId(const char * path) = 0;

	//不用释放, 类实例销毁前有效
	virtual XObject * getDynamicField(XObject * object, int id) = 0;
	virtual XObject * getStaticField(XObject * object, int id) = 0;

	//压入参数 在invoke之前
	virtual void pushParam(XContext * context, XObject *) = 0;

	//创建一个context  用来invoke 
	//注意 此对象对应线程, 不同线程之间不可以共享一个context
	//可以长期保存  但只能由一个线程使用
	virtual XContext * getContext(bool * bRelease) = 0;

	//用来释放createContext创建的对象
	virtual void  releaseContext(XContext * context) = 0;

	//创建一个对象的副本, 
	//xlang调用native中的参数对象  若要长期保存,请使用这个函数创建一个引用
	// 用完之后需要使用dereferenceObject 解引用 以免产生泄露
	virtual XObject * referenceObject( XObject * obj) = 0;
	virtual void dereferenceObject(XObject * obj) = 0;

	// 获取xlang中的对象ID,该ID不占用资源,无需释放, 但需要自己保障有效, 即上层finalize时 要使该对象失效
	virtual XObjectId*  getObjectId(XObject * _class) = 0;

	//根据ID 获取xlang上层的对象, 注意 返回值的对象指针不用的时候需要使用dereferenceObject进行释放 否则会占用资源
	//该方法不核查id的有效性， 错误的ID将导致问题
	virtual XObject * refObjectById(XObjectId * id) = 0;

	//设置对象的值
	virtual void setValue(XObject * object, xbyte byteValue) = 0;
	virtual void setValue(XObject * object, xchar charValue) = 0;
	virtual void setValue(XObject * object, short shortValue) = 0;
	virtual void setValue(XObject * object, xint intValue) = 0;
	virtual void setValue(XObject * object, xlong longValue) = 0;
	virtual void setValue(XObject * object, double doubleValue) = 0;
	virtual void setValue(XObject * object, bool boolValue) = 0;
	virtual void setValue(XContext * context, XObject * object, const char * stringValue, int length) = 0;
	virtual void setValue(XObject * object, XObject * value) = 0;

	//获取对象的值
	virtual bool getByteValue(XObject * object, xbyte * byteValue) = 0;
	virtual bool getCharValue(XObject * object, xchar * charValue) = 0;
	virtual bool getShortValue(XObject * object, short * shortValue) = 0;
	virtual bool getIntValue(XObject * object, xint * intValue) = 0;
	virtual bool getLongValue(XObject * object, xlong * longValue) = 0;
	virtual bool getDoubleValue(XObject * object, double * doubleValue) = 0;
	virtual bool getBoolValue(XObject * object, bool * boolValue) = 0;
	virtual bool getStringValue(XObject * object, const char * * stringValue, int * length) = 0;

	virtual bool isArray(XObject * object) = 0;
	virtual xlong getLengthOfArray(XObject * object) = 0;
	virtual xptr getPointerOfArray(XObject * object) = 0;
	//创建一个对象
	virtual XObject * createObject() = 0;

	//创建一个数组
	virtual XObject * createByteArray(int length) = 0;
	virtual XObject * createCharArray(int length) = 0;
	virtual XObject * createShortArray(int length) = 0;
	virtual XObject * createIntArray(int length) = 0;
	virtual XObject * createLongArray(int length) = 0;
	virtual XObject * createDoubleArray(int length) = 0;
	virtual XObject * createBoolArray(int length) = 0;
	virtual XObject * createStringArray(int length) = 0;
	virtual XObject * createObjectArray(int length) = 0;

	virtual bool setElementValue(XObject * object, size_t index, xbyte *byteValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, xchar *charValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, short *shortValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, xint *intValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, xlong *longValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, double *doubleValue, size_t length) = 0;
	virtual bool setElementValue(XObject * object, size_t index, bool *boolValue, size_t length) = 0;
	virtual bool setElementValue(XContext * context, XObject * object, size_t index, xstring* stringValue, int * strslength, size_t length) = 0;
	virtual bool setElementValue(XContext * context, XObject * object, size_t index, XObject ** value, size_t length) = 0;

	virtual bool getElementValue(XObject * object, size_t index, xbyte * byteValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, xchar * charValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, short * shortValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, xint * intValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, xlong * longValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, double * doubleValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, bool * boolValue, size_t length) = 0;
	virtual bool getElementValue(XObject * object, size_t index, xstring * stringValue, size_t * strlength, size_t length) = 0;
	virtual bool getElementValue(XContext * context, XObject * object, size_t index, XObject ** value, size_t length) = 0;


	virtual void throwNativeException(XContext * context, const char * message) = 0;

	//判断对象是不是一个类(非类实例)
	virtual bool isClass(XObject * object) = 0;

	//判断一个对象是不是指定类的实例
	virtual bool isInstanceOf(XObject * object, XObject * _class, bool allowExtends) = 0;

	//判断一个对象是不是指定类的派生类
	virtual bool isExtendsOf(XObject * _class, XObject * _baseclass) = 0;

	//获取对象的类型  需要解引用
	virtual XDataType getObjectType(XObject * object) = 0;

	//获取一个对象的类对象
	virtual XObject * getObjectClass(XObject * object) = 0;

	//获取一个类的基类型
	virtual XObject * getBaseClass(XObject * _classobject) = 0;

	template<typename _FIRST, typename... _LIST>
	XObject * createInstance(XContext * context/*线程*/, XObject * _class/*类*/, XMethod * method/*构造方法*/, _FIRST _Var/*构造参数*/, _LIST... arg) {
		return createInstance(context, _class, method, push_Args(context, _Var, arg...));
	}

	template<typename _FIRST, typename... _LIST>
	XObject * invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		if (virtualMethodId == -1) {
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			return 0;
		}
		return invoke(context, pthis, m, push_Args(context, _Var, arg...));
	}

	template<typename _FIRST, typename... _LIST>
	XObject * invoke(XContext * context, XObject * pthis, XMethod * method, _FIRST _Var, _LIST... arg) {
		return invoke(context, pthis, method, push_Args(context, _Var, arg...));
	}

	template<typename _FIRST, typename... _LIST>
	int push_Args(XContext * context, _FIRST _Var, _LIST... arg) {
		pushParam(context, _Var);
		return  push_Args(context, arg...) + 1;
	}

	XObject * invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		if (virtualMethodId == -1) {
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			return 0;
		}
		return invoke(context, pthis, m, 0);
	}
	//调用函数
	virtual XObject * invoke(XContext * context, XObject * pthis, XMethod * method, int argc) = 0;
	virtual XObject * createInstance(XContext * context, XObject * _class, XMethod * method, int argc) = 0;


	template<typename _FIRST, typename... _LIST>
	void void_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return ;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return ;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret){
			dereferenceObject(ret);
		}
	}

	template<typename _FIRST, typename... _LIST>
	bool bool_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		bool bret = false;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret) {
			getBoolValue(ret, &bret);
			dereferenceObject(ret);
		}
		return bret;
	}

	bool bool_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		bool bret = false;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret) {
			getBoolValue(ret, &bret);
			dereferenceObject(ret);
		}
		return bret;
	}
	template<typename _FIRST, typename... _LIST>
	xint int_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		xint nret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret) {
			getIntValue(ret, &nret);
			dereferenceObject(ret);
		}
		return nret;
	}

	xint int_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		xint nret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret) {
			getIntValue(ret, &nret);
			dereferenceObject(ret);
		}
		return nret;
	}
	template<typename _FIRST, typename... _LIST>
	xchar char_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		xchar cret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret) {
			getCharValue(ret, &cret);
			dereferenceObject(ret);
		}
		return cret;
	}

	xchar char_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		xchar cret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret) {
			getCharValue(ret, &cret);
			dereferenceObject(ret);
		}
		return cret;
	}
	template<typename _FIRST, typename... _LIST>
	xbyte byte_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		xbyte cbret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret) {
			getByteValue(ret, &cbret);
			dereferenceObject(ret);
		}
		return cbret;
	}

	xbyte byte_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		xbyte cbret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret) {
			getByteValue(ret, &cbret);
			dereferenceObject(ret);
		}
		return cbret;
	}
	template<typename _FIRST, typename... _LIST>
	xlong long_invoke(XContext * context, XObject * pthis, int virtualMethodId, _FIRST _Var, _LIST... arg) {
		xlong lret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, push_Args(context, _Var, arg...));
		if (ret) {
			getLongValue(ret, &lret);
			dereferenceObject(ret);
		}
		return lret;
	}

	xlong long_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		xlong lret = 0;

		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret) {
			getLongValue(ret, &lret);
			dereferenceObject(ret);
		}
		return lret;
	}
	template<typename _FIRST, typename... _LIST>
	void void_invoke(XContext * context, XObject * pthis, XMethod * method, _FIRST _Var, _LIST... arg) {
		XObject * ret = invoke(context, pthis, method, push_Args(context, _Var, arg...));
		if (ret){
			dereferenceObject(ret);
		}
	}

	void void_invoke(XContext * context, XObject * pthis, int virtualMethodId) {
		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return ;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return ;
		}
		XObject * ret = invoke(context, pthis, m, 0);
		if (ret){
			dereferenceObject(ret);
		}
	}

	template<class _Type>
	XObject * CreateXObject(_Type v) {
		XObject * obj = createObject();
		setValue(obj, v);
		return obj;
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	XObject *Invoke(XContext * context, XObject * pthis, _METHOD method, _FIRST _Var, _LIST... arg) {
		return Invoke_helper(context, pthis, method, 0, _Var, arg...);
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	XObject *Invoke_helper(XContext * context, XObject * pthis, _METHOD method, int helper_cnt, _FIRST _Var, _LIST... arg) {
		XObject * pret = 0;

		if (typeid(_Var) == typeid(bool)) {
			XObject * param = CreateXObject((xbool)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if (typeid(_Var) == typeid(unsigned char)) {
			XObject * param = CreateXObject((xbyte)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if (typeid(_Var) == typeid(char) || typeid(_Var) == typeid(wchar_t) || typeid(_Var) == typeid(unsigned short)){
			XObject * param = CreateXObject((xchar)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if (typeid(_Var) == typeid(short) || typeid(_Var) == typeid(signed short)) {
			XObject * param = CreateXObject((short)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if (typeid(_Var) == typeid(int) || typeid(_Var) == typeid(signed int) || typeid(_Var) == typeid(unsigned int)) {
			XObject * param = CreateXObject((xint)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if (typeid(_Var) == typeid(long long) || typeid(_Var) == typeid(signed long long) || typeid(_Var) == typeid(unsigned long long)) {
			XObject * param = CreateXObject((xlong)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}
		else
		if (typeid(_Var) == typeid(double) || typeid(_Var) == typeid(float) || typeid(_Var) == typeid(long double)) {
			XObject * param = CreateXObject((double)_Var);
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else
		if(typeid(_Var) == typeid(char*) || typeid(_Var) == typeid(const char *)) {
			XObject * param = createObject();
			const char * pstr = (const char *)((size_t)(_Var));
			setValue(context, param, pstr, strlen(pstr));
			pushParam(context, param);
			pret = Invoke_helper(context, pthis, method, helper_cnt + 1, arg...);
			dereferenceObject(param);
		}else {
			assert(0 && "Unsupported type");
		}
		
		return pret;
	}


	XObject *Invoke_helper(XContext * context, XObject * pthis, XMethod * method, int helper_cnt) {
		return invoke(context, pthis, method, helper_cnt);
	}

	XObject *Invoke_helper(XContext * context, XObject * pthis, int virtualMethodId, int helper_cnt) {
		if (virtualMethodId == -1) {
			assert(0 && "invalid MethodId");
			return 0;
		}
		XMethod * m = getVirtualMethod(pthis, virtualMethodId);
		if (m == 0) {
			assert(0 && "invalid VirtualMethod");
			return 0;
		}
		return invoke(context, pthis, m, helper_cnt);
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	void void_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		XObject * ret = Invoke(context, pthis, virtualMethodId, _Var, arg...);
		if (ret) {
			dereferenceObject(ret);
		}
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	bool bool_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		bool bret = false;
		XObject * ret = Invoke(context, pthis, virtualMethodId, _Var, arg...);
		if (ret) {
			getBoolValue(ret, &bret);
			dereferenceObject(ret);
		}
		return bret;
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	xint int_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		xint nret = 0;

		XObject * ret = Invoke(context, pthis, virtualMethodId, _Var, arg...);
		if (ret) {
			getIntValue(ret, &nret);
			dereferenceObject(ret);
		}
		return nret;
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	xchar char_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		xchar cret = 0;

		XObject * ret = Invoke(context, pthis, virtualMethodId, _Var, arg...);
		if (ret) {
			getCharValue(ret, &cret);
			dereferenceObject(ret);
		}
		return cret;
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	xbyte byte_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		xbyte cbret = 0;

		XObject * ret = Invoke(context, pthis, virtualMethodId, _Var, arg...);
		if (ret) {
			getByteValue(ret, &cbret);
			dereferenceObject(ret);
		}
		return cbret;
	}

	template<typename _FIRST, typename _METHOD, typename... _LIST>
	xlong long_Invoke(XContext * context, XObject * pthis, _METHOD virtualMethodId, _FIRST _Var, _LIST... arg) {
		xlong lret = 0;
		XObject * ret = Invoke(context, pthis, virtualMethodId,  _Var, arg...);
		if (ret) {
			getLongValue(ret, &lret);
			dereferenceObject(ret);
		}
		return lret;
	}

private:
    int push_Args(XContext * ) {
		return 0;
	}

};

/*
entry:
	XNLEXPORT xint XI_STDCALL XNLMain(XNLEnv * env, xint version);
exit:
	XNLEXPORT xint XI_STDCALL XNLExit(XNLEnv * env);
*/