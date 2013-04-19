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
#include "qumlreception.h"
#include "qumlreception_p.h"

#include <QtUml/QUmlSignal>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlReceptionPrivate::QUmlReceptionPrivate() :
    signal(0)
{
}

QUmlReceptionPrivate::~QUmlReceptionPrivate()
{
}

/*!
    \class QUmlReception

    \inmodule QtUml

    \brief A reception is a declaration stating that a classifier is prepared to react to the receipt of a signal. A reception designates a signal and specifies the expected behavioral response. The details of handling a signal are specified by the behavior associated with the reception or the classifier itself.
 */

QUmlReception::QUmlReception(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlBehavioralFeature(*new QUmlReceptionPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlReception::QUmlReception(QUmlReceptionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlBehavioralFeature(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlReception::~QUmlReception()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlReception
// ---------------------------------------------------------------

/*!
    The signal that this reception handles.
 */
QUmlSignal *QUmlReception::signal() const
{
    // This is a read-write association end

    Q_D(const QUmlReception);
    return d->signal;
}

void QUmlReception::setSignal(QUmlSignal *signal)
{
    // This is a read-write association end

    Q_D(QUmlReception);
    if (d->signal != signal) {
        d->signal = signal;
    }
}

void QUmlReception::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The signal that this reception handles.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReception")][QString::fromLatin1("signal")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlBehavioralFeature::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlreception.cpp"
