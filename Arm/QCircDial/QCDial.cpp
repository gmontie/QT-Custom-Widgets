#include "QCDial.h"
#include <QtGui/QPainter>
#include <cmath>

/*-------------------------------------------------------------------------*/
QCDial::QCDial(QWidget *parent)  : QWidget(parent)
{
    NeedlesBrush = 0; // NeedlesBrush is used if and only if UseGradient is false
    NeedlesGradient = 0; // NeedlesGradient is used if and only if UseGradient is true
    DialsBox = 0;
    Painter = 0;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont f( "DejaVu Sans", 8, QFont::Condensed);
    this->setFont(f);

    DialsName = new QString("Dial");
    m_Controls_X = -1;
    m_Controls_Y = -5;
    m_ControlsDiameter = 225; // In Pixels
    setGeometry(m_Controls_X, m_Controls_Y, m_ControlsDiameter, m_ControlsDiameter);
    m_MaxValue = 360.0; // Scales Ending Value
    m_Value = 0; // Current Value
    _Margin = 30;
    m_OuterRadius = 101;
    m_InterRadius = 68;
    m_DialsOffset = 30;
    m_NeedleWidth = 10;
    m_TextsOffset = 65;
    m_OuterCircleThickness = 5;
    m_InterCircleThickness = 5;

    m_MajorOver = 5;
    m_MajorUnder = 20;
    m_MinorOver = 3;
    m_MinorUnder = 10;

    m_MajorInterval = 15;
    m_MinorInterval = 5;
    m_UseGradient = true;
    m_DrawOuterCircle = true;
    m_DrawInterCircle = true;
    m_MajorColor = Qt::magenta;
    m_MinorColor = Qt::gray;
    m_DialsForground = Qt::white;
    m_DialsBackground = Qt::black;
    m_OuterCircleColor = Qt::blue;
    m_InterCircleColor = Qt::white;
    m_NeedlesColor = QColor(90, 0, 0);
    m_NeedleFillColor = QColor(128, 128, 0);
    m_PivotColor = QColor(160, 160, 160);

    recalculate();
}

/*-------------------------------------------------------------------------*/
QCDial::~QCDial()
{
    if(NeedlesBrush){delete NeedlesBrush; NeedlesBrush = 0;} // NeedlesBrush is used if and only if UseGradient is false
    if(NeedlesBrush){delete NeedlesGradient; NeedlesGradient = 0;} // NeedlesGradient is used if and only if UseGradient is true
    if(NeedlesBrush){delete DialsName; DialsName = 0;}
    if(DialsName != 0) {delete DialsName;}
    if(DialsBox != 0){ delete DialsBox; }
    if(Painter != 0){ delete Painter;}
}

/*-------------------------------------------------------------------------*/
void QCDial::resizeEvent(QResizeEvent *e)
{
    QRect Geometry= geometry();
    int m_Controls_Hight = Geometry.height();
    int m_Controls_Width = Geometry.width();
    m_ControlsDiameter=_Max(m_Controls_Hight ,m_Controls_Width);
    recalculate();
    QWidget::resizeEvent(e);
}

/*-------------------------------------------------------------------------*/
void QCDial::moveEvent(QMoveEvent * e)
{
    QRect Geometry= geometry();
    int m_Controls_Hight = Geometry.height();
    int m_Controls_Width = Geometry.width();
    m_ControlsDiameter=_Max(m_Controls_Hight ,m_Controls_Width);
    recalculate();
    QWidget::moveEvent(e);
}

/*-------------------------------------------------------------------------*/
QSize QCDial::sizeHint() const{return QSize(m_ControlsDiameter, m_ControlsDiameter);}

/*-------------------------------------------------------------------------*/
QSize QCDial::minimumSizeHint() const{return QSize(m_ControlsDiameter, m_ControlsDiameter);}

