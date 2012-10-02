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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QTUML_QCALLEVENT_H
#define QTUML_QCALLEVENT_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QMessageEvent>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QCallEventPrivate;
class QOperation;

class Q_UML_EXPORT QCallEvent : public QObject, public QMessageEvent
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComments READ ownedComments)
    Q_PROPERTY(const QList<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QParameterableElement
    Q_PROPERTY(QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)
    Q_PROPERTY(QTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QList<QDependency *> * clientDependencies READ clientDependencies)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QPackageableElement
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)

    // From QCallEvent
    Q_PROPERTY(QOperation * operation READ operation WRITE setOperation)

public:
    explicit QCallEvent(QObject *parent = 0);
    virtual ~QCallEvent();

    // Association-ends (except those derived && !derivedUnion)
    QOperation *operation() const;
    void setOperation(QOperation *operation);

private:
    Q_DISABLE_COPY(QCallEvent)
    Q_DECLARE_PRIVATE(QCallEvent)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QCallEvent *>)
Q_DECLARE_METATYPE(QList<QtUml::QCallEvent *> *)

QT_END_HEADER

#endif // QTUML_QCALLEVENT_H
