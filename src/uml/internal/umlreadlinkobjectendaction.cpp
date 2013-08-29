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
#include "umlreadlinkobjectendaction_p.h"

#include "private/umlinputpin_p.h"
#include "private/umloutputpin_p.h"
#include "private/umlproperty_p.h"

/*!
    \class UmlReadLinkObjectEndAction

    \inmodule QtUml

    \brief A read link object end action is an action that retrieves an end object from a link object.
 */

UmlReadLinkObjectEndAction::UmlReadLinkObjectEndAction() :
    _end(0),
    _object(0),
    _result(0)
{
}

// OWNED ATTRIBUTES

/*!
    Link end to be read.
 */
UmlProperty *UmlReadLinkObjectEndAction::end() const
{
    // This is a read-write association end

    return _end;
}

void UmlReadLinkObjectEndAction::setEnd(UmlProperty *end)
{
    // This is a read-write association end

    if (_end != end) {
        _end = end;
    }
}

/*!
    Gives the input pin from which the link object is obtained.
 */
UmlInputPin *UmlReadLinkObjectEndAction::object() const
{
    // This is a read-write association end

    return _object;
}

void UmlReadLinkObjectEndAction::setObject(UmlInputPin *object)
{
    // This is a read-write association end

    if (_object != object) {
        // Adjust subsetted properties
        removeInput(_object);

        _object = object;

        // Adjust subsetted properties
        if (object) {
            addInput(object);
        }
    }
}

/*!
    Pin where the result value is placed.
 */
UmlOutputPin *UmlReadLinkObjectEndAction::result() const
{
    // This is a read-write association end

    return _result;
}

void UmlReadLinkObjectEndAction::setResult(UmlOutputPin *result)
{
    // This is a read-write association end

    if (_result != result) {
        // Adjust subsetted properties
        removeOutput(_result);

        _result = result;

        // Adjust subsetted properties
        if (result) {
            addOutput(result);
        }
    }
}
