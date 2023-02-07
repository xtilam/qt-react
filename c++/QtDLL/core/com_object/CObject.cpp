#include "CObject.h"

CObject::~CObject()
{
    for(auto iter = map.begin(); iter != map.end(); iter++){
        delete iter.value();
    }
}

CObject::CObject() : BaseObject()
{
    this->objType = OBJECT;
}

void CObject::notPrototypeExecute(wchar_t *key, FunctionInput *params)
{
    if(params->length() == 0){
        auto variant = map.value(key);
        if(!variant) return;
        params->setResultCVariant(variant);
    }else{
        setProperty(key, params->nextToCVariant());
        params->setResultObject(this);
    }
}

void CObject::get(FunctionInput *params)
{
    wchar_t * key;
    params->nextToWString(&key);
    auto variant = this->getProperty(key);
    if(!variant) return;
    params->setResultCVariant(variant);
}

void CObject::set(FunctionInput *params)
{
    wchar_t * key;
    CVariant * v = new CVariant;

    params->nextToWString(&key)
            ->nextToCVariant(v);

    this->setProperty(key, v);
    params->setResultObject(this);
}

void CObject::deleteProperty(FunctionInput *params)
{
    wchar_t * key;
    params->nextToWString(&key);
    this->removeProperty(key);
}

CVariant *CObject::getProperty(wchar_t *key)
{
    return map.value(key);
}

void CObject::removeProperty(wchar_t *key)
{
    auto val = map.value(key);
    if(!val) return;
    delete val;
}

void CObject::setProperty(wchar_t *key, CVariant *v)
{
    auto val = map.value(key);
    if(val) delete val;
    map.insert(key, v);
}

BaseObject::SPrototype *CObject::getPrototype()
{
    static auto prototype = makePrototype<void(CObject::*)(FunctionInput *)>
            ({
                 {"get", &CObject::get},
                 {"set", &CObject::set},
                 {"delete", &CObject::deleteProperty},
             });
    return prototype;
}
