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
