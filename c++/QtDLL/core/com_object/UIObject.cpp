#include "UIObject.h"
#include "COExports.h"
#include "Au3.h"
#include "AllComObject.h"
#include <QMetaObject>

UIObject::UIObject()
{
    this->objType = UI_OBJECT;
}

UIObject::~UIObject()
{
    this->clear();
}

UIObject *UIObject::add(wchar_t *key)
{
    if(this->methodId){
        objExport->app->au3->m_ids.push_back(this->methodId);
        this->methodId = 0;
    }

    auto obj = map.value(key);
    if(obj) return obj;

    obj = new UIObject;
    obj->addRef();
    map.insert(key,obj);
    return obj;
}

void UIObject::notPrototypeExecute(wchar_t *key, FunctionInput *params)
{

    auto obj = map.value(key);
    if(!obj) return;

    if(obj->methodId == 0){
        params->setResultObject(obj);
    }else{
        objExport->app->au3->inputs = params;
        auto result = objExport->app->engine()->evaluate(
                    QString::fromStdString("g.callUIMethod(")
                    .append(QString::number(obj->methodId))
                    .append(")")
                    ).toVariant();

        if(!result.isNull()){
            switch (result.type()) {
            case QVariant::String:
            {
                auto str = result.toString();
                if(str.isEmpty()) break;
                params->setResultString((wchar_t *)str.toStdWString().c_str());
                break;
            }
                break;
            case QVariant::Int:
                params->setResultNumber(result.toInt());
                break;
            case QVariant::Double:
                params->setResultNumber(result.toDouble());
                break;
            case QVariant::Map:
            {
                auto subMap = result.toMap();
                CObject * subObj = new CObject;
                Au3::setDataCObjectFromMapVariant(subObj, &subMap);
                params->setResultObject(subObj);
                break;
            }
            case QVariant::List:
            {
                CArray * subArr = new CArray;
                auto subList = result.toList();
                Au3::setDataCArrayFromListVariant(subArr, &subList);
                params->setResultObject((BaseObject *)subArr);
                break;
            }
            }
        }
    }
}

void UIObject::clear()
{
    for(auto iter = map.begin(); iter != map.end(); iter++) delete iter.value();
    if(this->methodId) objExport->app->au3->m_ids.push_back(this->methodId);
    this->map = {};
    this->methodId = 0;
}

void UIObject::setMethodID(int id)
{
    this->clear();
    if(this->methodId){
        objExport->app->au3->m_ids.push_back(this->methodId);
    }
    this->methodId = id;
}
