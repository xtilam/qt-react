#ifndef EXPORTS_H
#define EXPORTS_H

#include <oaidl.h>
#include "comobj.h"

LPDISPATCH initComObjectMethod(void* data);
void* getBaseCObject(ComObject * obj);
void allocString(VARIANT* v, wchar_t*);
void deleteObject(ComObject*);
void addRef(ComObject *obj);
void releaseRef(ComObject *obj);
void freeString(VARIANT* v);
void setMethodsEvents(void** methods);

inline void* dllMethods[] = {
    (void*)initComObjectMethod,
    (void*)getBaseCObject,
    (void*)allocString,
    (void*)deleteObject,
    (void*)addRef,
    (void*)releaseRef,
    (void*)freeString,
    (void*)setMethodsEvents,
};

extern "C" __declspec(dllexport) void** __stdcall getAllMethods();

#endif // EXPORTS_H
