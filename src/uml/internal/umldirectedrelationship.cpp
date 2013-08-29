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
#include "umldirectedrelationship_p.h"

#include "private/umlelement_p.h"

/*!
    \class UmlDirectedRelationship

    \inmodule QtUml

    \brief A directed relationship represents a relationship between a collection of source model elements and a collection of target model elements.
 */

UmlDirectedRelationship::UmlDirectedRelationship()
{
}

// OWNED ATTRIBUTES

/*!
    Specifies the sources of the DirectedRelationship.
 */
const QSet<UmlElement *> UmlDirectedRelationship::source() const
{
    // This is a read-only derived union association end

    return _source;
}

void UmlDirectedRelationship::addSource(UmlElement *source)
{
    // This is a read-only derived union association end

    if (!_source.contains(source)) {
        _source.insert(source);

        // Adjust subsetted properties
        addRelatedElement(source);
    }
}

void UmlDirectedRelationship::removeSource(UmlElement *source)
{
    // This is a read-only derived union association end

    if (_source.contains(source)) {
        _source.remove(source);

        // Adjust subsetted properties
        removeRelatedElement(source);
    }
}

/*!
    Specifies the targets of the DirectedRelationship.
 */
const QSet<UmlElement *> UmlDirectedRelationship::target() const
{
    // This is a read-only derived union association end

    return _target;
}

void UmlDirectedRelationship::addTarget(UmlElement *target)
{
    // This is a read-only derived union association end

    if (!_target.contains(target)) {
        _target.insert(target);

        // Adjust subsetted properties
        addRelatedElement(target);
    }
}

void UmlDirectedRelationship::removeTarget(UmlElement *target)
{
    // This is a read-only derived union association end

    if (_target.contains(target)) {
        _target.remove(target);

        // Adjust subsetted properties
        removeRelatedElement(target);
    }
}
