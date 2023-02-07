#ifndef QTELEMENTSETATTRIBUTEACTION_H
#define QTELEMENTSETATTRIBUTEACTION_H

#include <QString>
#include <QMap>
#include <QDebug>
#include <QObject>

template<class ELEMENT_CLASS>
class QtElementSetAttributeAction
{
public:
    template<typename PARAM_TYPE>
    struct AttrAction;
    typedef void(QtElementSetAttributeAction<ELEMENT_CLASS>::*callAction)(ELEMENT_CLASS * cl, AttrAction<void*> * attrAction, QString& value);
    QMap<QString, AttrAction<void*>*> mapAction;

    template<typename PARAM_TYPE>
    struct AttrAction{
        void(ELEMENT_CLASS::*elCallback)(PARAM_TYPE);
        callAction callback;
    };
    template<typename T>
    inline QtElementSetAttributeAction * addAction(QString name, void(ELEMENT_CLASS::*callback)(T)){
        mapAction.insert(name, (AttrAction<void*> *)
                         new AttrAction<T>{callback,getCallAction((T*)nullptr)});
        return this;
    };
    inline bool call(ELEMENT_CLASS * cl, QString& attr, QString& value){
        auto action = mapAction[attr];
        if(!action) return false;
        (this->*action->callback)(cl, action, value);
        return true;
    };
private:
        inline callAction getCallAction(QString *){
            return &QtElementSetAttributeAction::callString;
        }
        inline callAction getCallAction(int *){
            return &QtElementSetAttributeAction::callInt;
        }
        inline callAction getCallAction(bool *){
            return &QtElementSetAttributeAction::callBool;
        }
        inline void callString(ELEMENT_CLASS * cl, AttrAction<void*> * attrAction, QString& value){
            (cl->*((AttrAction<QString> *)attrAction)->elCallback)(value);
        };
        inline void callBool(ELEMENT_CLASS * cl, AttrAction<void*> * attrAction, QString& value){
            (cl->*((AttrAction<bool> *)attrAction)->elCallback)(value.length() ? true : false);
        };
        inline void callInt(ELEMENT_CLASS * cl, AttrAction<void*> * attrAction, QString& value){
            (cl->*((AttrAction<int> *)attrAction)->elCallback)(value.toInt());
        };
};

#endif // QTELEMENTSETATTRIBUTEACTION_H
