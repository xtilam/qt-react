#include "CParams.h"
#include "BaseObject.h"
#include "CVariant.h"
#include <QDebug>

FunctionInput::FunctionInput(DISPPARAMS * params, VARIANT * result)
{
    this->params = params;
    this->result = result;
    this->index = this->params->cArgs;
}

FunctionInput *FunctionInput::setIndex(int index)
{
    this->index = this->params->cArgs - index;
    return this;
}

FunctionInput *FunctionInput::nextToWString(wchar_t ** str)
{
    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    if(variant->vt == VT_BSTR){
        *str = (&variant->bstrVal)[0];
    }
    return this;
}

FunctionInput *FunctionInput::nextToQString(QString * str)
{
    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    if(variant->vt == VT_BSTR){
        *str = QString::fromStdWString((&variant->bstrVal)[0]);
    }else{
        long double num = 0;
        --this->index;
        this->nextToNumber(&num);
        if(num != 0){
            *str = QString::number((double)num);
        }
    }
    return this;
}

FunctionInput *FunctionInput::nextToNumber(long double * num)
{

    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    switch (variant->vt) {
    case VT_INT:
    case VT_I1:
    case VT_I2:
    case VT_I4:
        *num = variant->intVal;
        break;
    case VT_R4:
        *num = variant->fltVal;
        break;
    case VT_R8:
        *num = variant->dblVal;
    case VT_UI8:
        *num = variant->llVal;
        break;
    }

    return this;
}

FunctionInput *FunctionInput::nextToArray(CArray ** arr)
{
    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    if(variant->vt != VT_DISPATCH || variant->pdispVal == nullptr) return this;
    auto baseobj = BaseObject::getBaseObject(variant->pdispVal);
    if(baseobj->objType != BaseObject::ARRAY) return this;
    *arr = (CArray*)baseobj;
    return this;
}

FunctionInput *FunctionInput::nextToObject(CObject **cobj)
{
    if(this->hasNextParam()) return this;
    auto variant = nextVariant();
    if(variant->vt != VT_DISPATCH || variant->pdispVal == nullptr) return this;
    auto baseobj = BaseObject::getBaseObject(variant->pdispVal);
    if(baseobj->objType != BaseObject::OBJECT) return this;
    *cobj = (CObject *)baseobj;
	return this;
}

FunctionInput * FunctionInput::nextToBool(bool * v)
{
	if(this->hasNextParam()) return this;
	auto variant = nextVariant();
	if(variant->vt != VT_BOOL) return this;
	*v = variant->boolVal;
	return this;
}

FunctionInput *FunctionInput::nextToCVariant(CVariant * cv)
{
    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    cv->setValueFromVariant(variant);
    return this;
}

CVariant *FunctionInput::nextToCVariant()
{
    CVariant * variant = new CVariant;
    this->nextToCVariant(variant);
    return variant;
}

const QString FunctionInput::nextToQString()
{
    QString result;
    nextToQString(&result);
    return result;
}

wchar_t *FunctionInput::nextToWString()
{
    wchar_t * result = nullptr;
    nextToWString(&result);
    return result;
}

bool FunctionInput::nextToBool()
{
    bool result = false;
    nextToBool(&result);
    return result;
}

CObject *FunctionInput::nextToObject()
{
    CObject * obj = nullptr;
    nextToObject(&obj);
    return obj;
}

CArray *FunctionInput::nextToArray()
{
    CArray * arr = nullptr;
    nextToArray(&arr);
    return arr;
}

long double FunctionInput::nextToNumber()
{
    long double result = 0;
    nextToNumber(&result);
    return result;
}

void *FunctionInput::nextToPointer()
{
    if(!this->hasNextParam()) return this;
    auto variant = nextVariant();
    return (void*)(long long)variant->llVal;
}

FunctionInput *FunctionInput::setResultString(wchar_t *str)
{
    BaseObject::allocString(this->result, str);
    return this;
}

FunctionInput *FunctionInput::setResultQString(QString result)
{
    BaseObject::allocString(this->result, (wchar_t *)result.toStdWString().c_str());
    return this;
}

FunctionInput *FunctionInput::setResultNumber(double result)
{
    this->result->vt = VT_R8;
    this->result->dblVal = result;
    return this;
}

FunctionInput *FunctionInput::setResultObject(BaseObject * obj)
{
    if(!obj) return this;
    this->result->vt = VT_DISPATCH;
    this->result->pdispVal = obj->comobject;
    obj->addRef();
	return this;
}

FunctionInput * FunctionInput::setResultBool(bool v)
{
	this->result->vt = VT_DISPATCH;
	this->result->boolVal = v;
	return this;
}

FunctionInput *FunctionInput::setResultCVariant(CVariant * cv)
{
    cv->applyToVariant(this->result);
    cv->addRefIfIsObject();
    return this;
}

FunctionInput *FunctionInput::resetIndex(int index)
{
    if(index >= length()) index = 0;
    this->index = index;
    return this;
}

int FunctionInput::length()
{
    return this->params->cArgs;
}

VARIANT * FunctionInput::nextVariant()
{
    return &this->params->rgvarg[--this->index];
}

bool FunctionInput::hasNextParam()
{
    if(this->index <= 0) return false;
    return true;
}
