#ifndef BASEWIDGETELEMENT_H
#define BASEWIDGETELEMENT_H

#include "../QtElement.h"
#include <QObject>
#include <QWidget>

class BaseWidgetElement : public QtElement
{
    Q_OBJECT
public:
    explicit BaseWidgetElement(QObject *parent = nullptr);

    Q_PROPERTY(bool show READ r_show WRITE w_show)
    bool r_show();
    void w_show(bool isShow);

    Q_PROPERTY(int x READ r_x WRITE w_x)
    int r_x();
    void w_x(int x);

    Q_PROPERTY(int y READ r_y WRITE w_y)
    int r_y();
    void w_y(int y);

    Q_PROPERTY(int height READ r_height WRITE w_height)
    int r_height();
    void w_height(int height);

    Q_PROPERTY(int width READ r_width WRITE w_width)
    int r_width();
    void w_width(int width);

	Q_PROPERTY(bool disabled READ r_disabled WRITE w_disabled)
    bool r_disabled();
    void w_disabled(bool isDisabled);

    Q_PROPERTY(QString title READ r_title WRITE w_title)
    QString r_title();
    void w_title(QString title);

	Q_PROPERTY(int windowFlags READ r_windowFlags WRITE w_windowFlags)
    int r_windowFlags();
    void w_windowFlags(int windowFlags);

    Q_PROPERTY(int horPolicy READ r_horPolicy WRITE w_horPolicy)
    int r_horPolicy();
    void w_horPolicy(int horPolicy);

    Q_PROPERTY(int verPolicy READ r_verPolicy WRITE w_verPolicy)
    int r_verPolicy();
    void w_verPolicy(int verPolicy);


    Q_PROPERTY(QJSValue style READ r_css WRITE w_css)
    QJSValue r_css();
    void w_css(QJSValue style);
public:
    QString tagName() override;
    bool isWidget() override final;
};

#endif // BASEWIDGETELEMENT_H
