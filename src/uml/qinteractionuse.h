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
#ifndef QTUML_QINTERACTIONUSE_H
#define QTUML_QINTERACTIONUSE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QInteractionFragment>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QProperty;
class QInteraction;
class QGate;
class QValueSpecification;

class QInteractionUsePrivate;

class Q_UML_EXPORT QInteractionUse : public QInteractionFragment
{
    Q_OBJECT

    Q_PROPERTY(const QSet<QGate *> * actualGates READ actualGates)
    Q_PROPERTY(QValueSpecification * returnValue READ returnValue WRITE setReturnValue)
    Q_PROPERTY(QInteraction * refersTo READ refersTo WRITE setRefersTo)
    Q_PROPERTY(const QList<QValueSpecification *> * arguments READ arguments)
    Q_PROPERTY(QProperty * returnValueRecipient READ returnValueRecipient WRITE setReturnValueRecipient)

    Q_DISABLE_COPY(QInteractionUse)
    Q_DECLARE_PRIVATE(QInteractionUse)

public:
    explicit QInteractionUse(QObject *parent = 0);
    virtual ~QInteractionUse();

    // Association ends from QInteractionUse
    const QSet<QGate *> *actualGates() const;
    void addActualGate(QGate *actualGate);
    void removeActualGate(QGate *actualGate);
    QValueSpecification *returnValue() const;
    void setReturnValue(QValueSpecification *returnValue);
    QInteraction *refersTo() const;
    void setRefersTo(QInteraction *refersTo);
    const QList<QValueSpecification *> *arguments() const;
    void addArgument(QValueSpecification *argument);
    void removeArgument(QValueSpecification *argument);
    QProperty *returnValueRecipient() const;
    void setReturnValueRecipient(QProperty *returnValueRecipient);

protected:
    explicit QInteractionUse(QInteractionUsePrivate &dd, QObject *parent = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QInteractionUse) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QInteractionUse) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QInteractionUse) *> *)

QT_END_HEADER

#endif // QTUML_QINTERACTIONUSE_H

