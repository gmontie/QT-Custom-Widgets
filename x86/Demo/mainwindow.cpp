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
#include "mainwindow.h"
#include "ui_demo.h"

#define PSI_HI 60.0
#define PSI_LO 35.0
#define AMPS 7.0
#define SPEED 120.0
#define VOLTS 9.0

/*-------------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*-------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*-------------------------------------------------------------------------*/
void MainWindow::PSI_slot1()
{
    double Percentage = static_cast<double>(ui->PSI_Slider->value())/ 100.0;
    QString s = QString::number(ui->PSI_Slider->value(), 10);
    ui->PSI_SliderLabel->setText(s);
    int MetersValue = static_cast<int>((Percentage * (PSI_HI - PSI_LO)) + PSI_LO);
    s = QString::number(MetersValue);
    ui->PSI_Label->setText(s);
    ui->PSI_Meter->setValue(MetersValue);
}

/*-------------------------------------------------------------------------*/
void MainWindow::Amps_slot1()
{
    double Percentage = static_cast<double>(ui->AmpsSlider->value())/ 100.0;
    QString s = QString::number(ui->AmpsSlider->value(),10);
    ui->AmpsSliderLabel->setText(s);
    int MetersValue = static_cast<int>(Percentage * AMPS);
    s = QString::number(MetersValue);
    ui->AmpsLabel->setText(s);
    ui->AmpsMeter->setValue(MetersValue);
}

/*-------------------------------------------------------------------------*/
void MainWindow::Volts_slot1()
{
    double Percentage = static_cast<double>(ui->VoltsSlider->value())/ 100.0;
    QString s = QString::number(ui->VoltsSlider->value(), 10);
    ui->VoltsSliderLabel->setText(s);
    int MetersValue = static_cast<int>(Percentage * VOLTS);
    s = QString::number(MetersValue);
    ui->VoltsLabel->setText(s);
    ui->VoltsMeter->setValue(MetersValue);
}

/*-------------------------------------------------------------------------*/
void MainWindow::Speed_slot1()
{
    double Percentage = static_cast<double>(ui->SpeedSlider->value())/ 100.0;
    QString s = QString::number(ui->SpeedSlider->value(), 10);
    ui->SpeedSliderLavel->setText(s);
    int MetersValue = static_cast<int>(Percentage * SPEED);
    s = QString::number(MetersValue);
    ui->SpeedLabel->setText(s);
    ui->SpeedMeter->setValue(MetersValue);
}
