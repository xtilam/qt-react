#ifndef QTELEMENT_H
#define QTELEMENT_H

#include <QObject>
#include <QJSValue>
#include <QMap>
#include <QDebug>

class QtElement : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int nodeType READ r_nodeType)
    Q_PROPERTY(QString tagName READ tagName)
    Q_PROPERTY(QWidget * widget READ getWidget)
    Q_PROPERTY(QWidget * widgetParentChild READ getWidgetParentChild)
    Q_PROPERTY(QObject * ownerDocument READ r_ownerDocument)
    QObject * r_ownerDocument();
    typedef QtElement * (*initTagNameAction)();
    inline static QMap<QString, initTagNameAction> listInitTag = {};

    explicit QtElement(QObject * parent = nullptr);
    static void addInitTagAction(std::initializer_list<initTagNameAction> actions);
    virtual QString tagName();
    virtual bool isWidget();
    virtual QWidget *getWidgetParentChild();
    virtual QWidget *getWidget();
    QJSEngine * engine();

    Q_PROPERTY(QString className READ r_className WRITE w_className)
    QString r_className();
    void w_className(QString className);
    virtual void updateStyle();
    void updateStyleElement(QtElement * el);
    void updateStyleWidget(QWidget * widget);
private:
    int r_nodeType();
public slots:
    void addEventListener(QJSValue name, QJSValue callback);
    void setAttribute(QString key, QString value);
    void removeAttribute(QString key);
    QObject * createElement(QString tagName);
    QJSValue createTextNode(QString text);
    const QVariant getProperty(QString property);
    void setProperty(QString property, const QVariant& value);
    virtual void updateCSS();
    virtual void appendChild(QtElement * el);
    virtual void insertBefore(QtElement * el, QtElement * beforeEl);
    virtual void removeChild(QtElement * el);
};

#endif // QTELEMENT_H
