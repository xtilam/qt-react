#include "BaseExtension.h"
#include "../exports.h"
BaseExtension::BaseExtension()
{

}

void BaseExtension::setupInit()
{

}

void BaseExtension::setupEngine()
{

}

void BaseExtension::setAllObject()
{
    for(auto ctx: this->listObject){
        ctx->setData(engine());
    }
}

void BaseExtension::addObject(QString name, QObject *obj)
{
    this->listObject.append((new ObjectContext)->setObject(obj)->setName(name));
}

QJSEngine *BaseExtension::engine()
{
    return app->engine();
}

QObject *ObjectContext::r_data()
{
    return this->obj;
}

ObjectContext::ObjectContext(QObject *parent) : QObject(parent)
{

}

ObjectContext *ObjectContext::setObject(QObject * object)
{
    this->obj = object;
    return this;
}

ObjectContext *ObjectContext::setName(QString name)
{
    this->name = name;
    return this;
}

ObjectContext *ObjectContext::setData(QJSEngine *engine)
{
    QString jsName = "_context_";
    QString setString = this->name + "=_context_.data; delete _context_;";
    engine->globalObject().setProperty(jsName, engine->newQObject(this));
    engine->evaluate(setString);
    return this;
}
