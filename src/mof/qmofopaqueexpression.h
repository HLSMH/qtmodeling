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
#ifndef QMOFOPAQUEEXPRESSION_H
#define QMOFOPAQUEEXPRESSION_H

#include <QtMof/QtMofGlobal>

#include <QtMof/QMofValueSpecification>

QT_BEGIN_NAMESPACE

QT_MODULE(QtMof)

class Q_MOF_EXPORT QMofOpaqueExpression : public QMofValueSpecification
{
public:
    explicit QMofOpaqueExpression(bool createQModelingObject = true);
    virtual ~QMofOpaqueExpression();

    virtual QModelingElement *clone() const;

    // Owned attributes
    const QList<QString> bodies() const;
    void addBody(QString body);
    void removeBody(QString body);
    const QList<QString> languages() const;
    void addLanguage(QString language);
    void removeLanguage(QString language);

    // Operations
    bool isIntegral() const;
    bool isNonNegative() const;
    bool isPositive() const;
    int value() const;

protected:
    QList<QString> _bodies;
    QList<QString> _languages;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE(QMofOpaqueExpression) *)

#endif // QMOFOPAQUEEXPRESSION_H

