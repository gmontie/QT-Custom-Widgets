#include "QMeter.h"
#include <QtGui/QPainter>
#include <cmath>

/*-------------------------------------------------------------------------*/
QMeter::QMeter(QWidget *parent)  : QWidget(parent)
{
    NeedlesBrush = 0; // NeedlesBrush is used if and only if UseGradient is false
    NeedlesGradient = 0; // NeedlesGradient is used if and only if UseGradient is true
    MetersBox = 0;
    Painter = 0;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    MetersName = new QString("Meter");
    m_Controls_X = 0;
    m_Controls_Y = 0;
    m_Controls_Hight = 200; // In Pixels
    m_Controls_Width = 300; // In Pixels
    setGeometry(m_Controls_X, m_Controls_Y, m_Controls_Width, m_Controls_Hight);
    m_AngleOffset = 30.0;
    m_MinValue = 0; // Starting Scale Value
    m_Value = 0; // Current Value
    _Margin = 30;
    m_MetersOffset = 40;
    m_MaxValue = 10.0; // Scales Ending Value
    m_NeedleWidth = 10;
    m_TextsOffset = 40;
    m_ArcThickness = 1;

    m_MajorOver = 5;
    m_MajorUnder = 20;
    m_MinorOver = 3;
    m_MinorUnder = 10;

    m_MajorInterval = 1;
    m_MinorInterval = 5;
    m_UseGradient = true;
    m_DrawArch = true;
    m_MajorColor = Qt::red;
    m_MinorColor = Qt::gray;
    m_MetersForground = Qt::white;
    m_MetersBackground = Qt::black;
    m_ArcColor = Qt::blue;
    m_NeedlesColor = Qt::blue;
    m_NeedleFillColor = Qt::gray;
    m_PivotColor = Qt::yellow;

    recalculate();
}

/*-------------------------------------------------------------------------*/
QMeter::~QMeter()
{
    if(NeedlesBrush){delete NeedlesBrush; NeedlesBrush = 0;} // NeedlesBrush is used if and only if UseGradient is false
    if(NeedlesBrush){delete NeedlesGradient; NeedlesGradient = 0;} // NeedlesGradient is used if and only if UseGradient is true
    if(NeedlesBrush){delete MetersName; MetersName = 0;}
    if(MetersName != 0) {delete MetersName;}
    if(MetersBox != 0){ delete MetersBox; }
    if(Painter != 0){ delete Painter;}
}

/*-------------------------------------------------------------------------*/
void QMeter::resizeEvent(QResizeEvent *e)
{
    QRect Geometry= geometry();
    m_Controls_Hight = Geometry.height();
    m_Controls_Width = Geometry.width();
    recalculate();
    QWidget::resizeEvent(e);
}

/*-------------------------------------------------------------------------*/
void QMeter::moveEvent(QMoveEvent * e)
{
    QRect Geometry= geometry();
    m_Controls_Hight = Geometry.height();
    m_Controls_Width = Geometry.width();
    recalculate();
    QWidget::moveEvent(e);
}

/*-------------------------------------------------------------------------*/
QSize QMeter::sizeHint() const{return QSize(m_Controls_Width, m_Controls_Hight);}

/*-------------------------------------------------------------------------*/
QSize QMeter::minimumSizeHint() const{return QSize(m_Controls_Width, m_Controls_Hight);}

