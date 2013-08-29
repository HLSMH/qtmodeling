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
#include "umlstringexpression_p.h"

/*!
    \class UmlStringExpression

    \inmodule QtUml

    \brief An expression that specifies a string value that is derived by concatenating a set of sub string expressions, some of which might be template parameters.
 */

UmlStringExpression::UmlStringExpression() :
    _owningExpression(0)
{
}

// OWNED ATTRIBUTES

/*!
    The string expression of which this expression is a substring.
 */
UmlStringExpression *UmlStringExpression::owningExpression() const
{
    // This is a read-write association end

    return _owningExpression;
}

void UmlStringExpression::setOwningExpression(UmlStringExpression *owningExpression)
{
    // This is a read-write association end

    if (_owningExpression != owningExpression) {
        // Adjust subsetted properties

        _owningExpression = owningExpression;

        // Adjust subsetted properties
        setOwner(owningExpression);
    }
}

/*!
    The StringExpressions that constitute this StringExpression.
 */
const QSet<UmlStringExpression *> UmlStringExpression::subExpression() const
{
    // This is a read-write association end

    return _subExpression;
}

void UmlStringExpression::addSubExpression(UmlStringExpression *subExpression)
{
    // This is a read-write association end

    if (!_subExpression.contains(subExpression)) {
        _subExpression.insert(subExpression);

        // Adjust subsetted properties
        addOwnedElement(subExpression);
    }
}

void UmlStringExpression::removeSubExpression(UmlStringExpression *subExpression)
{
    // This is a read-write association end

    if (_subExpression.contains(subExpression)) {
        _subExpression.remove(subExpression);

        // Adjust subsetted properties
        removeOwnedElement(subExpression);
    }
}

// OPERATIONS

/*!
    The query stringValue() returns the string that concatenates, in order, all the component string literals of all the subexpressions that are part of the StringExpression.
 */
QString UmlStringExpression::stringValue(
    ) const
{
    qWarning("UmlStringExpression::stringValue(): to be implemented (operation)");

    return QString ();
}
