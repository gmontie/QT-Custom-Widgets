#ifndef QMETER_H
#define QMETER_H

#include <QtDesigner/QtDesigner>
#include <QWidget>
#include <QColor>

class QDESIGNER_WIDGET_EXPORT QMeter : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString Title READ Title WRITE setTitle)
    Q_PROPERTY(double value READ value WRITE setValue)
    Q_PROPERTY(int Xoffset READ Xoffset WRITE setXOffset)
    Q_PROPERTY(int Yoffset READ Yoffset WRITE setYOffset)
    Q_PROPERTY(int textsOffset READ textsOffset WRITE setTextsOffset)
    Q_PROPERTY(int arcThickness READ arcThickness WRITE setArchThickness)
    Q_PROPERTY(int majorInterval READ majorInterval WRITE setMajorsInterval)
    Q_PROPERTY(int majorOver READ majorOver WRITE setMajorsOver)
    Q_PROPERTY(int majorUnder READ majorUnder WRITE setMajorsUnder)
    Q_PROPERTY(int minorInterval READ minorInterval WRITE setMinorsInterval)
    Q_PROPERTY(int minorOver READ minorOver WRITE setMinorsOver)
    Q_PROPERTY(int minorUnder READ minorUnder WRITE setMinorsUnder)
    // Needle Variables
    Q_PROPERTY(int NeedlesWidth READ needleWidth WRITE setNeedlesWidth)
    // Fundamental items for Meter
    Q_PROPERTY(double minimum READ minimum WRITE setMinValue)
    Q_PROPERTY(double maximum READ maximum WRITE setMaximum)
    Q_PROPERTY(double offsetAngle READ offsetAngle WRITE setOffsetAngle)
    // Color layout for Meter
    Q_PROPERTY(QColor background READ background WRITE setBackground)
    Q_PROPERTY(QColor foreground READ foreground WRITE setForeground)
    Q_PROPERTY(QColor majorColor READ majorColor WRITE setMajorColor)
    Q_PROPERTY(QColor minorColor READ minorColor WRITE setMinorColor)
    Q_PROPERTY(QColor arcColor READ arcColor WRITE setArcsColor)
    Q_PROPERTY(QColor needleColor READ needleColor WRITE setNeedlesColor)
    Q_PROPERTY(QColor pivotPointColor READ pivotPointColor WRITE setPivotPointColor)

    Q_PROPERTY(bool useGradient READ useGradient WRITE use_A_Gradient)
    Q_PROPERTY(bool drawArc READ drawArc WRITE setDrawArc)
    Q_PROPERTY(QColor needlesFillColor READ needlesFillColor WRITE setNeedlesFillColor)

public:
    explicit QMeter(QWidget * parent=0);
    ~QMeter();
    void use_A_Gradient(const bool qValue);
    void setDrawArc(const bool qValue);
    void setNeedlesFillColor(const QColor qValue);
    void setTextsOffset(int);
    void setXOffset(int);
    void setYOffset(int);
    void setArchThickness(int);
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
    void setMinValue(const double);
    void setMaximum(const double);
    void setOffsetAngle(const double);
    void setBackground(const QColor);
    void setForeground(const QColor);
    void setMajorColor(const QColor);
    void setMinorColor(const QColor);
    void setArcsColor(const QColor);
    void setNeedlesColor(const QColor);
    void setPivotPointColor(const QColor);
    int heightForWidth(int width) const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    int Xoffset()const{return m_Controls_X;}
    int Yoffset()const{return m_Controls_Y;}
    int textsOffset()const{return m_TextsOffset;}
    int arcThickness()const{return m_ArcThickness;}
    QString Title()const{ return *MetersName; }
    double value()const { return m_Value; }
    int majorInterval()const{ return m_MajorInterval; }
    int majorOver()const {return m_MajorOver;}
    int majorUnder()const {return m_MajorUnder;}
    int minorInterval()const {return m_MinorInterval;}
    int minorOver()const {return  m_MinorOver;}
    int minorUnder()const {return m_MinorUnder;}
    int needleWidth() const {return m_NeedleWidth;}
    bool useGradient()const {return m_UseGradient;}
    double minimum()const{return m_MinValue;}
    double maximum()const{ return m_MaxValue; }
    double offsetAngle()const {return m_AngleOffset;}
    bool drawArc()const { return m_DrawArch;}
    bool userGradient()const {return m_UseGradient;}
    QColor background()const {return m_MetersBackground; }
    QColor foreground()const {return m_MetersForground;}
    QColor majorColor()const {return m_MajorColor;}
    QColor minorColor()const {return m_MinorColor;}
    QColor arcColor()const {return  m_ArcColor;}
    QColor needleColor()const {return m_NeedlesColor;}
    QColor needlesFillColor()const {return  m_NeedleFillColor;}
    QColor pivotPointColor()const {return m_PivotColor; }

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void paintEvent(QPaintEvent *);
    virtual void moveEvent(QMoveEvent *);
    virtual void recalculate(void);

private:
    QPainter * Painter;
    QRect * MetersBox;
    QColor m_MetersBackground;
    QColor m_MetersForground;
    QColor m_MajorColor;
    QColor m_MinorColor;
    QColor m_ArcColor;
    QPointF NeedlesPoint;
    QColor m_NeedlesColor;
    QColor m_NeedleFillColor;
    QColor m_PivotColor;
    QRect DisplayBox;
    QPolygon Needle;
    QBrush * NeedlesBrush; // NeedlesBrush is used if and only if UseGradient is false
    QLinearGradient * NeedlesGradient; // NeedlesGradient is used if and only if UseGradient is true
    QString * MetersName;

    // Boundry items: Size and shape for control
    int m_Controls_X;
    int m_Controls_Y;
    int m_Controls_Hight;
    int m_Controls_Width;
    // Margin variables for plament of Meter control
    int _Margin;
    int m_MetersOffset;
    int m_MetersRadias;
    // Major and Minor configuration variables
    int m_MajorInterval;
    int m_MajorOver;
    int m_MajorUnder;
    int m_MinorInterval;
    int m_MinorOver;
    int m_MinorUnder;
    int m_TextsOffset;
    int m_ArcThickness;
    // Needle Variables
    int _NeedlePoints[10];
    int m_NeedleWidth;
    bool m_UseGradient;
    // Fundamental items for Meter
    double m_Value;
    double m_MinValue;
    double m_MaxValue;
    double m_AngleOffset;
    bool m_DrawArch;
    // Calculated variables
    double _DisplayBoxSpan;
    double _NeedleLocationPercent;
    double _StartAngle;
    double _EndAngle;
    double _NeedleSpan;
    double _SpanValue;

    QPaintEvent * EDummy;

    static const int QtScaleFactor = 16; // Angles in Qt must be specified in 1/16th of a degree. 3 o'clock is zero degrees

    double ComputePositionPoint(double);
};

#endif // QMeter_H