/*-------------------------------------------------------------------------*/
void QCDial::setOuterCircleThickness(int Value)
{
    m_OuterCircleThickness = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMaxValue(const double Value)
{
    m_MaxValue=Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setInterCircleThickness(int Value)
{
    m_InterCircleThickness = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setOuterRadius(const int Value)
{
    m_OuterRadius = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setInterRadius(const int Value)
{
    m_InterRadius = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setXOffset(int Value)
{
    m_Controls_X = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setYOffset(int Value)
{
    m_Controls_Y = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setTextsOffset(int Value)
{
    m_TextsOffset = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setBackground(const QColor Value)
{
    m_DialsBackground = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setForeground(const QColor Value)
{
    m_DialsForground = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMajorColor(const QColor Value)
{
    m_MajorColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMinorColor(const QColor Value)
{
    m_MinorColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setOuterCircleColor(const QColor Value)
{
    m_OuterCircleColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setInterCircleColor(const QColor Value)
{
    m_InterCircleColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setNeedlesColor(const QColor Value)
{
    m_NeedlesColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setPivotPointColor(const QColor Value)
{
    m_PivotColor = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setTitle(char * Value)
{
    DialsName = new QString(Value);
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setTitle(QString Value)
{
    DialsName = new QString(Value);
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setValue(double Value)
{
    m_Value = Value;
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMajorsInterval(const int Value)
{
    m_MajorInterval = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMajorsOver(const int  Value)
{
    m_MajorOver = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMajorsUnder(const int Value)
{
    m_MajorUnder = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMinorsInterval(const int Value)
{
    m_MinorInterval = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMinorsOver(int const Value)
{
    m_MinorOver = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setMinorsUnder(const int Value)
{
    m_MinorUnder = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setNeedlesWidth(const int Value)
{
    m_NeedleWidth = Value;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::use_A_Gradient(const bool qValue)
{
    m_UseGradient = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::drawOuterCircle(const bool qValue)
{
    m_DrawOuterCircle = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::drawInterCircle(const bool qValue)
{
    m_DrawInterCircle = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
void QCDial::setNeedlesFillColor(const QColor qValue)
{
    m_NeedleFillColor = qValue;
    recalculate();
    update();
}

/*-------------------------------------------------------------------------*/
int QCDial::heightForWidth(int newWidth) const
{
    double Results = m_ControlsDiameter * newWidth;
    return static_cast<int>(Results);
}

/*-------------------------------------------------------------------------*/
void QCDial::recalculate(void)
{
    DialsBox = new QRect();
    DisplayBox.setCoords(m_Controls_X, (m_Controls_Y + 5), m_ControlsDiameter, m_ControlsDiameter);
    _DisplayBoxSpan = m_ControlsDiameter - m_Controls_Y;
    int StartX = (m_Controls_X + _Margin);
    int StartY = (m_Controls_Y + m_DialsOffset);

    int DialsLength = m_ControlsDiameter - (2 * _Margin);
    m_DialsRadias = DialsLength / 2;
    if(DialsBox != 0){ delete DialsBox; }
    DialsBox = new QRect(StartX, StartY, DialsLength, StartY + (DialsLength - m_DialsOffset));

    NeedlesPoint.setX(m_DialsRadias + DialsBox->topLeft().x());
    NeedlesPoint.setY(StartY +  m_DialsRadias);

    int PointList[] = {
        -20, -((m_NeedleWidth/2) - 1),
        0, -(m_NeedleWidth / 2),
        (m_DialsRadias - (m_NeedleWidth / 2)), 0,
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
void QCDial::paintEvent(QPaintEvent *e)
{
    EDummy = e;
    Painter = new QPainter(this);
    QPen TextPen(m_DialsForground); // default forground color is what for white on black scheme
    QPen OCirclesPen(m_OuterCircleColor);
    QPen ICirclesPen(m_InterCircleColor);
    QPen NeedlesPen(m_NeedlesColor);
    QPen MajorPen(m_MajorColor);
    QPen MinorPen(m_MinorColor);
    QPen PivotPen(m_PivotColor);
    double PositionPoint;
    double MinorStepSize = (m_MajorInterval * 1.0) / (m_MinorInterval * 1.0);
    double i;
    double j;

    //--------------------  Fill Dial background ----------------------
    Painter->setRenderHint(QPainter::Antialiasing, true);
    // The default background color is black for white on black scheme.
    Painter->fillRect(DisplayBox, m_DialsBackground);
    // NOTE: DialsForground color is the color of the TextPen
    Painter->setPen(TextPen);
    // Display the name of the Dial
    Painter->drawText(DisplayBox, Qt::AlignBottom | Qt::AlignCenter, *DialsName);
    Painter->drawRect(DisplayBox);

//#define DEBUG_Dial_LOCATON 1
#ifdef DEBUG_Dial_LOCATON
    // Draw Dials Box area
    QPen DrawPen(Qt::yellow);
    Painter->setPen(DrawPen);
    Painter->drawRect(*DialsBox);
    QPoint p(static_cast<int>(NeedlesPoint.x()), static_cast<int>(NeedlesPoint.y()));
    DrawPen.setColor(Qt::red);
    Painter->setPen(DrawPen);
    Painter->drawEllipse(p, m_DialsRadias, m_DialsRadias);
#endif

    if(m_DrawOuterCircle)
    {
        //-------------------- Draw Circle for Dial ----------------------
        OCirclesPen.setWidth(m_OuterCircleThickness);
        Painter->setPen(OCirclesPen); // Set the color via setting the Pen
        Painter->drawEllipse(NeedlesPoint, m_OuterRadius, m_OuterRadius);
    }

    if(m_DrawInterCircle)
    {
        //-------------------- Draw Circle for Dial ----------------------
        ICirclesPen.setWidth(m_InterCircleThickness);
        Painter->setPen(ICirclesPen); // Set the color via setting the Pen
        Painter->drawEllipse(NeedlesPoint, m_InterRadius, m_InterRadius);
    }

    //--------------------  Draw Steps ----------------------
    // This algorithm to draw the steps is very similar the the way the needle is
    // drawn. The percentage of the Circleh (as if it's a streight line) is computed
    // and then used to rotate around the Needles/Dials pivot point. At each
    // major interval where a tick line is to be drawn text is drawn for the major
    // interval. Minor Intervals are drawn for each space between the major tick
    // just draw to just before the next major tick is to be drawn.
    //
    // By the way this circumvents the need to explicitly use trig functionality
    //
    for(i = 0; i < m_MaxValue; i += m_MajorInterval)
    {
       Painter->translate(NeedlesPoint); // Set relative Qt coordinates
       PositionPoint = ComputePositionPoint(i);
       Painter->rotate( PositionPoint ); // Rotate around to we get to where the line needs to be drawn.
       // Draw text for major tick lines
       Painter->setPen(TextPen);

       QRect TempRec(( m_DialsRadias - m_TextsOffset), -10, m_DialsRadias, 20); // Todo: use font metrics here
       Painter->drawText(TempRec, Qt::AlignBottom | Qt::AlignRight, QString::number(i, 'f', 0));
       // Now set things up to draw the major tick lines
       Painter->setPen(MajorPen); // Set color for Major tick lines via MajorPen
       // The Dials radis is from the needles pivot point out to the actual locaton of the
       // Circleh. So we draw from above the Circleh (DialsRadias + Major points over Dials Circle) to
       // (DialsRadias - Major points under the Circle). The same is done for the minor tick
       // lines
       Painter->drawLine((m_InterRadius - m_MajorUnder),
                         0,
                         (m_InterRadius + m_MajorOver),
                         0);
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
               Painter->drawLine((m_InterRadius - m_MinorUnder),
                                 0,
                                 (m_InterRadius + m_MinorOver),
                                 0);
           }
       }
       Painter->resetMatrix(); // Start with a fresh point of reference.

    }

    //-------------------- Draw the Needle ----------------------
    // Set Qt coordinates relative to center of point of Dial where the needle's pivot point is
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
    Painter->drawLine(0, 0, m_DialsRadias, 0); // Draw center line of needle
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
double QCDial::ComputePositionPoint(double PositionValue)
{
    double PercentValue = PositionValue / m_MaxValue;
    double NeedlesPosition = 360 * PercentValue;
    return NeedlesPosition;
}
