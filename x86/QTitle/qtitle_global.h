#ifndef QTITLE_GLOBAL_H
#define QTITLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTITLE_LIBRARY)
#  define QTITLESHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTITLESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTITLE_GLOBAL_H
