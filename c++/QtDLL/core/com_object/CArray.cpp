#include "CArray.h"

CArray::CArray() : BaseObject()
{
    this->objType = ARRAY;
}

CArray::~CArray()
{
    for (auto variant : this->items)
    {
        delete variant;
    }
}

void CArray::_length(FunctionInput *params)
{
    params->setResultNumber(this->items.size());
}

uint CArray::length()
{
    return this->items.size();
}

void CArray::_get(FunctionInput *params)
{
    long key = (long)params->nextToNumber();
    if (key >= (long)items.size()) return;
    params->setResultCVariant(this->items[key]);
}

CVariant *CArray::get(uint index)
{
    return this->items[index];
}

void CArray::_push(FunctionInput *params)
{
    int length = params->length();

    for (int i = 0; i < length; i++)
    {
        CVariant *v = new CVariant;
        params->nextToCVariant(v);
        this->items.push_back(v);
    }
    params->setResultObject(this);
}

void CArray::push(vector<CVariant *> variants)
{
    for (auto variant : variants)
    {
        this->items.push_back(variant);
    }
}

void CArray::_unshift(FunctionInput *params)
{
}

void CArray::unshift(vector<CVariant *> variants)
{
    for (auto variant : variants)
    {
        variant->releaseRefIfIsObject();
        this->items.push_back(variant);
    }
}

void CArray::_splice(FunctionInput *params)
{

}

void CArray::splice(uint start, uint nItem, vector<CVariant *> variants)
{
    uint size = this->items.size();
    auto begin = this->items.begin();
    // remove items
    if (start < size)
    {
        int end = start + nItem;
        if (end > size)
        {
            end = size;
        }

        for (int i = start; i < end; i++)
        {
            delete this->items[i];
            this->items.erase(begin + i);
        }
    }

    // add items
    int i = 0;
    for(auto variant: variants){
        this->items.insert(begin + i, variant);
    }
}

void CArray::_shift(FunctionInput *params)
{
}

void CArray::shift()
{
}

void CArray::_pop(FunctionInput *params)
{
    this->pop();
}

void CArray::pop(){
    this->items.pop_back();
}

BaseObject::SPrototype *CArray::getPrototype()
{
    static SPrototype *prototype = makePrototype<void (CArray::*)(FunctionInput *)>({
        {"length", &CArray::_length},
        {"get", &CArray::_get},
        {"push", &CArray::_push},
        {"unshift", &CArray::_unshift},
        {"splice", &CArray::_splice},
        {"shift", &CArray::_shift},
        {"pop", &CArray::_pop},
        {"isArray", &CArray::_isArray}
    });
    return prototype;
}
