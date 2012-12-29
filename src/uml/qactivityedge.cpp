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

#include "qactivityedge.h"
#include "qactivityedge_p.h"

#include "qactivitygroup_p.h"

#include <QtUml/QInterruptibleActivityRegion>
#include <QtUml/QActivityNode>
#include <QtUml/QStructuredActivityNode>
#include <QtUml/QActivityPartition>
#include <QtUml/QActivity>
#include <QtUml/QActivityGroup>
#include <QtUml/QValueSpecification>

QT_BEGIN_NAMESPACE_QTUML

QActivityEdgePrivate::QActivityEdgePrivate() :
    source(0),
    guard(0),
    activity(0),
    interrupts(0),
    weight(0),
    inStructuredNode(0),
    target(0)
{
}

QActivityEdgePrivate::~QActivityEdgePrivate()
{
}

void QActivityEdgePrivate::addInGroup(QActivityGroup *inGroup)
{
    // This is a read-only derived-union association end

    if (!this->inGroup.contains(inGroup)) {
        this->inGroup.insert(inGroup);

        // Adjust opposite property
        Q_Q(QActivityEdge);
        (qwrappedobject_cast<QActivityGroupPrivate *>(inGroup->d_func()))->addContainedEdge(q);
    }
}

void QActivityEdgePrivate::removeInGroup(QActivityGroup *inGroup)
{
    // This is a read-only derived-union association end

    if (this->inGroup.contains(inGroup)) {
        this->inGroup.remove(inGroup);

        // Adjust opposite property
        Q_Q(QActivityEdge);
        if (inGroup)
            (qwrappedobject_cast<QActivityGroupPrivate *>(inGroup->d_func()))->removeContainedEdge(q);
    }
}

/*!
    \class QActivityEdge

    \inmodule QtUml

    \brief Activity edges can be contained in interruptible regions.An activity edge is an abstract class for directed connections between two activity nodes.
 */

QActivityEdge::QActivityEdge(QWrappedObject *parent, QWrappedObject *wrapper) :
    QRedefinableElement(*new QActivityEdgePrivate, parent, wrapper)
{
}

QActivityEdge::QActivityEdge(QActivityEdgePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QRedefinableElement(dd, parent, wrapper)
{
}

QActivityEdge::~QActivityEdge()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QActivityEdge
// ---------------------------------------------------------------

/*!
    Node from which tokens are taken when they traverse the edge.
 */
QActivityNode *QActivityEdge::source() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->source;
}

void QActivityEdge::setSource(QActivityNode *source)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->source != source) {
        // Adjust opposite property
        if (d->source)
            d->source->removeOutgoing(this);

        d->source = source;

        // Adjust opposite property
        if (source)
            source->addOutgoing(this);
    }
}

/*!
    Inherited edges replaced by this edge in a specialization of the activity.
 */
QSet<QActivityEdge *> QActivityEdge::redefinedEdges() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->redefinedEdges;
}

void QActivityEdge::addRedefinedEdge(QActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (!d->redefinedEdges.contains(redefinedEdge)) {
        d->redefinedEdges.insert(redefinedEdge);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->addRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(redefinedEdge));
    }
}

void QActivityEdge::removeRedefinedEdge(QActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->redefinedEdges.contains(redefinedEdge)) {
        d->redefinedEdges.remove(redefinedEdge);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->removeRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(redefinedEdge));
    }
}

/*!
    Groups containing the edge.
 */
QSet<QActivityGroup *> QActivityEdge::inGroup() const
{
    // This is a read-only derived-union association end

    Q_D(const QActivityEdge);
    return d->inGroup;
}

/*!
    Specification evaluated at runtime to determine if the edge can be traversed.
 */
QValueSpecification *QActivityEdge::guard() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->guard;
}

void QActivityEdge::setGuard(QValueSpecification *guard)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->guard != guard) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->guard));

        d->guard = guard;

        // Adjust subsetted property(ies)
        if (guard) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(guard));
        }
    }
}

/*!
    Partitions containing the edge.
 */
QSet<QActivityPartition *> QActivityEdge::inPartition() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->inPartition;
}

void QActivityEdge::addInPartition(QActivityPartition *inPartition)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (!d->inPartition.contains(inPartition)) {
        d->inPartition.insert(inPartition);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActivityEdgePrivate *>(d))->addInGroup(qwrappedobject_cast<QActivityGroup *>(inPartition));

        // Adjust opposite property
        inPartition->addEdge(this);
    }
}

void QActivityEdge::removeInPartition(QActivityPartition *inPartition)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->inPartition.contains(inPartition)) {
        d->inPartition.remove(inPartition);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActivityEdgePrivate *>(d))->removeInGroup(qwrappedobject_cast<QActivityGroup *>(inPartition));

        // Adjust opposite property
        if (inPartition)
            inPartition->removeEdge(this);
    }
}

/*!
    Activity containing the edge.
 */
QActivity *QActivityEdge::activity() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->activity;
}

