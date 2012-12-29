/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia  LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QTMOF_QPACKAGEMERGE_H
#define QTMOF_QPACKAGEMERGE_H

#include <QtMof/QtMofGlobal>

// Base class includes
#include <QtMof/QDirectedRelationship>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTMOF

QT_MODULE(QtMof)

// Forward decls for function parameters
class QPackage;

class QPackageMergePrivate;

class Q_MOF_EXPORT QPackageMerge : public QDirectedRelationship
{
    Q_OBJECT

    Q_PROPERTY(QPackage * mergedPackage READ mergedPackage WRITE setMergedPackage)
    Q_PROPERTY(QPackage * receivingPackage READ receivingPackage WRITE setReceivingPackage)

    Q_DISABLE_COPY(QPackageMerge)
    Q_DECLARE_PRIVATE(QPackageMerge)

public:
    Q_INVOKABLE explicit QPackageMerge(QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
    virtual ~QPackageMerge();

    // Association ends from QPackageMerge
    Q_INVOKABLE QPackage *mergedPackage() const;
    Q_INVOKABLE void setMergedPackage(QPackage *mergedPackage);
    Q_INVOKABLE QPackage *receivingPackage() const;
    Q_INVOKABLE void setReceivingPackage(QPackage *receivingPackage);
    virtual void registerMetaTypes() const;

protected:
    explicit QPackageMerge(QPackageMergePrivate &dd, QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
};

QT_END_NAMESPACE_QTMOF

QT_END_HEADER

#endif // QTMOF_QPACKAGEMERGE_H

