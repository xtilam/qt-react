#ifndef QTELEMENT_H
#define QTELEMENT_H

#include <QObject>
#include <QJSValue>
#include <QMap>

class QtElement;

typedef QtElement * (*initTagNameAction)();

class QtElement : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int nodeType READ r_nodeType)
    Q_PROPERTY(QString tagName READ tagName)
    inline static QMap<QString, initTagNameAction> listInitTag = {};
    explicit QtElement(QObject * parent);
    static void addInitTagAction(std::initializer_list<initTagNameAction> actions);
    virtual QString tagName();
    virtual bool isWidget();
    virtual QWidget *getWidget();
private:
    int r_nodeType();
public slots:
    void addEventListener(QJSValue name, QJSValue callback);
    virtual void setAttribute(QString key, QString value);
    virtual void removeAttribute(QString key);
    QtElement * createElement(QString tagName);
    virtual void insertBefore(QtElement * el, QtElement * beforeEl);
    virtual void removeElement(QtElement * el);
};

#endif // QTELEMENT_H
