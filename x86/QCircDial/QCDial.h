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
#ifndef QCDial_H
#define QCDial_H

#include <QtDesigner/QtDesigner>
#include <QWidget>
#include <QColor>

class QDESIGNER_WIDGET_EXPORT QCDial : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString Title READ Title WRITE setTitle)
    Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ value WRITE setValue)
    Q_PROPERTY(int Xoffset READ Xoffset WRITE setXOffset)
    Q_PROPERTY(int Yoffset READ Yoffset WRITE setYOffset)
    Q_PROPERTY(int textsOffset READ textsOffset WRITE setTextsOffset)

    Q_PROPERTY(bool drawingInterCircle READ drawingInterCircle WRITE drawInterCircle)
    Q_PROPERTY(int outerCircleThickness READ outerCircleThickness WRITE setOuterCircleThickness)
    Q_PROPERTY(int outerRadius READ outerRadius WRITE setOuterRadius)

    Q_PROPERTY(bool drawingOuterCircle READ drawingOuterCircle WRITE drawOuterCircle)
    Q_PROPERTY(int interCircleThickness READ interCircleThickness WRITE setInterCircleThickness)
    Q_PROPERTY(int interRadius READ interRadius WRITE setInterRadius)

    Q_PROPERTY(int majorInterval READ majorInterval WRITE setMajorsInterval)
    Q_PROPERTY(int minorInterval READ minorInterval WRITE setMinorsInterval)

    Q_PROPERTY(int majorOver READ majorOver WRITE setMajorsOver)
    Q_PROPERTY(int majorUnder READ majorUnder WRITE setMajorsUnder)

    Q_PROPERTY(int minorOver READ minorOver WRITE setMinorsOver)
    Q_PROPERTY(int minorUnder READ minorUnder WRITE setMinorsUnder)

    // Needle Variables
    Q_PROPERTY(int NeedlesWidth READ needleWidth WRITE setNeedlesWidth)
    Q_PROPERTY(bool useGradient READ useGradient WRITE use_A_Gradient)
    // Color layout for Dial
    Q_PROPERTY(QColor needleColor READ needleColor WRITE setNeedlesColor)
    Q_PROPERTY(QColor needlesFillColor READ needlesFillColor WRITE setNeedlesFillColor)
    Q_PROPERTY(QColor pivotPointColor READ pivotPointColor WRITE setPivotPointColor)
    Q_PROPERTY(QColor background READ background WRITE setBackground)
    Q_PROPERTY(QColor foreground READ foreground WRITE setForeground)
    Q_PROPERTY(QColor majorColor READ majorColor WRITE setMajorColor)
    Q_PROPERTY(QColor minorColor READ minorColor WRITE setMinorColor)
    Q_PROPERTY(QColor outerCircleColor READ outerCircleColor WRITE setOuterCircleColor)
    Q_PROPERTY(QColor interCircleColor READ interCircleColor WRITE setInterCircleColor)


