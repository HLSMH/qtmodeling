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
#include "qumlreadlinkobjectendqualifieraction.h"
#include "qumlreadlinkobjectendqualifieraction_p.h"

#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlOutputPin>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlReadLinkObjectEndQualifierActionPrivate::QUmlReadLinkObjectEndQualifierActionPrivate() :
    result(0),
    object(0),
    qualifier(0)
{
}

QUmlReadLinkObjectEndQualifierActionPrivate::~QUmlReadLinkObjectEndQualifierActionPrivate()
{
}

/*!
    \class QUmlReadLinkObjectEndQualifierAction

    \inmodule QtUml

    \brief A read link object end qualifier action is an action that retrieves a qualifier end value from a link object.
 */

QUmlReadLinkObjectEndQualifierAction::QUmlReadLinkObjectEndQualifierAction(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlAction(*new QUmlReadLinkObjectEndQualifierActionPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlReadLinkObjectEndQualifierAction::QUmlReadLinkObjectEndQualifierAction(QUmlReadLinkObjectEndQualifierActionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlAction(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlReadLinkObjectEndQualifierAction::~QUmlReadLinkObjectEndQualifierAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlReadLinkObjectEndQualifierAction
// ---------------------------------------------------------------

/*!
    Pin where the result value is placed.
 */
QUmlOutputPin *QUmlReadLinkObjectEndQualifierAction::result() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndQualifierAction);
    return d->result;
}

void QUmlReadLinkObjectEndQualifierAction::setResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndQualifierAction);
    if (d->result != result) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlActionPrivate *>(d))->removeOutput(qwrappedobject_cast<QUmlOutputPin *>(d->result));

        d->result = result;

        // Adjust subsetted property(ies)
        if (result) {
            (qwrappedobject_cast<QUmlActionPrivate *>(d))->addOutput(qwrappedobject_cast<QUmlOutputPin *>(result));
        }
    }
}

/*!
    Gives the input pin from which the link object is obtained.
 */
QUmlInputPin *QUmlReadLinkObjectEndQualifierAction::object() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndQualifierAction);
    return d->object;
}

void QUmlReadLinkObjectEndQualifierAction::setObject(QUmlInputPin *object)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndQualifierAction);
    if (d->object != object) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlActionPrivate *>(d))->removeInput(qwrappedobject_cast<QUmlInputPin *>(d->object));

        d->object = object;

        // Adjust subsetted property(ies)
        if (object) {
            (qwrappedobject_cast<QUmlActionPrivate *>(d))->addInput(qwrappedobject_cast<QUmlInputPin *>(object));
        }
    }
}

/*!
    The attribute representing the qualifier to be read.
 */
QUmlProperty *QUmlReadLinkObjectEndQualifierAction::qualifier() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndQualifierAction);
    return d->qualifier;
}

void QUmlReadLinkObjectEndQualifierAction::setQualifier(QUmlProperty *qualifier)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndQualifierAction);
    if (d->qualifier != qualifier) {
        d->qualifier = qualifier;
    }
}

void QUmlReadLinkObjectEndQualifierAction::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Pin where the result value is placed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlAction::outputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("result")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Gives the input pin from which the link object is obtained.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlAction::inputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("object")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The attribute representing the qualifier to be read.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndQualifierAction")][QString::fromLatin1("qualifier")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlAction::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlreadlinkobjectendqualifieraction.cpp"
