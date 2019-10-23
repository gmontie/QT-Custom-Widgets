#include "QMeter.h"
#include "QMeterPlugin.h"

#include <QtPlugin>

QMeterPlugin::QMeterPlugin(QObject* parent) : QObject(parent), initialized(false)
{
}

QString QMeterPlugin::name() const
{
    return "QMeter";
}

QString QMeterPlugin::group() const
{
    return tr("glm Cutsom Widgets");
}

QString QMeterPlugin::toolTip() const
{
    return tr("QMeter");
}

QString QMeterPlugin::whatsThis() const
{
    return tr("QMeter");
}

QString QMeterPlugin::includeFile() const
{
    return "QMeter.h";
}

QIcon QMeterPlugin::icon() const
{
	return QIcon();
}

bool QMeterPlugin::isContainer() const
{
	return false;
}

QWidget * QMeterPlugin::createWidget(QWidget * Parent)
{
    return new QMeter(Parent);
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(QMeterplugin, QMeterPlugin)
#endif
