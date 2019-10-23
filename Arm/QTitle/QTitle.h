#ifndef QTITLE_H
#define QTITLE_H

#include <QtDesigner/QtDesigner>
#include <QWidget>
#include <QFrame>
#include <QLabel>
//#include "qtitle_global.h"

class QDESIGNER_WIDGET_EXPORT QTitle : public QFrame
{
    Q_OBJECT

    Q_PROPERTY(QColor Background READ Background WRITE setBackground)
    Q_PROPERTY(QColor TextColor READ TextColor WRITE setTextColor)
    //Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment)
    Q_PROPERTY(QString Text READ Text WRITE setText)

public:
    explicit QTitle(QWidget * parent=0);
    void setBackground(const QColor& );
    void setTextColor(const QColor& );
    void setText(const QString& );
    QColor Background() const;
    QColor TextColor() const;
    QString Text() const;
    QLabel * FramesLabel;
    //Qt::Alignment alignment() const;

protected:
    //void paintEvent(QPaintEvent* event);
    void ChangePalette(void);

private:
    QColor BackgroundColor;
    QColor LightBackground;
    QColor DarkBackground;
    QColor ForgroundTextColor;
    Qt::Alignment Alignment;
    QLinearGradient Gradient;

    QString selfText;
    int Frame_X;
    int Frame_Y;
    int Frame_Width;
    int Frame_Hight;
    int LabelX;
    int LabelY;
};

#endif // QTITLE_H
