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
#include "qumlreduceaction.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlOutputPin>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlReduceAction

    \inmodule QtUml

    \brief A reduce action is an action that reduces a collection to a single value by combining the elements of the collection.
 */

QUmlReduceAction::QUmlReduceAction() :
    _collection(0),
    _isOrdered(false),
    _reducer(0),
    _result(0)
{
    d_ptr->object.setProperty("collection", QVariant::fromValue((QUmlInputPin *)(0)));
    d_ptr->object.setProperty("isOrdered", QVariant::fromValue(false));
    d_ptr->object.setProperty("reducer", QVariant::fromValue((QUmlBehavior *)(0)));
    d_ptr->object.setProperty("result", QVariant::fromValue((QUmlOutputPin *)(0)));
}

// OWNED ATTRIBUTES

/*!
    The collection to be reduced.
 */
QUmlInputPin *QUmlReduceAction::collection() const
{
    // This is a read-write association end

    return _collection;
}

void QUmlReduceAction::setCollection(QUmlInputPin *collection)
{
    // This is a read-write association end

    if (_collection != collection) {
        // Adjust subsetted properties
        removeInput(_collection);

        _collection = collection;

        // Adjust subsetted properties
        if (collection) {
            addInput(collection);
        }
    }
}

/*!
    Tells whether the order of the input collection should determine the order in which the behavior is applied to its elements.
 */
bool QUmlReduceAction::isOrdered() const
{
    // This is a read-write property

    return _isOrdered;
}

void QUmlReduceAction::setOrdered(bool isOrdered)
{
    // This is a read-write property

    if (_isOrdered != isOrdered) {
        _isOrdered = isOrdered;
    }
}

/*!
    Behavior that is applied to two elements of the input collection to produce a value that is the same type as elements of the collection.
 */
QUmlBehavior *QUmlReduceAction::reducer() const
{
    // This is a read-write association end

    return _reducer;
}

void QUmlReduceAction::setReducer(QUmlBehavior *reducer)
{
    // This is a read-write association end

    if (_reducer != reducer) {
        _reducer = reducer;
    }
}

/*!
    Gives the output pin on which the result is put.
 */
QUmlOutputPin *QUmlReduceAction::result() const
{
    // This is a read-write association end

    return _result;
}

void QUmlReduceAction::setResult(QUmlOutputPin *result)
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

QT_END_NAMESPACE

