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
#ifndef QTUML_QEXTEND_H
#define QTUML_QEXTEND_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QDirectedRelationship>
#include <QtUml/QNamedElement>

// Qt includes
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QExtendPrivate;
class QConstraint;
class QUseCase;
class QExtensionPoint;

class Q_UML_EXPORT QExtend : public QObject, public QDirectedRelationship, public QNamedElement
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComments READ ownedComments)
    Q_PROPERTY(const QList<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QRelationship
    Q_PROPERTY(const QList<QElement *> * relatedElements READ relatedElements)

    // From QDirectedRelationship
    Q_PROPERTY(const QList<QElement *> * sources READ sources)
    Q_PROPERTY(const QList<QElement *> * targets READ targets)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QList<QDependency *> * clientDependencies READ clientDependencies)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QExtend
    Q_PROPERTY(QConstraint * condition READ condition WRITE setCondition)
    Q_PROPERTY(QUseCase * extendedCase READ extendedCase WRITE setExtendedCase)
    Q_PROPERTY(QUseCase * extension READ extension WRITE setExtension)
    Q_PROPERTY(QList<QExtensionPoint *> * extensionLocations READ extensionLocations)

public:
    explicit QExtend(QObject *parent = 0);
    virtual ~QExtend();

    // Association-ends (except those derived && !derivedUnion)
    QConstraint *condition() const;
    void setCondition(QConstraint *condition);
    QUseCase *extendedCase() const;
    void setExtendedCase(QUseCase *extendedCase);
    QUseCase *extension() const;
    void setExtension(QUseCase *extension);
    QList<QExtensionPoint *> *extensionLocations();

private:
    Q_DISABLE_COPY(QExtend)
    Q_DECLARE_PRIVATE(QExtend)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QExtend *>)
Q_DECLARE_METATYPE(QList<QtUml::QExtend *> *)

QT_END_HEADER

#endif // QTUML_QEXTEND_H