public:
    explicit QCDial(QWidget * parent=0);
    ~QCDial();
    void use_A_Gradient(const bool qValue);
    void drawOuterCircle(const bool qValue);
    void drawInterCircle(const bool qValue);
    void setMaxValue(const double);
    void setNeedlesFillColor(const QColor qValue);
    void setTextsOffset(int);
    void setXOffset(int);
    void setYOffset(int);
    void setOuterCircleThickness(const int);
    void setInterCircleThickness(const int);
    void setOuterRadius(const int);
    void setInterRadius(const int);
    void setTitle(QString);
    void setTitle(char *);
    void setValue(double);
    void setMajorsInterval(int const);
    void setMajorsOver(const int);
    void setMajorsUnder(const int);
    void setMinorsInterval(const int);
    void setMinorsOver(const int);
    void setMinorsUnder(const int);
    void setNeedlesWidth(const int);
    void setBackground(const QColor);
    void setForeground(const QColor);
    void setMajorColor(const QColor);
    void setMinorColor(const QColor);
    void setOuterCircleColor(const QColor);
    void setInterCircleColor(const QColor);
    void setNeedlesColor(const QColor);
    void setPivotPointColor(const QColor);
    int heightForWidth(int width) const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    int Xoffset()const{return m_Controls_X;}
    int Yoffset()const{return m_Controls_Y;}
    int textsOffset()const{return m_TextsOffset;}
    int outerCircleThickness()const{return m_OuterCircleThickness;}
    int interCircleThickness()const{ return m_InterCircleThickness; }
    int outerRadius()const{ return m_OuterRadius;}
    int interRadius()const{ return m_InterRadius;}
    QString Title()const{ return *DialsName; }
    double value()const { return m_Value; }
    double maxValue()const{ return m_MaxValue; }
    int majorInterval()const{ return m_MajorInterval; }
    int majorOver()const {return m_MajorOver;}
    int majorUnder()const {return m_MajorUnder;}
    int minorInterval()const {return m_MinorInterval;}
    int minorOver()const {return  m_MinorOver;}
    int minorUnder()const {return m_MinorUnder;}
    int needleWidth() const {return m_NeedleWidth;}
    bool useGradient()const {return m_UseGradient;}
    bool drawingOuterCircle()const { return m_DrawOuterCircle;}
    bool drawingInterCircle()const { return m_DrawInterCircle; }
    bool userGradient()const {return m_UseGradient;}
    QColor background()const {return m_DialsBackground; }
    QColor foreground()const {return m_DialsForground;}
    QColor majorColor()const {return m_MajorColor;}
    QColor minorColor()const {return m_MinorColor;}
    QColor outerCircleColor()const {return m_OuterCircleColor;}
    QColor interCircleColor()const {return m_InterCircleColor; }
    QColor needleColor()const {return m_NeedlesColor;}
    QColor needlesFillColor()const {return  m_NeedleFillColor;}
    QColor pivotPointColor()const {return m_PivotColor; }

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void paintEvent(QPaintEvent *);
    virtual void moveEvent(QMoveEvent *);
    virtual void recalculate(void);
    inline int _Min(int a, int b) { int Answer=a; if (a > b) Answer=b; return Answer; }
    inline int _Max(int a, int b) { int Answer=a; if (a < b) Answer=b; return Answer; }

private:
    QPainter * Painter;
    QRect * DialsBox;
    QColor m_DialsBackground;
    QColor m_DialsForground;
    QColor m_MajorColor;
    QColor m_MinorColor;
    QColor m_OuterCircleColor;
    QColor m_InterCircleColor;
    QPointF NeedlesPoint;
    QColor m_NeedlesColor;
    QColor m_NeedleFillColor;
    QColor m_PivotColor;
    QRect DisplayBox;
    QPolygon Needle;
    QBrush * NeedlesBrush; // NeedlesBrush is used if and only if UseGradient is false
    QLinearGradient * NeedlesGradient; // NeedlesGradient is used if and only if UseGradient is true
    QString * DialsName;

    // Boundry items: Size and shape for control
    int m_Controls_X;
    int m_Controls_Y;
    int m_ControlsDiameter;
    // Margin variables for plament of Dial control
    int _Margin;
    int m_DialsOffset;
    int m_DialsRadias;
    int m_OuterRadius;
    int m_InterRadius;
    // Major and Minor configuration variables
    int m_MajorInterval;
    int m_MajorOver;
    int m_MajorUnder;
    int m_MinorInterval;
    int m_MinorOver;
    int m_MinorUnder;
    int m_TextsOffset;
    int m_OuterCircleThickness;
    int m_InterCircleThickness;
    // Needle Variables
    int _NeedlePoints[10];
    int m_NeedleWidth;
    bool m_UseGradient;
    // Fundamental items for Dial
    double m_Value;
    double m_MaxValue;
    //double m_AngleOffset;
    bool m_DrawOuterCircle;
    bool m_DrawInterCircle;
    // Calculated variables
    double _DisplayBoxSpan;
    double _NeedleLocationPercent;
    double _NeedleSpan;

    QPaintEvent * EDummy;

    static const int QtScaleFactor = 16; // Angles in Qt must be specified in 1/16th of a degree. 3 o'clock is zero degrees

    double ComputePositionPoint(double);
};

#endif // QCDial_H
