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
#ifndef QMOFSLOTOBJECT_H
#define QMOFSLOTOBJECT_H

#include <QtMof/QtMofGlobal>

#include <QtModeling/QModelingObject>

QT_BEGIN_NAMESPACE

QT_MODULE(QtMof)

class QMofSlot;
class QModelingObjectPrivate;
class Q_MOF_EXPORT QMofSlotObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QMofSlotObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [Slot]
    Q_PROPERTY(QObject * definingFeature READ definingFeature WRITE setDefiningFeature NOTIFY definingFeatureChanged)
    Q_PROPERTY(QObject * owningInstance READ owningInstance WRITE setOwningInstance NOTIFY owningInstanceChanged)
    Q_PROPERTY(QList<QObject *> values READ values NOTIFY valuesChanged)

public:
    Q_INVOKABLE explicit QMofSlotObject(QMofSlot *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [Slot]
    Q_INVOKABLE QObject *definingFeature() const;
    Q_INVOKABLE QObject *owningInstance() const;
    Q_INVOKABLE const QList<QObject *> values() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;
    Q_TODO Q_INVOKABLE QObject *getMetaClass() const;
    Q_TODO Q_INVOKABLE QObject *container() const;
    Q_TODO Q_INVOKABLE bool isInstanceOfType(QObject *type, bool includesSubtypes) const;
    Q_TODO Q_INVOKABLE void delete_();

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [Slot]
    void setDefiningFeature(QObject *definingFeature = 0);
    void setOwningInstance(QObject *owningInstance = 0);
    void addValue(QObject *value);
    void removeValue(QObject *value);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [Slot]
    void definingFeatureChanged(QObject *definingFeature);
    void owningInstanceChanged(QObject *owningInstance);
    void valuesChanged(QList<QObject *> values);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QMOFSLOTOBJECT_H

