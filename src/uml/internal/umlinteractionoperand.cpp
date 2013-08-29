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
#include "umlinteractionoperand_p.h"

#include "private/umlinteractionconstraint_p.h"

/*!
    \class UmlInteractionOperand

    \inmodule QtUml

    \brief An interaction operand is contained in a combined fragment. An interaction operand represents one operand of the expression given by the enclosing combined fragment.
 */

UmlInteractionOperand::UmlInteractionOperand() :
    _guard(0)
{
}

// OWNED ATTRIBUTES

/*!
    The fragments of the operand.
 */
const QList<UmlInteractionFragment *> UmlInteractionOperand::fragment() const
{
    // This is a read-write association end

    return _fragment;
}

void UmlInteractionOperand::addFragment(UmlInteractionFragment *fragment)
{
    // This is a read-write association end

    if (!_fragment.contains(fragment)) {
        _fragment.append(fragment);

        // Adjust subsetted properties
        addOwnedMember(fragment);

        // Adjust opposite properties
        if (fragment) {
            fragment->setEnclosingOperand(this);
        }
    }
}

void UmlInteractionOperand::removeFragment(UmlInteractionFragment *fragment)
{
    // This is a read-write association end

    if (_fragment.contains(fragment)) {
        _fragment.removeAll(fragment);

        // Adjust subsetted properties
        removeOwnedMember(fragment);

        // Adjust opposite properties
        if (fragment) {
            fragment->setEnclosingOperand(0);
        }
    }
}

/*!
    Constraint of the operand.
 */
UmlInteractionConstraint *UmlInteractionOperand::guard() const
{
    // This is a read-write association end

    return _guard;
}

void UmlInteractionOperand::setGuard(UmlInteractionConstraint *guard)
{
    // This is a read-write association end

    if (_guard != guard) {
        // Adjust subsetted properties
        removeOwnedElement(_guard);

        _guard = guard;

        // Adjust subsetted properties
        if (guard) {
            addOwnedElement(guard);
        }
    }
}
