/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "umlprofile_p.h"

#include "private/umlelementimport_p.h"
#include "private/umlpackageimport_p.h"

/*!
    \class UmlProfile

    \inmodule QtUml

    \brief A profile defines limited extensions to a reference metamodel with the purpose of adapting the metamodel to a specific platform or domain.
 */

UmlProfile::UmlProfile()
{
}

// OWNED ATTRIBUTES

/*!
    References a metaclass that may be extended.
 */
const QSet<UmlElementImport *> UmlProfile::metaclassReference() const
{
    // This is a read-write association end

    return _metaclassReference;
}

void UmlProfile::addMetaclassReference(UmlElementImport *metaclassReference)
{
    // This is a read-write association end

    if (!_metaclassReference.contains(metaclassReference)) {
        _metaclassReference.insert(metaclassReference);

        // Adjust subsetted properties
        addElementImport(metaclassReference);
    }
}

void UmlProfile::removeMetaclassReference(UmlElementImport *metaclassReference)
{
    // This is a read-write association end

    if (_metaclassReference.contains(metaclassReference)) {
        _metaclassReference.remove(metaclassReference);

        // Adjust subsetted properties
        removeElementImport(metaclassReference);
    }
}

/*!
    References a package containing (directly or indirectly) metaclasses that may be extended.
 */
const QSet<UmlPackageImport *> UmlProfile::metamodelReference() const
{
    // This is a read-write association end

    return _metamodelReference;
}

void UmlProfile::addMetamodelReference(UmlPackageImport *metamodelReference)
{
    // This is a read-write association end

    if (!_metamodelReference.contains(metamodelReference)) {
        _metamodelReference.insert(metamodelReference);

        // Adjust subsetted properties
        addPackageImport(metamodelReference);
    }
}

void UmlProfile::removeMetamodelReference(UmlPackageImport *metamodelReference)
{
    // This is a read-write association end

    if (_metamodelReference.contains(metamodelReference)) {
        _metamodelReference.remove(metamodelReference);

        // Adjust subsetted properties
        removePackageImport(metamodelReference);
    }
}
