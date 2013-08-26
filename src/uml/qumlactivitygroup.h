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
#ifndef QUMLACTIVITYGROUP_H
#define QUMLACTIVITYGROUP_H

#include <QtUml/QtUmlGlobal>

#include <QtUml/QUmlNamedElement>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlActivity;
class QUmlActivityEdge;
class QUmlActivityNode;

class Q_UML_EXPORT QUmlActivityGroup : public virtual QUmlNamedElement
{
public:
    Q_DECL_HIDDEN QUmlActivityGroup();

    // Owned attributes
    QSet<QUmlActivityEdge *> containedEdge() const;
    Q_DECL_HIDDEN void addContainedEdge(QUmlActivityEdge *containedEdge);
    Q_DECL_HIDDEN void removeContainedEdge(QUmlActivityEdge *containedEdge);
    QSet<QUmlActivityNode *> containedNode() const;
    Q_DECL_HIDDEN void addContainedNode(QUmlActivityNode *containedNode);
    Q_DECL_HIDDEN void removeContainedNode(QUmlActivityNode *containedNode);
    QUmlActivity *inActivity() const;
    void setInActivity(QUmlActivity *inActivity);
    QSet<QUmlActivityGroup *> subgroup() const;
    Q_DECL_HIDDEN void addSubgroup(QUmlActivityGroup *subgroup);
    Q_DECL_HIDDEN void removeSubgroup(QUmlActivityGroup *subgroup);
    QUmlActivityGroup *superGroup() const;
    Q_DECL_HIDDEN void setSuperGroup(QUmlActivityGroup *superGroup);

protected:
    QSet<QUmlActivityEdge *> _containedEdge;
    QSet<QUmlActivityNode *> _containedNode;
    QUmlActivity *_inActivity;
    QSet<QUmlActivityGroup *> _subgroup;
    QUmlActivityGroup *_superGroup;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QUmlActivityGroup *)
Q_DECLARE_METATYPE(QList<QUmlActivityGroup *> *)
Q_DECLARE_METATYPE(QSet<QUmlActivityGroup *> *)

QT_END_HEADER

#endif // QUMLACTIVITYGROUP_H

