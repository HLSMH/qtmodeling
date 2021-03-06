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
#include "qumlinteractionfragment.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteraction>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlInteractionFragment

    \inmodule QtUml

    \brief InteractionFragment is an abstract notion of the most general interaction unit. An interaction fragment is a piece of an interaction. Each interaction fragment is conceptually like an interaction by itself.

    \b {QUmlInteractionFragment is an abstract class.}
 */

/*!
    Creates a new QUmlInteractionFragment.
*/
QUmlInteractionFragment::QUmlInteractionFragment() :
    _enclosingInteraction(0),
    _enclosingOperand(0)
{
}

/*!
    Destroys the QUmlInteractionFragment.
 */
QUmlInteractionFragment::~QUmlInteractionFragment()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlInteractionFragment.
*/
QModelingElement *QUmlInteractionFragment::clone() const
{
    QUmlInteractionFragment *c = new QUmlInteractionFragment;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlGeneralOrdering *element, generalOrderings())
        c->addGeneralOrdering(dynamic_cast<QUmlGeneralOrdering *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    References the Lifelines that the InteractionFragment involves.

    \sa addCovered(), removeCovered()

    \b {Opposite property(ies):} QUmlLifeline::coveredBy().
 */
const QSet<QUmlLifeline *> QUmlInteractionFragment::covered() const
{
    // This is a read-write association end

    return _covered;
}

/*!
    Adds \a covered to covered.

    \sa covered(), removeCovered()
 */
void QUmlInteractionFragment::addCovered(QUmlLifeline *covered)
{
    // This is a read-write association end

    if (!_covered.contains(covered)) {
        _covered.insert(covered);
        if (covered && covered->asQModelingObject() && this->asQModelingObject())
            QObject::connect(covered->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeCovered(QObject *)));

        // Adjust opposite properties
        if (covered) {
            covered->addCoveredBy(this);
        }
    }
}

/*!
    Removes \a covered from covered.

    \sa covered(), addCovered()
 */
void QUmlInteractionFragment::removeCovered(QUmlLifeline *covered)
{
    // This is a read-write association end

    if (_covered.contains(covered)) {
        _covered.remove(covered);

        // Adjust opposite properties
        if (covered) {
            covered->removeCoveredBy(this);
        }
    }
}

/*!
    The Interaction enclosing this InteractionFragment.

    \b {Subsetted property(ies):} QUmlNamedElement::namespace_().

    \b {Opposite property(ies):} QUmlInteraction::fragments().
 */
QUmlInteraction *QUmlInteractionFragment::enclosingInteraction() const
{
    // This is a read-write association end

    return _enclosingInteraction;
}

/*!
    Adjusts enclosingInteraction to \a enclosingInteraction.
 */
void QUmlInteractionFragment::setEnclosingInteraction(QUmlInteraction *enclosingInteraction)
{
    // This is a read-write association end

    if (_enclosingInteraction != enclosingInteraction) {
        // Adjust subsetted properties

        _enclosingInteraction = enclosingInteraction;
        if (enclosingInteraction && enclosingInteraction->asQModelingObject() && this->asQModelingObject())
            QObject::connect(enclosingInteraction->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setEnclosingInteraction()));

        // Adjust subsetted properties
        setNamespace(enclosingInteraction);
    }
}

/*!
    The operand enclosing this InteractionFragment (they may nest recursively)

    \b {Subsetted property(ies):} QUmlNamedElement::namespace_().

    \b {Opposite property(ies):} QUmlInteractionOperand::fragments().
 */
QUmlInteractionOperand *QUmlInteractionFragment::enclosingOperand() const
{
    // This is a read-write association end

    return _enclosingOperand;
}

/*!
    Adjusts enclosingOperand to \a enclosingOperand.
 */
void QUmlInteractionFragment::setEnclosingOperand(QUmlInteractionOperand *enclosingOperand)
{
    // This is a read-write association end

    if (_enclosingOperand != enclosingOperand) {
        // Adjust subsetted properties

        _enclosingOperand = enclosingOperand;
        if (enclosingOperand && enclosingOperand->asQModelingObject() && this->asQModelingObject())
            QObject::connect(enclosingOperand->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setEnclosingOperand()));

        // Adjust subsetted properties
        setNamespace(enclosingOperand);
    }
}

/*!
    The general ordering relationships contained in this fragment.

    \sa addGeneralOrdering(), removeGeneralOrdering()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
const QSet<QUmlGeneralOrdering *> QUmlInteractionFragment::generalOrderings() const
{
    // This is a read-write association end

    return _generalOrderings;
}

/*!
    Adds \a generalOrdering to generalOrderings.

    \sa generalOrderings(), removeGeneralOrdering()
 */
void QUmlInteractionFragment::addGeneralOrdering(QUmlGeneralOrdering *generalOrdering)
{
    // This is a read-write association end

    if (!_generalOrderings.contains(generalOrdering)) {
        _generalOrderings.insert(generalOrdering);
        if (generalOrdering && generalOrdering->asQModelingObject() && this->asQModelingObject())
            QObject::connect(generalOrdering->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeGeneralOrdering(QObject *)));
        generalOrdering->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(generalOrdering);
    }
}

/*!
    Removes \a generalOrdering from generalOrderings.

    \sa generalOrderings(), addGeneralOrdering()
 */
void QUmlInteractionFragment::removeGeneralOrdering(QUmlGeneralOrdering *generalOrdering)
{
    // This is a read-write association end

    if (_generalOrderings.contains(generalOrdering)) {
        _generalOrderings.remove(generalOrdering);
        if (generalOrdering->asQModelingObject())
            generalOrdering->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(generalOrdering);
    }
}

QT_END_NAMESPACE

