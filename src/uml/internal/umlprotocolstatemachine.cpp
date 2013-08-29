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
#include "umlprotocolstatemachine_p.h"

#include "private/umlprotocolconformance_p.h"

/*!
    \class UmlProtocolStateMachine

    \inmodule QtUml

    \brief A protocol state machine is always defined in the context of a classifier. It specifies which operations of the classifier can be called in which state and under which condition, thus specifying the allowed call sequences on the classifier's operations. A protocol state machine presents the possible and permitted transitions on the instances of its context classifier, together with the operations which carry the transitions. In this manner, an instance lifecycle can be created for a classifier, by specifying the order in which the operations can be activated and the states through which an instance progresses during its existence.
 */

UmlProtocolStateMachine::UmlProtocolStateMachine()
{
}

// OWNED ATTRIBUTES

/*!
    Conformance between protocol state machines.
 */
const QSet<UmlProtocolConformance *> UmlProtocolStateMachine::conformance() const
{
    // This is a read-write association end

    return _conformance;
}

void UmlProtocolStateMachine::addConformance(UmlProtocolConformance *conformance)
{
    // This is a read-write association end

    if (!_conformance.contains(conformance)) {
        _conformance.insert(conformance);

        // Adjust subsetted properties
        addOwnedElement(conformance);

        // Adjust opposite properties
        if (conformance) {
            conformance->setSpecificMachine(this);
        }
    }
}

void UmlProtocolStateMachine::removeConformance(UmlProtocolConformance *conformance)
{
    // This is a read-write association end

    if (_conformance.contains(conformance)) {
        _conformance.remove(conformance);

        // Adjust subsetted properties
        removeOwnedElement(conformance);

        // Adjust opposite properties
        if (conformance) {
            conformance->setSpecificMachine(0);
        }
    }
}
