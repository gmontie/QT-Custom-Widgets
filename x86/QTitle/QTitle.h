/****************************************************************************/
/*                                                                          */
/*  Programmer: Gregory L Montgomery                                        */
/*                                                                          */
/*  Copyright © 2010-2019                                                   */
/*                                                                          */
/*  COPYING: (See the file COPYING.md for the GNU General Public License).  */
/*  this program is free software, and you may redistribute it and/or       */
/*  modify it under the terms of the GNU General Public License as          */
/*  published by the Free Software Foundation                               */
/*                                                                          */
/* This file is part of Gregory L Montgomery's code base collection Project.*/
/*                                                                          */
/*     Gregory L Montgomery's code base collection Project is free software:*/
/*     you can redistribute it and/or modify  it under the terms of the GNU */
/*     General Public License as published by the Free Software Foundation, */
/*     either version 3 of the License, or (at your option)                 */
/*     any later version.                                                   */
/*                                                                          */
/*     Gregory L Montgomery's code base collection Project is distributed   */
/*     in the hope that it will be useful, but WITHOUT ANY WARRANTY;        */
/*     without even the implied warranty of MERCHANTABILITY or FITNESS FOR  */
/*     A PARTICULAR PURPOSE.  See the GNU General Public License for more   */
/*     details.                                                             */
/*                                                                          */
/*     You should have received a copy of the GNU General Public License    */
/*     along with Gregory L Montgomery's code base collection Project.      */
/*     If not, see <https://www.gnu.org/licenses/>.                         */
/*                                                                          */
/****************************************************************************/
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