/*-------------------------------------------------------------------------*/
void QMeter::setArchThickness(int Value)
{
    m_ArcThickness = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setXOffset(int Value)
{
    m_Controls_X = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setYOffset(int Value)
{
    m_Controls_Y = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setTextsOffset(int Value)
{
    m_TextsOffset = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setBackground(const QColor Value)
{
    m_MetersBackground = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setForeground(const QColor Value)
{
    m_MetersForground = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMajorColor(const QColor Value)
{
    m_MajorColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMinorColor(const QColor Value)
{
    m_MinorColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setArcsColor(const QColor Value)
{
    m_ArcColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setNeedlesColor(const QColor Value)
{
    m_NeedlesColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setPivotPointColor(const QColor Value)
{
    m_PivotColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setTitle(char * Value)
{
    MetersName = new QString(Value);
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setTitle(QString Value)
{
    MetersName = new QString(Value);
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setValue(double Value)
{
    m_Value = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMajorsInterval(const int Value)
{
    m_MajorInterval = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMajorsOver(const int  Value)
{
    m_MajorOver = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMajorsUnder(const int Value)
{
    m_MajorUnder = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMinorsInterval(const int Value)
{
    m_MinorInterval = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMinorsOver(int const Value)
{
    m_MinorOver = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMinorsUnder(const int Value)
{
    m_MinorUnder = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setNeedlesWidth(const int Value)
{
    m_NeedleWidth = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMinValue(const double Value)
{
    m_MinValue = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setMaximum(const double Value)
{
    m_MaxValue = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setOffsetAngle(double const Value)
{
    m_AngleOffset = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::use_A_Gradient(const bool qValue)
{
    m_UseGradient = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setDrawArc(const bool qValue)
{
    m_DrawArch = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QMeter::setNeedlesFillColor(const QColor qValue)
{
    m_NeedleFillColor = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
int QMeter::heightForWidth(int newWidth) const
{
    double dWidth = 1.0 * m_Controls_Width;
    double dHieght = 1.0 * m_Controls_Hight;
    double Results = newWidth * dWidth/dHieght;
    return static_cast<int>(Results);
}

/*-------------------------------------------------------------------------*/
void QMeter::recalculate(void)
{
     if( m_Value < m_MinValue) m_Value = m_MinValue;
     if( m_Value > m_MaxValue) m_Value = m_MaxValue;
    _StartAngle = m_AngleOffset; // In Degrees
    _EndAngle = (180.0 - m_AngleOffset); // In Degrees not scaled
    _NeedleSpan = (180.0 - (2 * m_AngleOffset)); // In Degrees not scaled
    _SpanValue = m_MaxValue - m_MinValue;
    DisplayBox.setCoords(m_Controls_X, m_Controls_Y, m_Controls_Width, m_Controls_Hight);
    _DisplayBoxSpan = m_Controls_Hight - m_Controls_Y;
    int StartX = (m_Controls_X + _Margin);
    int StartY = (m_Controls_Y + m_MetersOffset);

    int MetersLength = m_Controls_Width - (2 * _Margin);

    m_MetersRadias = MetersLength / 2;
    MetersBox = new QRect(StartX, StartY, MetersLength, StartY + (MetersLength - m_MetersOffset));

    NeedlesPoint.setX(m_MetersRadias + MetersBox->topLeft().x());
    NeedlesPoint.setY(StartY +  m_MetersRadias);

    int PointList[] = {
        -20, -((m_NeedleWidth/2) - 1),
        0, -(m_NeedleWidth / 2),
        (m_MetersRadias - (m_NeedleWidth / 2)), 0,
        0, (m_NeedleWidth / 2),
        -20, ((m_NeedleWidth/2) - 1)
    };

    for(int i = 0; i < 10; i++) _NeedlePoints[i] = PointList[i];
    NeedlesBrush = new QBrush(m_NeedleFillColor, Qt::SolidPattern);
    NeedlesGradient = new QLinearGradient(0, (-(m_NeedleWidth / 2) - 3), 0, ((m_NeedleWidth / 2) + 3));
    NeedlesGradient->setColorAt(0, m_NeedlesColor);
    NeedlesGradient->setColorAt(0.5, m_NeedleFillColor);
    NeedlesGradient->setColorAt(1, m_NeedlesColor);
}

/*-------------------------------------------------------------------------*/
void QMeter::paintEvent(QPaintEvent *e)
{
    EDummy = e;
    Painter = new QPainter(this);
    QPen TextPen(m_MetersForground); // default forground color is what for white on black scheme
    QPen ArcsPen(m_ArcColor);
    QPen NeedlesPen(m_NeedlesColor);
    QPen MajorPen(m_MajorColor);
    QPen MinorPen(m_MinorColor);
    QPen PivotPen(m_PivotColor);
    double PositionPoint;
    double MinorStepSize = (m_MajorInterval * 1.0) / (m_MinorInterval * 1.0);
    double i;
    double j;

    //--------------------  Fill Meter background ----------------------
    Painter->setRenderHint(QPainter::Antialiasing, true);
    // The default background color is black for white on black scheme.
    Painter->fillRect(DisplayBox, m_MetersBackground);
    // NOTE: MetersForground color is the color of the TextPen
    Painter->setPen(TextPen);
    // Display the name of the Meter
    Painter->drawText(DisplayBox, Qt::AlignBottom | Qt::AlignCenter, *MetersName);
    Painter->drawRect(DisplayBox);

//#define DEBUG_METER_LOCATON 1
#ifdef DEBUG_METER_LOCATON
    // Draw Meters Box area
    QPen DrawPen(Qt::yellow);
    Painter->setPen(DrawPen);
    Painter->drawRect(*MetersBox);
    QPoint p(static_cast<int>(NeedlesPoint.x()), static_cast<int>(NeedlesPoint.y()));
    DrawPen.setColor(Qt::red);
    Painter->setPen(DrawPen);
    Painter->drawEllipse(p, m_MetersRadias, m_MetersRadias);
#endif

    if(m_DrawArch)
    {
        //--------------------  Adjust angles by Qt's Scaling factor ----------------------
        int ScaledStart = static_cast<int>(_StartAngle * QtScaleFactor);
        int ScaledSpan = static_cast<int>(_NeedleSpan * QtScaleFactor);
        //-------------------- Draw Arc for Meter ----------------------
        ArcsPen.setWidth(m_ArcThickness);
        Painter->setPen(ArcsPen); // Set the color via setting the Pen
        Painter->drawArc(*MetersBox, ScaledStart, ScaledSpan); // Draw the arch
    }

    //--------------------  Draw Steps ----------------------
    // This algorithm to draw the steps is very similar the the way the needle is
    // drawn. The percentage of the arch (as if it's a streight line) is computed
    // and then used to rotate around the Needles/Meters pivot point. At each
    // major interval where a tick line is to be drawn text is drawn for the major
    // interval. Minor Intervals are drawn for each space between the major tick
    // just draw to just before the next major tick is to be drawn.
    //
    // By the way this circumvents the need to explicitly use trig functionality
    //
    for(i = m_MinValue; i <= m_MaxValue; i += m_MajorInterval)
    {
       Painter->translate(NeedlesPoint); // Set relative Qt coordinates
       PositionPoint = ComputePositionPoint(i);
       Painter->rotate( PositionPoint ); // Rotate around to we get to where the line needs to be drawn.
       // Draw text for major tick lines
       Painter->setPen(TextPen);
       QRect TempRec(( m_MetersRadias - m_TextsOffset), -10, m_MetersRadias, 20); // Todo: use font metrics here
       Painter->drawText(TempRec, Qt::AlignBottom | Qt::AlignCenter, QString::number(i, 'f', 1));
       // Now set things up to draw the major tick lines
       Painter->setPen(MajorPen); // Set color for Major tick lines via MajorPen
       // The Meters radis is from the needles pivot point out to the actual locaton of the
       // arch. So we draw from above the arch (MetersRadias + Major points over meters arc) to
       // (MetersRadias - Major points under the arc). The same is done for the minor tick
       // lines
       Painter->drawLine((m_MetersRadias - m_MajorUnder), 0, (m_MetersRadias + m_MajorOver), 0);
       // If there are more minor tick lines to draw
       if( i + MinorStepSize < static_cast<int>(m_MaxValue))
       {
           Painter->setPen(MinorPen); // Set the minor tick color via MinorPen
           // For each minor tick line in between the major line, just drawn
           // and the next major tick line draw each minor tick line
           for(j = (i + MinorStepSize); j < (i + m_MajorInterval); j += MinorStepSize)
           {   // Reset everything
               Painter->resetMatrix();
               Painter->translate(NeedlesPoint); // Retranslate Qt coordinates
               PositionPoint = ComputePositionPoint(j); // Computer the new position
               Painter->rotate( PositionPoint ); // Rotate to the new position
               // Draw the minor tick line
               Painter->drawLine((m_MetersRadias - m_MinorUnder), 0, (m_MetersRadias + m_MinorOver), 0);
           }
       }
       Painter->resetMatrix(); // Start with a fresh point of reference.
    }

    //-------------------- Draw the Needle ----------------------
    // Set Qt coordinates relative to center of point of meter where the needle's pivot point is
    PositionPoint = ComputePositionPoint(m_Value);
    Needle.setPoints(5, _NeedlePoints); // Setup point list for polygone which is the needle
    NeedlesPen.setWidth(1); // Draw with line width of 1
    NeedlesPen.setCapStyle(Qt::FlatCap); // Endcaps for lines are to be flat
    Painter->setPen(NeedlesPen); // Set the Pen to use for painting the needle
    // Select whether to use a Linear Gradient or a Brush
    if(m_UseGradient)
        Painter->setBrush(*NeedlesGradient);
    else
        Painter->setBrush(*NeedlesBrush);
    // Adjust Qt coordinates to needles pivot point
    Painter->translate(NeedlesPoint); // Translate Qt's coordinate system relative to the needles pivot point
    Painter->rotate( PositionPoint ); // Rotate around to the correct position
    Painter->drawConvexPolygon(Needle); // Draw the needle
    Painter->drawLine(0, 0, m_MetersRadias, 0); // Draw center line of needle
    Painter->resetMatrix(); // Reset everything to the next step

    //--------------------  Draw Needles pivot point ----------------------
    PivotPen.setWidth(m_NeedleWidth + 2);
    PivotPen.setCapStyle(Qt::RoundCap);
    Painter->setPen(PivotPen);
    Painter->drawPoint(NeedlesPoint);
    NeedlesPen.setWidth((m_NeedleWidth / 2));
    NeedlesPen.setCapStyle(Qt::RoundCap);
    Painter->setPen(NeedlesPen);
    Painter->drawPoint(NeedlesPoint);
}

/*-------------------------------------------------------------------------*/
//  The percent that Value is over the complete range between
//  MinValue and MaxValue
//  PercentValue = (Value - MinValue) / (MaxValue - MinValue)
//
//  Total Degrees of Span
// NeedleSpan
//
//    The Percent of Degrees from the very left of the
// scale to where the Needle should be is:
// NeedlesEndPoint = NeedleSpan * PercentValue
//
//   Now adjust so that the Needles End Point is mapped onto
// Qt's coordinate system. The -EndAngle is the start of
// the scale so
//  RotateAngle = -EndAngle + NeedlesEndPoint
double QMeter::ComputePositionPoint(double PositionValue)
{
    //  The percent that Value is over the complete range between
    //  MinValue and MaxValue
    double  PercentValue = (PositionValue - m_MinValue) / (m_MaxValue - m_MinValue);
    //
    //  Total Degrees of Span
    // NeedleSpan
    //
    //    The Percent of Degrees from the very left of the
    // scale to where the Needle should be is:
    double NeedlesEndPoint = _NeedleSpan * PercentValue ;
    //
    //   Now adjust so that the Needles End Point is mapped onto
    // Qt's coordinate system. The -EndAngle is the start of
    // the scale so
    //double RotateAngle = -EndAngle + NeedlesEndPoint;
    return (-_EndAngle + NeedlesEndPoint);
}
