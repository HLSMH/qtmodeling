/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qinteractionconstraint.h"
#include "qinteractionconstraint_p.h"

#include <QtUml/QValueSpecification>

QT_BEGIN_NAMESPACE_QTUML

QInteractionConstraintPrivate::QInteractionConstraintPrivate() :
    maxint(0),
    minint(0)
{
}

QInteractionConstraintPrivate::~QInteractionConstraintPrivate()
{
}

/*!
    \class QInteractionConstraint

    \inmodule QtUml

    \brief An interaction constraint is a Boolean expression that guards an operand in a combined fragment.
 */

QInteractionConstraint::QInteractionConstraint(QWrappedObject *parent, QWrappedObject *wrapper) :
    QConstraint(*new QInteractionConstraintPrivate, parent, wrapper)
{
}

QInteractionConstraint::QInteractionConstraint(QInteractionConstraintPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QConstraint(dd, parent, wrapper)
{
}

QInteractionConstraint::~QInteractionConstraint()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QInteractionConstraint
// ---------------------------------------------------------------

/*!
    The maximum number of iterations of a loop
 */
QValueSpecification *QInteractionConstraint::maxint() const
{
    // This is a read-write association end

    Q_D(const QInteractionConstraint);
    return d->maxint;
}

void QInteractionConstraint::setMaxint(QValueSpecification *maxint)
{
    // This is a read-write association end

    Q_D(QInteractionConstraint);
    if (d->maxint != maxint) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->maxint));

        d->maxint = maxint;

        // Adjust subsetted property(ies)
        if (maxint) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(maxint));
        }
    }
}

/*!
    The minimum number of iterations of a loop
 */
QValueSpecification *QInteractionConstraint::minint() const
{
    // This is a read-write association end

    Q_D(const QInteractionConstraint);
    return d->minint;
}

void QInteractionConstraint::setMinint(QValueSpecification *minint)
{
    // This is a read-write association end

    Q_D(QInteractionConstraint);
    if (d->minint != minint) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->minint));

        d->minint = minint;

        // Adjust subsetted property(ies)
        if (minint) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(minint));
        }
    }
}

void QInteractionConstraint::registerMetaTypes() const
{
    qRegisterMetaType<QValueSpecification *>("QValueSpecification *");
    qRegisterMetaType<QSet<QValueSpecification *>>("QSet<QValueSpecification *>");
    qRegisterMetaType<QList<QValueSpecification *>>("QList<QValueSpecification *>");

    QConstraint::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qinteractionconstraint.cpp"

QT_END_NAMESPACE_QTUML

