#include "EnumDefine.h"
#include <QDebug>
#include <QMetaEnum>
#include <QJSValue>

#include "core/extensions/BaseExtension.h"
#include "core/enums/MouseButtonEnum.h"
#include "core/enums/KeyEnum.h"
#include "core/enums/QSizePolicyEnum.h"
#include "core/enums/QtEnums.h"


void EnumDefine::setup(QJSEngine *engine)
{
    engine->evaluate("if(!this.Qt) this.Qt = {}; this.QSizePolicy = { Policy: 0 };");
    this->registerEnum(engine, &MouseButtonEnum::staticMetaObject, "Qt.MouseButton");
    this->registerEnum(engine, &KeyEnum::staticMetaObject, "Qt.Key");
    this->registerEnum(engine, &QtEnums::staticMetaObject, "Qt.WindowFlags");
    this->registerEnum(engine, &QSizePolicy::staticMetaObject, "QSizePolicy.Policy");
}

void EnumDefine::registerEnum(QJSEngine *engine, const QMetaObject *obj, QString name, int enumIndex)
{
    static QString valName = "__EnumDefineVal_";
    auto jsObj = engine->newQMetaObject(obj);
    engine->globalObject().setProperty(valName, jsObj);
    engine->evaluate(name +"=" + valName + ";delete " + valName);
    const QMetaEnum _enum = obj->enumerator(enumIndex);
    for(int i=0; i<_enum.keyCount(); i++){
        QString name = _enum.key(i);
        QString val = QString::number(_enum.value(i));
        if(jsObj.hasOwnProperty(val)){
            jsObj.setProperty(val, QString(jsObj.property(val).toString() + "," + name));
        }else{
            jsObj.setProperty(val, name);
        }
    }
}
