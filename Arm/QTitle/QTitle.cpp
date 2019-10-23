#include <math.h>

#include <QPainter>
#include <QGradient>
#include <QPaintDevice>

#include "QTitle.h"


QTitle::QTitle(QWidget * parent) : QFrame(parent)
{
    BackgroundColor = QColor(255, 0, 0, 255);
    ForgroundTextColor = QColor(255, 255, 255, 255);
    setFrameShadow(Raised);
    setFrameShape(Panel);
    setLineWidth(5);
    setAutoFillBackground(true);
    ChangePalette();
    FramesLabel = new QLabel("Text Label", this);
    FramesLabel->setGeometry(3,3,10,10);
    FramesLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    FramesLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FramesLabel->setTextFormat(Qt::AutoText);

    setGeometry(0,0, FramesLabel->height(), FramesLabel->width());
    FramesLabel->show();
}

void QTitle::setBackground(const QColor& Value)
{
    BackgroundColor = Value;
    update();
}

void QTitle::ChangePalette()
{
    LightBackground = BackgroundColor.darker(200);
    DarkBackground = BackgroundColor.darker(300);
    QPalette p = this->palette();
    p.setColor(QPalette::Active, QPalette::Light, LightBackground);
    p.setColor(QPalette::Active, QPalette::Dark, DarkBackground);
    this->setPalette(p);
}

void QTitle::setTextColor(const QColor& Value)
{
    ForgroundTextColor = Value;
}

void QTitle::setText(const QString& Str)
{
    FramesLabel->setText(Str);
    update();
}

QColor QTitle::Background() const
{
    return BackgroundColor;
}

QColor QTitle::TextColor() const
{
    return ForgroundTextColor;
}

QString QTitle::Text() const
{
    return FramesLabel->text();
}

//Qt::Alignment QTitle::alignment() const{return Alignment;}

/*
QTitle::paintEvent(QPaintEvent * q)
{
    Q_UNUSED(Event);

    QPainter p(this);
    QLinearGradient g(Q)
}
*/
