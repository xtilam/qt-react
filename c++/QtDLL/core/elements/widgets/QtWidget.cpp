#include "QtWidget.h"
#include "../../../Utils.h"
#include "../layouts/RowLayout.h"
#include "../layouts/ColumnLayout.h"
#include <QStyle>

QtWidget::QtWidget(QObject * parent) : BaseWidgetElement(parent)
{
    this->widget = new QWidgetCustom;
}

QString QtWidget::r_layout()
{
//    qDebug() << "read layout";
    if(!this->layout) return "";
    return this->layout->layoutName();
}

void QtWidget::w_layout(QString layout)
{
    static const QMap<QString, BaseLayout *(*)()> initLayoutActions = {
        {"row", Utils::makeCallback<BaseLayout, RowLayout>()},
        {"column", Utils::makeCallback<BaseLayout, ColumnLayout>()}
    };
    auto action = initLayoutActions.value(layout);
    if(!action){
        if(this->layout == nullptr) return;
        delete this->layout;
        this->layout = nullptr;
    }else{
        if(this->layout != nullptr) delete this->layout;
        this->layout = action();
        auto qlayout = this->layout->getLayout();
        this->widget->setLayout(qlayout);
        qlayout->setContentsMargins(0,0,0,0);
        qlayout->setSpacing(0);
        for(auto child: widgetChild){
            if(!child->getWidget()) continue;
            this->layout->addWidget((BaseWidgetElement*)child);
        }
    }
}

QtWidget::~QtWidget()
{
    for(auto child: widgetChild){
        delete child;
    }
    if(!this->layout) delete this->layout;
    delete this->widget;
}


QString QtWidget::tagName()
{
    return "qtwidget";
}

QWidget *QtWidget::getWidget()
{
    return widget;
}

void QtWidget::insertBefore(QtElement *el, QtElement *beforeEl)
{
    int widgetIndex = -1;
    int listIndex = -1;
    for(int i=0; i<widgetChild.length(); i++){
        auto widgetEl = widgetChild[i];
        if(widgetEl->getWidget()) ++widgetIndex;
        if(widgetEl == beforeEl){
            listIndex = i;
            break;
        }
    }
    if(listIndex == -1) return;
    widgetChild.insert(listIndex, el);
    if(!this->layout) return;
    if(!el->getWidget()) return;
    this->layout->insertBefore((BaseWidgetElement *)el, widgetIndex);
}

void QtWidget::removeChild(QtElement *el)
{
    for(int i=0; i<widgetChild.length(); i++){
        if(widgetChild[i] != el) continue;
        widgetChild.removeAt(i);
        break;
    }
    delete el;
}


void QtWidget::appendChild(QtElement *el)
{
    this->widgetChild.append(el);
    if(this->layout){
        if(el->getWidget()) {
            this->layout->addWidget((BaseWidgetElement*)el);
        }
    }
}

void QtWidget::updateStyle()
{
    updateStyleWidget(widget);
    for(auto child: this->widgetChild){
        child->updateStyle();
    }
}
