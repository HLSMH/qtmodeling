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
#include "umlcallaction_p.h"

#include "private/umloutputpin_p.h"

/*!
    \class UmlCallAction

    \inmodule QtUml

    \brief CallAction is an abstract class for actions that invoke behavior and receive return values.
 */

UmlCallAction::UmlCallAction() :
    _isSynchronous(true)
{
}

// OWNED ATTRIBUTES

/*!
    If true, the call is synchronous and the caller waits for completion of the invoked behavior. If false, the call is asynchronous and the caller proceeds immediately and does not expect a return values.
 */
bool UmlCallAction::isSynchronous() const
{
    // This is a read-write property

    return _isSynchronous;
}

void UmlCallAction::setSynchronous(bool isSynchronous)
{
    // This is a read-write property

    if (_isSynchronous != isSynchronous) {
        _isSynchronous = isSynchronous;
    }
}

/*!
    A list of output pins where the results of performing the invocation are placed.
 */
const QList<UmlOutputPin *> UmlCallAction::result() const
{
    // This is a read-write association end

    return _result;
}

void UmlCallAction::addResult(UmlOutputPin *result)
{
    // This is a read-write association end

    if (!_result.contains(result)) {
        _result.append(result);

        // Adjust subsetted properties
        addOutput(result);
    }
}

void UmlCallAction::removeResult(UmlOutputPin *result)
{
    // This is a read-write association end

    if (_result.contains(result)) {
        _result.removeAll(result);

        // Adjust subsetted properties
        removeOutput(result);
    }
}
