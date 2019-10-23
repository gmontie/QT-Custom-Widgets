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
#include "QCDial.h"
#include "QCDialPlugin.h"

#include <QtPlugin>

QCDialPlugin::QCDialPlugin(QObject* parent) : QObject(parent), initialized(false)
{
}

QString QCDialPlugin::name() const
{
    return "QCDial";
}

QString QCDialPlugin::group() const
{
    return tr("glm Cutsom Widgets");
}

QString QCDialPlugin::toolTip() const
{
    return tr("QCDial");
}

QString QCDialPlugin::whatsThis() const
{
    return tr("QCDial");
}

QString QCDialPlugin::includeFile() const
{
    return "QCDial.h";
}

QIcon QCDialPlugin::icon() const
{
	return QIcon();
}

bool QCDialPlugin::isContainer() const
{
	return false;
}

QWidget * QCDialPlugin::createWidget(QWidget * Parent)
{
    return new QCDial(Parent);
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(QCDialPlugin, QCDialPlugin)
#endif
