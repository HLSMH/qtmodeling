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
#include "umlliteralunlimitednatural_p.h"

/*!
    \class UmlLiteralUnlimitedNatural

    \inmodule QtUml

    \brief A literal unlimited natural is a specification of an unlimited natural number.
 */

UmlLiteralUnlimitedNatural::UmlLiteralUnlimitedNatural() :
    _value(0)
{
}

// OWNED ATTRIBUTES

/*!
    The specified UnlimitedNatural value.
 */
int UmlLiteralUnlimitedNatural::value() const
{
    // This is a read-write property

    return _value;
}

void UmlLiteralUnlimitedNatural::setValue(int value)
{
    // This is a read-write property

    if (_value != value) {
        _value = value;
    }
}

// OPERATIONS

/*!
    The query isComputable() is redefined to be true.
 */
bool UmlLiteralUnlimitedNatural::isComputable(
    ) const
{
    qWarning("UmlLiteralUnlimitedNatural::isComputable(): to be implemented (operation)");

    return bool ();
}

/*!
    The query unlimitedValue() gives the value.
 */
int UmlLiteralUnlimitedNatural::unlimitedValue(
    ) const
{
    qWarning("UmlLiteralUnlimitedNatural::unlimitedValue(): to be implemented (operation)");

    return int ();
}
