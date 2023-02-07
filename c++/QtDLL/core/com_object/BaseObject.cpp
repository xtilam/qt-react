#include "BaseObject.h"
#include <QString>
#include "CObject.h"
#include <QTimer>

void BaseObject::comObjectOnDelete(BaseObject *obj)
{
//    qDebug() << "call on delete" << obj;
    obj->comobject = nullptr;
    delete obj;
}

void BaseObject::comObjectOnExecute(BaseObject *obj, wchar_t* key, DISPPARAMS *pDispParams, VARIANT *pVarResult)
{
    FunctionInput params(pDispParams, pVarResult);

    auto prototype = obj->getPrototype();
    auto method = prototype->value(key);

    if(method == nullptr){
        obj->notPrototypeExecute(key, &params);
    }else{
        (obj->*(method))(&params);
    }
}

BaseObject::BaseObject()
{
    static QMap<int, QString> mapType = {
        {ARRAY, "BaseObject::Array"},
        {OBJECT, "BaseObject::OBJECT"},
        {BASE_OBJECT, "BaseObject::BASE_OBJECT"},
        {UI_OBJECT, "BaseObject::UI_OBJECT"}
    };
    this->comobject = initComObjectMethod(this);
    auto timer = new QTimer;
    BaseObject * obj = this;
    QObject::connect(timer, &QTimer::timeout, timer, [obj](){
//        qDebug() << "object init:" << obj << mapType[obj->objType];
    });
    timer->setSingleShot(true);
    timer->start(0);
}

BaseObject::~BaseObject()
{
    static QMap<int, QString> mapType = {
        {ARRAY, "BaseObject::Array"},
        {OBJECT, "BaseObject::OBJECT"},
        {BASE_OBJECT, "BaseObject::BASE_OBJECT"},
        {UI_OBJECT, "BaseObject::UI_OBJECT"}
    };
//    qDebug() << "object deleted:" << this << mapType[this->objType];
    if(this->comobject){
        deleteObject(this->comobject);
    }
}

BaseObject::SPrototype *BaseObject::getPrototype()
{
    static SPrototype * prototype = new QMap<wstring, prototypeType>;
    return prototype;
}

void BaseObject::notPrototypeExecute(wchar_t * , FunctionInput *)
{

}

void BaseObject::setComObjectFunctions(void *func)
{
    static void * functions[]= {
            (void *)comObjectOnDelete,
            (void *)comObjectOnExecute,
    };
    void (*action)(void ** methods);
    action = (void(*)(void**))func;
    action(functions);
}

void BaseObject::addRef()
{
    addRefObject(this->comobject);
}

void BaseObject::releaseRef()
{
    releaseRefObject(this->comobject);
}
