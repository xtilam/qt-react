#include "pch.h"
#include "comobj.h"

ComObject::ComObject(void* data)
{
    this->data = data;
}

ComObject::~ComObject() {
    ((TDeleteMethod)this->methods[Methods::onDelete])(data);
}

ULONG __stdcall ComObject::AddRef()
{
    return ++m_ref;
}

ULONG __stdcall ComObject::Release()
{
    if (--m_ref == 0)
    {
        delete this;    
        return 0;
    }
    return m_ref;
}

HRESULT __stdcall ComObject::QueryInterface(const IID& riid, void** ppvObject)
{
    if (riid == IID_IUnknown || riid == IID_IDispatch)
    {
        this->AddRef();
        *ppvObject = this;
        return S_OK;
    }
    return E_NOINTERFACE;
}

HRESULT __stdcall ComObject::GetTypeInfoCount(UINT* pctinfo)
{
    if (pctinfo) *pctinfo = 0;
    return S_OK;
}

HRESULT __stdcall ComObject::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    if (ppTInfo) *ppTInfo = NULL;
    return S_OK;
}

HRESULT __stdcall ComObject::GetIDsOfNames(const IID& riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId)
{
    auto index = ++autoKey;
    *rgDispId = autoKey;
    mapKey[*rgDispId] = *rgszNames;
    return S_OK;
}

HRESULT __stdcall ComObject::Invoke(DISPID dispIdMember, const IID& riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    if (wFlags & DISPATCH_METHOD || wFlags & DISPATCH_PROPERTYGET)
    {
        ((TExecuteMethod)methods[Methods::onExecute])(data, (wchar_t*)mapKey[dispIdMember].c_str(), pDispParams, pVarResult);
    }
    mapKey.erase(dispIdMember);
    return S_OK;
}
