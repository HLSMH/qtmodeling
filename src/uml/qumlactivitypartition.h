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
#ifndef QUMLACTIVITYPARTITION_H
#define QUMLACTIVITYPARTITION_H

#include <QtUml/QtUmlGlobal>

#include <QtUml/QUmlActivityGroup>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlActivityEdge;
class QUmlActivityNode;
class QUmlElement;

class Q_UML_EXPORT QUmlActivityPartition : public QUmlActivityGroup
{
public:
    explicit QUmlActivityPartition(bool createQModelingObject = true);
    virtual ~QUmlActivityPartition();

    virtual QModelingElement *clone() const;

    // Owned attributes
    const QSet<QUmlActivityEdge *> edges() const;
    void addEdge(QUmlActivityEdge *edge);
    void removeEdge(QUmlActivityEdge *edge);
    bool isDimension() const;
    void setDimension(bool isDimension);
    bool isExternal() const;
    void setExternal(bool isExternal);
    const QSet<QUmlActivityNode *> nodes() const;
    void addNode(QUmlActivityNode *node);
    void removeNode(QUmlActivityNode *node);
    QUmlElement *represents() const;
    void setRepresents(QUmlElement *represents);
    const QSet<QUmlActivityPartition *> subpartitions() const;
    void addSubpartition(QUmlActivityPartition *subpartition);
    void removeSubpartition(QUmlActivityPartition *subpartition);
    QUmlActivityPartition *superPartition() const;
    void setSuperPartition(QUmlActivityPartition *superPartition);

protected:
    QSet<QUmlActivityEdge *> _edges;
    bool _isDimension;
    bool _isExternal;
    QSet<QUmlActivityNode *> _nodes;
    QUmlElement *_represents;
    QSet<QUmlActivityPartition *> _subpartitions;
    QUmlActivityPartition *_superPartition;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE(QUmlActivityPartition) *)

#endif // QUMLACTIVITYPARTITION_H

