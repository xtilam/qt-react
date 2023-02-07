#include "CDebugger.h"
#include <QDebug>
#include "CArray.h"
#include "CObject.h"
#include "UIObject.h"

CDebugger::CDebugger() : BaseObject()
{

}

void CDebugger::log(FunctionInput *param)
{
    if(!isEnableDebug) return;
    int length = param->length();
    auto debug = qDebug().noquote().nospace();
    CVariant variant;
    for(int i=0; i<length; i++){
        param->nextToCVariant(&variant);
        logVariant(&variant, debug);
    }
}

void CDebugger::logVariant(CVariant *variant, QDebug &debug, const char * trace, bool isSpace)
{
    switch (variant->type) {
    case CVariant::String:{
        QString str;
        variant->getQString(&str);
        if(str.isEmpty()) break;
        debug << str;
        break;
    }
    case CVariant::Number:{
        double num;
        variant->getNumber(&num);
        debug << num;
        break;
    }

    case CVariant::NullValue:
        debug << "NULL";
        break;
    case CVariant::Array:
    {
        auto arr = (CArray*)variant->ptr;
        debug << "Array(" << arr->items.size() << ")[\n";
        int index = 0;
        auto nextTrace =  QString::fromStdString(trace).append("  ").toStdString();
        for(auto item: arr->items){
            debug << nextTrace.c_str() << index++ << ": ";
            logVariant(item, debug, nextTrace.c_str(), false);
            debug << ",\n";
        }
        debug << trace << "]";
        break;
    }
    case CVariant::Object:
    {
        BaseObject * bobj = (BaseObject *)variant->ptr;
        switch(bobj->objType){
        case BaseObject::OBJECT:
        {
            debug << "Object {\n";
            CObject * obj = (CObject *) bobj;
            auto nextTrace =  QString::fromStdString(trace).append("  ").toStdString();
            for(auto iter = obj->map.begin(); iter != obj->map.end(); iter++){
                debug << nextTrace.c_str() << iter.key() << ": ";
                logVariant(iter.value(), debug, nextTrace.c_str(), false);
                debug << ",\n";
            }
            debug << trace << "}";
            break;
        }
        case BaseObject::UI_OBJECT:
        {

            UIObject * obj = (UIObject *) bobj;
            if(!obj->methodId){
                debug << "Object {\n";
                auto nextTrace =  QString::fromStdString(trace).append("  ").toStdString();
                CVariant variant;
                for(auto iter = obj->map.begin(); iter != obj->map.end(); iter++){
                    debug << nextTrace.c_str() << iter.key() << ": ";
                    variant.setValueFromObject(iter.value());
                    logVariant(&variant, debug, nextTrace.c_str(), false);
                    debug << ",\n";
                }
                debug << trace << "}";
            }else{
                debug << "function() { [native code] }";
            }

            break;
        }
        default:
            debug << "Object(" << bobj << ")";
        }
        break;
    }

    case CVariant::Boolean:
        debug << (((bool)variant->ptr) ? "true " : "false");
        break;
    }

    if(isSpace){
        debug << " ";
    }
}

BaseObject::SPrototype *CDebugger::getPrototype()
{
    static auto prototype = BaseObject::makePrototype<void(CDebugger::*)(FunctionInput *)>
        ({
             {"log", &CDebugger::log},
             {"Log", &CDebugger::log},
         });
    return prototype;
}