void QActivityEdge::setActivity(QActivity *activity)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->activity != activity) {
        // Adjust opposite property
        if (d->activity)
            d->activity->removeEdge(this);

        d->activity = activity;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->setOwner(qwrappedobject_cast<QElement *>(activity));

        // Adjust opposite property
        if (activity)
            activity->addEdge(this);
    }
}

/*!
    Region that the edge can interrupt.
 */
QInterruptibleActivityRegion *QActivityEdge::interrupts() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->interrupts;
}

void QActivityEdge::setInterrupts(QInterruptibleActivityRegion *interrupts)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->interrupts != interrupts) {
        // Adjust opposite property
        if (d->interrupts)
            d->interrupts->removeInterruptingEdge(this);

        d->interrupts = interrupts;

        // Adjust opposite property
        if (interrupts)
            interrupts->addInterruptingEdge(this);
    }
}

/*!
    The minimum number of tokens that must traverse the edge at the same time.
 */
QValueSpecification *QActivityEdge::weight() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->weight;
}

void QActivityEdge::setWeight(QValueSpecification *weight)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->weight != weight) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->weight));

        d->weight = weight;

        // Adjust subsetted property(ies)
        if (weight) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(weight));
        }
    }
}

/*!
    Structured activity node containing the edge.
 */
QStructuredActivityNode *QActivityEdge::inStructuredNode() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->inStructuredNode;
}

void QActivityEdge::setInStructuredNode(QStructuredActivityNode *inStructuredNode)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->inStructuredNode != inStructuredNode) {
        // Adjust opposite property
        if (d->inStructuredNode)
            d->inStructuredNode->removeEdge(this);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActivityEdgePrivate *>(d))->removeInGroup(qwrappedobject_cast<QActivityGroup *>(d->inStructuredNode));

        d->inStructuredNode = inStructuredNode;

        // Adjust subsetted property(ies)
        if (inStructuredNode) {
            (qwrappedobject_cast<QActivityEdgePrivate *>(d))->addInGroup(qwrappedobject_cast<QActivityGroup *>(inStructuredNode));
        }
        (qwrappedobject_cast<QElementPrivate *>(d))->setOwner(qwrappedobject_cast<QElement *>(inStructuredNode));

        // Adjust opposite property
        if (inStructuredNode)
            inStructuredNode->addEdge(this);
    }
}

/*!
    Node to which tokens are put when they traverse the edge.
 */
QActivityNode *QActivityEdge::target() const
{
    // This is a read-write association end

    Q_D(const QActivityEdge);
    return d->target;
}

void QActivityEdge::setTarget(QActivityNode *target)
{
    // This is a read-write association end

    Q_D(QActivityEdge);
    if (d->target != target) {
        // Adjust opposite property
        if (d->target)
            d->target->removeIncoming(this);

        d->target = target;

        // Adjust opposite property
        if (target)
            target->addIncoming(this);
    }
}

void QActivityEdge::registerMetaTypes() const
{
    qRegisterMetaType<QInterruptibleActivityRegion *>("QInterruptibleActivityRegion *");
    qRegisterMetaType<QSet<QInterruptibleActivityRegion *>>("QSet<QInterruptibleActivityRegion *>");
    qRegisterMetaType<QList<QInterruptibleActivityRegion *>>("QList<QInterruptibleActivityRegion *>");

    qRegisterMetaType<QActivityNode *>("QActivityNode *");
    qRegisterMetaType<QSet<QActivityNode *>>("QSet<QActivityNode *>");
    qRegisterMetaType<QList<QActivityNode *>>("QList<QActivityNode *>");

    qRegisterMetaType<QStructuredActivityNode *>("QStructuredActivityNode *");
    qRegisterMetaType<QSet<QStructuredActivityNode *>>("QSet<QStructuredActivityNode *>");
    qRegisterMetaType<QList<QStructuredActivityNode *>>("QList<QStructuredActivityNode *>");

    qRegisterMetaType<QActivityPartition *>("QActivityPartition *");
    qRegisterMetaType<QSet<QActivityPartition *>>("QSet<QActivityPartition *>");
    qRegisterMetaType<QList<QActivityPartition *>>("QList<QActivityPartition *>");

    qRegisterMetaType<QActivity *>("QActivity *");
    qRegisterMetaType<QSet<QActivity *>>("QSet<QActivity *>");
    qRegisterMetaType<QList<QActivity *>>("QList<QActivity *>");

    qRegisterMetaType<QActivityGroup *>("QActivityGroup *");
    qRegisterMetaType<QSet<QActivityGroup *>>("QSet<QActivityGroup *>");
    qRegisterMetaType<QList<QActivityGroup *>>("QList<QActivityGroup *>");

    qRegisterMetaType<QValueSpecification *>("QValueSpecification *");
    qRegisterMetaType<QSet<QValueSpecification *>>("QSet<QValueSpecification *>");
    qRegisterMetaType<QList<QValueSpecification *>>("QList<QValueSpecification *>");

    QRedefinableElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qactivityedge.cpp"

QT_END_NAMESPACE_QTUML

