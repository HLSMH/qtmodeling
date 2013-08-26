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
#include "qumlconditionalnode.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlClause>
#include <QtUml/QUmlOutputPin>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlConditionalNode

    \inmodule QtUml

    \brief A conditional node is a structured activity node that represents an exclusive choice among some number of alternatives.
 */

QUmlConditionalNode::QUmlConditionalNode() :
    _isAssured(false),
    _isDeterminate(false)
{
    d_ptr->object.setProperty("clause", QVariant::fromValue(&_clause));
    d_ptr->object.setProperty("isAssured", QVariant::fromValue(false));
    d_ptr->object.setProperty("isDeterminate", QVariant::fromValue(false));
    d_ptr->object.setProperty("result", QVariant::fromValue(&_result));
}

// OWNED ATTRIBUTES

/*!
    Set of clauses composing the conditional.
 */
QSet<QUmlClause *> QUmlConditionalNode::clause() const
{
    // This is a read-write association end

    return _clause;
}

void QUmlConditionalNode::addClause(QUmlClause *clause)
{
    // This is a read-write association end

    if (!_clause.contains(clause)) {
        _clause.insert(clause);

        // Adjust subsetted properties
        addOwnedElement(clause);
    }
}

void QUmlConditionalNode::removeClause(QUmlClause *clause)
{
    // This is a read-write association end

    if (_clause.contains(clause)) {
        _clause.remove(clause);

        // Adjust subsetted properties
        removeOwnedElement(clause);
    }
}

/*!
    If true, the modeler asserts that at least one test will succeed.
 */
bool QUmlConditionalNode::isAssured() const
{
    // This is a read-write property

    return _isAssured;
}

void QUmlConditionalNode::setAssured(bool isAssured)
{
    // This is a read-write property

    if (_isAssured != isAssured) {
        _isAssured = isAssured;
    }
}

/*!
    If true, the modeler asserts that at most one test will succeed.
 */
bool QUmlConditionalNode::isDeterminate() const
{
    // This is a read-write property

    return _isDeterminate;
}

void QUmlConditionalNode::setDeterminate(bool isDeterminate)
{
    // This is a read-write property

    if (_isDeterminate != isDeterminate) {
        _isDeterminate = isDeterminate;
    }
}

/*!
    A list of output pins that constitute the data flow outputs of the conditional.
 */
QList<QUmlOutputPin *> QUmlConditionalNode::result() const
{
    // This is a read-write association end

    return _result;
}

void QUmlConditionalNode::addResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    if (!_result.contains(result)) {
        _result.append(result);
    }
}

void QUmlConditionalNode::removeResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    if (_result.contains(result)) {
        _result.removeAll(result);
    }
}

QT_END_NAMESPACE

