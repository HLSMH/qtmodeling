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
#ifndef QUMLCONNECTIONPOINTREFERENCEOBJECT_H
#define QUMLCONNECTIONPOINTREFERENCEOBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtModeling/QModelingObject>

#include <QtUml/QtUmlNamespace>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlConnectionPointReference;
class QModelingObjectPrivate;
class Q_UML_EXPORT QUmlConnectionPointReferenceObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QUmlConnectionPointReferenceObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [NamedElement]
    Q_PROPERTY(QSet<QObject *> clientDependencies READ clientDependencies NOTIFY clientDependenciesChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QObject * nameExpression READ nameExpression WRITE setNameExpression NOTIFY nameExpressionChanged)
    Q_PROPERTY(QObject * namespace_ READ namespace_ NOTIFY namespaceChanged)
    Q_PROPERTY(QString qualifiedName READ qualifiedName NOTIFY qualifiedNameChanged STORED false)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility NOTIFY visibilityChanged)

    // Properties [Vertex]
    Q_PROPERTY(QObject * container READ container WRITE setContainer NOTIFY containerChanged)
    Q_PROPERTY(QSet<QObject *> incomings READ incomings NOTIFY incomingsChanged STORED false)
    Q_PROPERTY(QSet<QObject *> outgoings READ outgoings NOTIFY outgoingsChanged STORED false)

    // Properties [ConnectionPointReference]
    Q_PROPERTY(QSet<QObject *> entries READ entries NOTIFY entriesChanged)
    Q_PROPERTY(QSet<QObject *> exits READ exits NOTIFY exitsChanged)
    Q_PROPERTY(QObject * state READ state WRITE setState NOTIFY stateChanged)

public:
    Q_INVOKABLE explicit QUmlConnectionPointReferenceObject(QUmlConnectionPointReference *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [NamedElement]
    Q_INVOKABLE const QSet<QObject *> clientDependencies() const;
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE QObject *nameExpression() const;
    Q_INVOKABLE QObject *namespace_() const;
    Q_INVOKABLE QString qualifiedName() const;
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;

    // Owned attributes [Vertex]
    Q_INVOKABLE QObject *container() const;
    Q_TODO Q_INVOKABLE const QSet<QObject *> incomings() const;
    Q_TODO Q_INVOKABLE const QSet<QObject *> outgoings() const;

    // Owned attributes [ConnectionPointReference]
    Q_INVOKABLE const QSet<QObject *> entries() const;
    Q_INVOKABLE const QSet<QObject *> exits() const;
    Q_INVOKABLE QObject *state() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [NamedElement]
    Q_INVOKABLE QList<QObject *> allNamespaces() const;
    Q_TODO Q_INVOKABLE QSet<QObject *> allOwningPackages() const;
    Q_TODO Q_INVOKABLE bool isDistinguishableFrom(QObject *n, QObject *ns) const;
    Q_INVOKABLE QString separator() const;

    // Operations [Vertex]
    Q_TODO Q_INVOKABLE QObject *containingStateMachine() const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [NamedElement]
    void addClientDependency(QObject *clientDependency);
    void removeClientDependency(QObject *clientDependency);
    void setName(QString name);
    void setNameExpression(QObject *nameExpression = 0);
    void Q_DECL_HIDDEN setNamespace(QObject *namespace_ = 0);
    void Q_DECL_HIDDEN setQualifiedName(QString qualifiedName);
    void setVisibility(QtUml::VisibilityKind visibility);

    // Slots for owned attributes [Vertex]
    void setContainer(QObject *container = 0);
    void Q_DECL_HIDDEN addIncoming(QObject *incoming);
    void Q_DECL_HIDDEN removeIncoming(QObject *incoming);
    void Q_DECL_HIDDEN addOutgoing(QObject *outgoing);
    void Q_DECL_HIDDEN removeOutgoing(QObject *outgoing);

    // Slots for owned attributes [ConnectionPointReference]
    void addEntry(QObject *entry);
    void removeEntry(QObject *entry);
    void addExit(QObject *exit);
    void removeExit(QObject *exit);
    void setState(QObject *state = 0);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [NamedElement]
    void clientDependenciesChanged(QSet<QObject *> clientDependencies);
    void nameChanged(QString name);
    void nameExpressionChanged(QObject *nameExpression);
    void namespaceChanged(QObject *namespace_);
    void qualifiedNameChanged(QString qualifiedName);
    void visibilityChanged(QtUml::VisibilityKind visibility);

    // Signals for owned attributes [Vertex]
    void containerChanged(QObject *container);
    void incomingsChanged(QSet<QObject *> incomings);
    void outgoingsChanged(QSet<QObject *> outgoings);

    // Signals for owned attributes [ConnectionPointReference]
    void entriesChanged(QSet<QObject *> entries);
    void exitsChanged(QSet<QObject *> exits);
    void stateChanged(QObject *state);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QUMLCONNECTIONPOINTREFERENCEOBJECT_H

