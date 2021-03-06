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
#include "qumlsubstitution.h"

#include "private/qumlsubstitutionobject_p.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOpaqueExpression>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlSubstitution

    \inmodule QtUml

    \brief A substitution is a relationship between two classifiers signifies that the substituting classifier complies with the contract specified by the contract classifier. This implies that instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
 */

/*!
    Creates a new QUmlSubstitution. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlSubstitution::QUmlSubstitution(bool createQModelingObject) :
    QUmlRealization(false),
    _contract(0),
    _substitutingClassifier(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlSubstitutionObject(this));
}

/*!
    Destroys the QUmlSubstitution.
 */
QUmlSubstitution::~QUmlSubstitution()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlSubstitution.
*/
QModelingElement *QUmlSubstitution::clone() const
{
    QUmlSubstitution *c = new QUmlSubstitution;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (mapping())
        c->setMapping(dynamic_cast<QUmlOpaqueExpression *>(mapping()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The contract with which the substituting classifier complies.

    \b {Subsetted property(ies):} QUmlDependency::suppliers().
 */
QUmlClassifier *QUmlSubstitution::contract() const
{
    // This is a read-write association end

    return _contract;
}

/*!
    Adjusts contract to \a contract.
 */
void QUmlSubstitution::setContract(QUmlClassifier *contract)
{
    // This is a read-write association end

    if (_contract != contract) {
        // Adjust subsetted properties
        removeSupplier(_contract);

        _contract = contract;
        if (contract && contract->asQModelingObject() && this->asQModelingObject())
            QObject::connect(contract->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setContract()));

        // Adjust subsetted properties
        if (contract) {
            addSupplier(contract);
        }
    }
}

/*!
    Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.

    \b {Subsetted property(ies):} QUmlElement::owner(), QUmlDependency::clients().

    \b {Opposite property(ies):} QUmlClassifier::substitutions().
 */
QUmlClassifier *QUmlSubstitution::substitutingClassifier() const
{
    // This is a read-write association end

    return _substitutingClassifier;
}

/*!
    Adjusts substitutingClassifier to \a substitutingClassifier.
 */
void QUmlSubstitution::setSubstitutingClassifier(QUmlClassifier *substitutingClassifier)
{
    // This is a read-write association end

    if (_substitutingClassifier != substitutingClassifier) {
        // Adjust subsetted properties
        removeClient(_substitutingClassifier);

        _substitutingClassifier = substitutingClassifier;
        if (substitutingClassifier && substitutingClassifier->asQModelingObject() && this->asQModelingObject())
            QObject::connect(substitutingClassifier->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setSubstitutingClassifier()));

        // Adjust subsetted properties
        setOwner(substitutingClassifier);
        if (substitutingClassifier) {
            addClient(substitutingClassifier);
        }
    }
}

QT_END_NAMESPACE

