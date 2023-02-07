#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <oaidl.h>
#include <QString>
#include "CVariant.h"
#include <string>
#include <QMap>
#include <QDebug>

using namespace std;

struct BaseObject
{
    static void comObjectOnDelete(BaseObject *obj);
    static void comObjectOnExecute(BaseObject * obj, wchar_t* key, DISPPARAMS* pDispParams, VARIANT* pVarResult);

public:
    BaseObject();
    virtual ~BaseObject();
    typedef void(*TCreateMethod)(void* data);
    typedef void(*TDeleteMethod)(void* data);
    typedef void(*TExecuteMethod)(void* data, wchar_t* key, VARIANT* pVarResult);

    typedef LPDISPATCH (*TInitComObjectType)(void * data);
    typedef BaseObject * (*TGetCObject)(LPDISPATCH obj);
    typedef void (*TAllocString)(VARIANT * v, wchar_t * str);
    typedef void (*TDeleteObject)(LPDISPATCH);
    typedef void (*TAddRef)(LPDISPATCH);
    typedef void (*TRelaseRef)(LPDISPATCH);
    typedef void (*TFreeString)(VARIANT *);

    typedef void(BaseObject::*prototypeType)(FunctionInput *);

    enum ObjectType{
        NULL_VALUE = 0,
        OBJECT,
        ARRAY,
        BASE_OBJECT,
		UI_OBJECT,
    };

    typedef QMap<wstring, prototypeType> SPrototype;

    template<class T>
    struct PrototypeInput
    {
        string name;
        T function;
    };

    LPDISPATCH comobject;
    ObjectType objType = ObjectType::BASE_OBJECT;

    inline static TInitComObjectType initComObjectMethod = nullptr;
    inline static TGetCObject getBaseObject = nullptr;
    inline static TAllocString allocString = nullptr;
    inline static TDeleteMethod deleteObject = nullptr;
    inline static TAddRef addRefObject = nullptr;
    inline static TRelaseRef releaseRefObject = nullptr;
    inline static TFreeString freeString = nullptr;

    virtual SPrototype * getPrototype();
    virtual void notPrototypeExecute(wchar_t * key, FunctionInput *params);
    static void setComObjectFunctions(void * func);

    template<typename T>
    inline static SPrototype *makePrototype(std::initializer_list<PrototypeInput<T>> items){
        SPrototype * map = new QMap<wstring, prototypeType>;
        for(PrototypeInput<T> const &item: items){
            QString name = QString::fromStdString(item.name);
            map->insert(name.toStdWString(), (prototypeType)item.function);
        }
        return map;
    };

    void addRef();
    void releaseRef();
};
#endif // BASEOBJECT_H
