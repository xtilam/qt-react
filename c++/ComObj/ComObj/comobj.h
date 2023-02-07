#ifndef COMOBJ_H
#define COMOBJ_H

#include <oaidl.h>
#include <atomic>
#include <map>
#include <iostream>


using namespace std;


class ComObject : public IDispatch
{
public:
    typedef void(*TDeleteMethod)(void* data);
    typedef void(*TExecuteMethod)(void* data, wchar_t * key, DISPPARAMS* pDispParams, VARIANT* pVarResult);

    inline static const VARIANT* NULL_VARIANT = new VARIANT{ VT_EMPTY };
    map<short, wstring> mapKey; 
    unsigned short autoKey = 0;

    inline static void** methods = nullptr;
    void* data;

    enum Methods {
        onDelete,
        onExecute,
    };


    ComObject(void* data);
    ~ComObject();

    std::atomic<int> m_ref = 0;

    ULONG STDMETHODCALLTYPE AddRef() override;
    ULONG STDMETHODCALLTYPE Release() override;
    HRESULT STDMETHODCALLTYPE QueryInterface(const IID& riid, void** ppvObject) override;
    HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctinfo) override;
    HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) override;
    HRESULT STDMETHODCALLTYPE GetIDsOfNames(const IID& riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) override;
    HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, const IID& riid, LCID lcid, WORD wFlags,
        DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) override;
};


#endif // COMOBJ_H
