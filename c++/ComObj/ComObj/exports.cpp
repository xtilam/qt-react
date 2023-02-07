#include "pch.h"
#include "exports.h"
#include "comobj.h"
#include <iostream>

using namespace std;

LPDISPATCH initComObjectMethod(void* data)
{
    auto obj = new ComObject(data);
    return obj;
}

void* getBaseCObject(ComObject * obj)
{
    return obj->data;
}

void allocString(VARIANT* v, wchar_t* str)
{
    v->vt = VT_BSTR;
    v->bstrVal = SysAllocString(str);
}

void deleteObject(ComObject* obj)
{
    delete obj;
}

void addRef(ComObject * obj)
{
    obj->AddRef();
}

void releaseRef(ComObject* obj)
{
    obj->Release();
}

void freeString(VARIANT* v)
{
    SysFreeString(v->bstrVal);
}

void** getAllMethods() {
    return dllMethods;
}

void setMethodsEvents(void** methods) {
    ComObject::methods = methods;
};