/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "QMeter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMeter *qmeter;
    QMeter *qmeter_2;
    QMeter *qmeter_3;
    QMeter *qmeter_4;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *verticalSlider;
    QDial *dial;
    QPushButton *ExitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 696);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        qmeter = new QMeter(centralwidget);
        qmeter->setObjectName(QString::fromUtf8("qmeter"));
        qmeter->setGeometry(QRect(0, 0, 231, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(7);
        font.setItalic(false);
        qmeter->setFont(font);
        qmeter->setTextsOffset(23);
        qmeter->setProperty("arcThickness", QVariant(3));
        qmeter->setBackground(QColor(255, 255, 255));
        qmeter->setForeground(QColor(0, 0, 0));
        qmeter->setMajorColor(QColor(0, 0, 0));
        qmeter->setProperty("arcColor", QVariant(QColor(0, 0, 0)));
        qmeter->setProperty("needleColor", QVariant(QColor(0, 0, 0)));
        qmeter->setNeedlesFillColor(QColor(128, 128, 128));
        qmeter->setPivotPointColor(QColor(0, 0, 255));
        qmeter_2 = new QMeter(centralwidget);
        qmeter_2->setObjectName(QString::fromUtf8("qmeter_2"));
        qmeter_2->setGeometry(QRect(360, 10, 331, 211));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Droid Sans Thai"));
        font1.setPointSize(8);
        qmeter_2->setFont(font1);
        qmeter_2->setTextsOffset(48);
        qmeter_2->setProperty("arcThickness", QVariant(2));
        qmeter_2->setProperty("majorInterval", QVariant(10));
        qmeter_2->setProperty("majorOver", QVariant(0));
        qmeter_2->setNeedlesWidth(7);
        qmeter_2->setUseGradient(false);
        qmeter_2->setMaximum(100);
        qmeter_2->setProperty("needleColor", QVariant(QColor(0, 128, 0)));
        qmeter_2->setNeedlesFillColor(QColor(192, 0, 3));
        qmeter_2->setPivotPointColor(QColor(255, 255, 255));
        qmeter_3 = new QMeter(centralwidget);
        qmeter_3->setObjectName(QString::fromUtf8("qmeter_3"));
        qmeter_3->setGeometry(QRect(10, 240, 300, 101));
        qmeter_3->setProperty("majorOver", QVariant(7));
        qmeter_3->setProperty("majorUnder", QVariant(0));
        qmeter_3->setProperty("minorInterval", QVariant(4));
        qmeter_3->setProperty("minorOver", QVariant(10));
        qmeter_3->setProperty("minorUnder", QVariant(0));
        qmeter_3->setNeedlesWidth(3);
        qmeter_3->setUseGradient(false);
        qmeter_3->setMaximum(7);
        qmeter_3->setOffsetAngle(45);
        qmeter_3->setDrawArc(false);
        qmeter_3->setBackground(QColor(0, 46, 0));
        qmeter_3->setForeground(QColor(255, 0, 0));
        qmeter_3->setProperty("needleColor", QVariant(QColor(255, 255, 255)));
        qmeter_3->setNeedlesFillColor(QColor(255, 255, 255));
        qmeter_4 = new QMeter(centralwidget);
        qmeter_4->setObjectName(QString::fromUtf8("qmeter_4"));
        qmeter_4->setGeometry(QRect(330, 290, 441, 271));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yudit"));
        font2.setItalic(true);
        qmeter_4->setFont(font2);
        qmeter_4->setValue(42);
        qmeter_4->setTextsOffset(77);
        qmeter_4->setProperty("arcThickness", QVariant(7));
        qmeter_4->setProperty("majorOver", QVariant(0));
        qmeter_4->setProperty("majorUnder", QVariant(30));
        qmeter_4->setProperty("minorInterval", QVariant(2));
        qmeter_4->setProperty("minorOver", QVariant(0));
        qmeter_4->setNeedlesWidth(20);
        qmeter_4->setProperty("minimum", QVariant(35));
        qmeter_4->setMaximum(60);
        qmeter_4->setOffsetAngle(10);
        qmeter_4->setBackground(QColor(0, 0, 93));
        qmeter_4->setMajorColor(QColor(0, 255, 255));
        qmeter_4->setMinorColor(QColor(255, 255, 0));
        qmeter_4->setProperty("arcColor", QVariant(QColor(0, 192, 0)));
        qmeter_4->setProperty("needleColor", QVariant(QColor(0, 0, 0)));
        qmeter_4->setNeedlesFillColor(QColor(88, 88, 88));
        qmeter_4->setPivotPointColor(QColor(0, 179, 0));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 360, 160, 16));
        QPalette palette;
        QBrush brush(QColor(0, 64, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        horizontalSlider->setPalette(palette);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(330, 570, 441, 21));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(700, 10, 16, 211));
        QPalette palette1;
        QBrush brush1(QColor(128, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        verticalSlider->setPalette(palette1);
        verticalSlider->setOrientation(Qt::Vertical);
        dial = new QDial(centralwidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(230, 100, 50, 51));
        QPalette palette2;
        QBrush brush2(QColor(0, 6, 65, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(0, 128, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush6(QColor(11, 14, 23, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        dial->setPalette(palette2);
        dial->setAutoFillBackground(true);
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(20, 600, 94, 29));
        QPalette palette3;
        QBrush brush7(QColor(64, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(157, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush8);
        QBrush brush9(QColor(0, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        ExitButton->setPalette(palette3);
        ExitButton->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 815, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        qmeter->setTitle(QApplication::translate("MainWindow", "Volts", 0, QApplication::UnicodeUTF8));
        qmeter_2->setTitle(QApplication::translate("MainWindow", "Speed", 0, QApplication::UnicodeUTF8));
        qmeter_3->setTitle(QApplication::translate("MainWindow", "Amps", 0, QApplication::UnicodeUTF8));
        qmeter_4->setTitle(QApplication::translate("MainWindow", "P. S. I.", 0, QApplication::UnicodeUTF8));
        ExitButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
