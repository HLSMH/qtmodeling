/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMof module of the Qt Toolkit.
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
#include "qmofbehavioralfeature.h"

#include <QtMof/QMofClass>
#include <QtMof/QMofClassifier>
#include <QtMof/QMofComment>
#include <QtMof/QMofConstraint>
#include <QtMof/QMofElement>
#include <QtMof/QMofElementImport>
#include <QtMof/QMofNamedElement>
#include <QtMof/QMofPackageableElement>
#include <QtMof/QMofPackageImport>
#include <QtMof/QMofParameter>
#include <QtMof/QMofRedefinableElement>
#include <QtMof/QMofType>

QT_BEGIN_NAMESPACE

/*!
    \class QMofBehavioralFeature

    \inmodule QtMof

    \brief A behavioral feature is a feature of a classifier that specifies an aspect of the behavior of its instances.

    \b {QMofBehavioralFeature is an abstract class.}
 */

/*!
    Creates a new QMofBehavioralFeature.
*/
QMofBehavioralFeature::QMofBehavioralFeature()
{
}

/*!
    Destroys the QMofBehavioralFeature.
 */
QMofBehavioralFeature::~QMofBehavioralFeature()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QMofBehavioralFeature.
*/
QModelingElement *QMofBehavioralFeature::clone() const
{
    QMofBehavioralFeature *c = new QMofBehavioralFeature;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QMofComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QMofComment *>(element->clone()));
    c->setName(name());
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    c->setStatic(isStatic());
    foreach (QMofElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QMofElementImport *>(element->clone()));
    foreach (QMofConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QMofConstraint *>(element->clone()));
    foreach (QMofPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QMofPackageImport *>(element->clone()));
    foreach (QMofParameter *element, ownedParameters())
        c->addOwnedParameter(dynamic_cast<QMofParameter *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies the ordered set of formal parameters of this BehavioralFeature.

    \sa addOwnedParameter(), removeOwnedParameter()

    \b {Subsetted property(ies):} QMofNamespace::ownedMembers().
 */
const QList<QMofParameter *> QMofBehavioralFeature::ownedParameters() const
{
    // This is a read-write association end

    return _ownedParameters;
}

/*!
    Adds \a ownedParameter to ownedParameters.

    \sa ownedParameters(), removeOwnedParameter()
 */
void QMofBehavioralFeature::addOwnedParameter(QMofParameter *ownedParameter)
{
    // This is a read-write association end

    if (!_ownedParameters.contains(ownedParameter)) {
        _ownedParameters.append(ownedParameter);
        if (ownedParameter && ownedParameter->asQModelingObject() && this->asQModelingObject())
            QObject::connect(ownedParameter->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeOwnedParameter(QObject *)));
        ownedParameter->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(ownedParameter);
    }
}

/*!
    Removes \a ownedParameter from ownedParameters.

    \sa ownedParameters(), addOwnedParameter()
 */
void QMofBehavioralFeature::removeOwnedParameter(QMofParameter *ownedParameter)
{
    // This is a read-write association end

    if (_ownedParameters.contains(ownedParameter)) {
        _ownedParameters.removeAll(ownedParameter);
        if (ownedParameter->asQModelingObject())
            ownedParameter->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(ownedParameter);
    }
}

/*!
    References the Types representing exceptions that may be raised during an invocation of this feature.

    \sa addRaisedException(), removeRaisedException()
 */
const QSet<QMofType *> QMofBehavioralFeature::raisedExceptions() const
{
    // This is a read-write association end

    return _raisedExceptions;
}

/*!
    Adds \a raisedException to raisedExceptions.

    \sa raisedExceptions(), removeRaisedException()
 */
void QMofBehavioralFeature::addRaisedException(QMofType *raisedException)
{
    // This is a read-write association end

    if (!_raisedExceptions.contains(raisedException)) {
        _raisedExceptions.insert(raisedException);
        if (raisedException && raisedException->asQModelingObject() && this->asQModelingObject())
            QObject::connect(raisedException->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeRaisedException(QObject *)));
    }
}

/*!
    Removes \a raisedException from raisedExceptions.

    \sa raisedExceptions(), addRaisedException()
 */
void QMofBehavioralFeature::removeRaisedException(QMofType *raisedException)
{
    // This is a read-write association end

    if (_raisedExceptions.contains(raisedException)) {
        _raisedExceptions.remove(raisedException);
    }
}

// OPERATIONS

/*!
    The query isDistinguishableFrom() determines whether two BehavioralFeatures may coexist in the same Namespace. It specifies that they have to have different signatures.
 */
bool QMofBehavioralFeature::isDistinguishableFrom(QMofNamedElement *n, QMofNamespace *ns) const
{
    qWarning("QMofBehavioralFeature::isDistinguishableFrom(): to be implemented (operation)");

    Q_UNUSED(n);
    Q_UNUSED(ns);
    return bool ();
}

QT_END_NAMESPACE

