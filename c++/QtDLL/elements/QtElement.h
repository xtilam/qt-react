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
    Q_PROPERTY(QWidget * widget READ getWidget)
    Q_PROPERTY(QObject * ownerDocument READ r_ownerDocument)
    QObject * r_ownerDocument();
    inline static QMap<QString, initTagNameAction> listInitTag = {};

    explicit QtElement(QObject * parent = nullptr);
    static void addInitTagAction(std::initializer_list<initTagNameAction> actions);
    virtual QString tagName();
    virtual bool isWidget();
    virtual QWidget *getWidget();

    template<class T>
    inline static initTagNameAction createCallbackInitTagName(){
        return [](){
            return (QtElement *) new T;
        };
    };
private:
    int r_nodeType();
public slots:
    void addEventListener(QJSValue name, QJSValue callback);
    virtual void setAttribute(QString key, QString value);
    virtual void removeAttribute(QString key);
    QObject * createElement(QString tagName);
    virtual void appendChild(QtElement * el);
    virtual void insertBefore(QtElement * el, QtElement * beforeEl);
    virtual void removeChild(QtElement * el);
};

#endif // QTELEMENT_H
