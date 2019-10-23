#include "QTitle.h"
#include "QTitlePlugin.h"

#include <QtPlugin>

QTitlePlugin::QTitlePlugin(QObject* parent) :	QObject(parent), initialized(false)
{
}

QString QTitlePlugin::name() const
{
    return "QTitle";
}

QString QTitlePlugin::group() const
{
    return tr("glm Cutsom Widgets");
}

QString QTitlePlugin::toolTip() const
{
    return tr("QTitle");
}

QString QTitlePlugin::whatsThis() const
{
    return tr("QTitle");
}

QString QTitlePlugin::includeFile() const
{
    return "QTitle.h";
}

QIcon QTitlePlugin::icon() const
{
	return QIcon();
}

bool QTitlePlugin::isContainer() const
{
    return true;
}

QWidget * QTitlePlugin::createWidget(QWidget * Parent)
{
    return new QTitle(Parent);
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
Q_EXPORT_PLUGIN2(QTitleplugin, QTitlePlugin)
#endif
