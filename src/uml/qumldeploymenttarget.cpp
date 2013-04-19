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
#include "qumldeploymenttarget.h"
#include "qumldeploymenttarget_p.h"

#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlDeployment>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlDeploymentTargetPrivate::QUmlDeploymentTargetPrivate()
{
}

QUmlDeploymentTargetPrivate::~QUmlDeploymentTargetPrivate()
{
}

/*!
    \class QUmlDeploymentTarget

    \inmodule QtUml

    \brief A deployment target is the location for a deployed artifact.
 */

QUmlDeploymentTarget::QUmlDeploymentTarget(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlNamedElement(*new QUmlDeploymentTargetPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlDeploymentTarget::QUmlDeploymentTarget(QUmlDeploymentTargetPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlNamedElement(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlDeploymentTarget::~QUmlDeploymentTarget()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlDeploymentTarget
// ---------------------------------------------------------------

/*!
    The set of elements that are manifested in an Artifact that is involved in Deployment to a DeploymentTarget.
 */
QSet<QUmlPackageableElement *> QUmlDeploymentTarget::deployedElements() const
{
    // This is a read-only derived association end

    qWarning("QUmlDeploymentTarget::deployedElements: to be implemented (this is a derived associationend)");

    return QSet<QUmlPackageableElement *>(); // change here to your derived return
}

/*!
    The set of Deployments for a DeploymentTarget.
 */
QSet<QUmlDeployment *> QUmlDeploymentTarget::deployments() const
{
    // This is a read-write association end

    Q_D(const QUmlDeploymentTarget);
    return d->deployments;
}

void QUmlDeploymentTarget::addDeployment(QUmlDeployment *deployment)
{
    // This is a read-write association end

    Q_D(QUmlDeploymentTarget);
    if (!d->deployments.contains(deployment)) {
        d->deployments.insert(deployment);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QUmlElement *>(deployment));
        (qwrappedobject_cast<QUmlNamedElement *>(this))->addClientDependency(qwrappedobject_cast<QUmlDependency *>(deployment));

        // Adjust opposite property
        deployment->setLocation(this);
    }
}

void QUmlDeploymentTarget::removeDeployment(QUmlDeployment *deployment)
{
    // This is a read-write association end

    Q_D(QUmlDeploymentTarget);
    if (d->deployments.contains(deployment)) {
        d->deployments.remove(deployment);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QUmlElement *>(deployment));
        (qwrappedobject_cast<QUmlNamedElement *>(this))->removeClientDependency(qwrappedobject_cast<QUmlDependency *>(deployment));

        // Adjust opposite property
        deployment->setLocation(0);
    }
}

void QUmlDeploymentTarget::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The set of elements that are manifested in an Artifact that is involved in Deployment to a DeploymentTarget.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployedElements")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The set of Deployments for a DeploymentTarget.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlElement::ownedElements QUmlNamedElement::clientDependencies");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlDeploymentTarget")][QString::fromLatin1("deployments")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUmlDeployment::location");

    QUmlNamedElement::setPropertyData();
}

// Overriden methods for subsetted properties

void QUmlDeploymentTarget::addClientDependency(QWrappedObjectPointer<QUmlDeployment> deployment)
{
    addDeployment(deployment);
}

void QUmlDeploymentTarget::removeClientDependency(QWrappedObjectPointer<QUmlDeployment> deployment)
{
    removeDeployment(deployment);
}

QT_END_NAMESPACE

#include "moc_qumldeploymenttarget.cpp"
