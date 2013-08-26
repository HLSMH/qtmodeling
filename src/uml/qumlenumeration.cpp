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
#include "qumlenumeration.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlEnumerationLiteral>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlEnumeration

    \inmodule QtUml

    \brief An enumeration is a data type whose values are enumerated in the model as enumeration literals.
 */

QUmlEnumeration::QUmlEnumeration()
{
    d_ptr->object.setProperty("ownedLiteral", QVariant::fromValue(&_ownedLiteral));
}

// OWNED ATTRIBUTES

/*!
    The ordered set of literals for this Enumeration.
 */
QList<QUmlEnumerationLiteral *> QUmlEnumeration::ownedLiteral() const
{
    // This is a read-write association end

    return _ownedLiteral;
}

void QUmlEnumeration::addOwnedLiteral(QUmlEnumerationLiteral *ownedLiteral)
{
    // This is a read-write association end

    if (!_ownedLiteral.contains(ownedLiteral)) {
        _ownedLiteral.append(ownedLiteral);

        // Adjust subsetted properties
        addOwnedMember(ownedLiteral);

        // Adjust opposite properties
        if (ownedLiteral) {
            ownedLiteral->setEnumeration(this);
        }
    }
}

void QUmlEnumeration::removeOwnedLiteral(QUmlEnumerationLiteral *ownedLiteral)
{
    // This is a read-write association end

    if (_ownedLiteral.contains(ownedLiteral)) {
        _ownedLiteral.removeAll(ownedLiteral);

        // Adjust subsetted properties
        removeOwnedMember(ownedLiteral);

        // Adjust opposite properties
        if (ownedLiteral) {
            ownedLiteral->setEnumeration(0);
        }
    }
}

QT_END_NAMESPACE

