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
#include "umllifeline_p.h"

#include "private/umlconnectableelement_p.h"
#include "private/umlinteraction_p.h"
#include "private/umlinteractionfragment_p.h"
#include "private/umlpartdecomposition_p.h"
#include "private/umlvaluespecification_p.h"

/*!
    \class UmlLifeline

    \inmodule QtUml

    \brief A lifeline represents an individual participant in the interaction. While parts and structural features may have multiplicity greater than 1, lifelines represent only one interacting entity.
 */

UmlLifeline::UmlLifeline() :
    _decomposedAs(0),
    _interaction(0),
    _represents(0),
    _selector(0)
{
}

// OWNED ATTRIBUTES

/*!
    References the InteractionFragments in which this Lifeline takes part.
 */
const QSet<UmlInteractionFragment *> UmlLifeline::coveredBy() const
{
    // This is a read-write association end

    return _coveredBy;
}

void UmlLifeline::addCoveredBy(UmlInteractionFragment *coveredBy)
{
    // This is a read-write association end

    if (!_coveredBy.contains(coveredBy)) {
        _coveredBy.insert(coveredBy);

        // Adjust opposite properties
        if (coveredBy) {
            coveredBy->addCovered(this);
        }
    }
}

void UmlLifeline::removeCoveredBy(UmlInteractionFragment *coveredBy)
{
    // This is a read-write association end

    if (_coveredBy.contains(coveredBy)) {
        _coveredBy.remove(coveredBy);

        // Adjust opposite properties
        if (coveredBy) {
            coveredBy->removeCovered(this);
        }
    }
}

/*!
    References the Interaction that represents the decomposition.
 */
UmlPartDecomposition *UmlLifeline::decomposedAs() const
{
    // This is a read-write association end

    return _decomposedAs;
}

void UmlLifeline::setDecomposedAs(UmlPartDecomposition *decomposedAs)
{
    // This is a read-write association end

    if (_decomposedAs != decomposedAs) {
        _decomposedAs = decomposedAs;
    }
}

/*!
    References the Interaction enclosing this Lifeline.
 */
UmlInteraction *UmlLifeline::interaction() const
{
    // This is a read-write association end

    return _interaction;
}

void UmlLifeline::setInteraction(UmlInteraction *interaction)
{
    // This is a read-write association end

    if (_interaction != interaction) {
        // Adjust subsetted properties

        _interaction = interaction;

        // Adjust subsetted properties
        setNamespace(interaction);
    }
}

/*!
    References the ConnectableElement within the classifier that contains the enclosing interaction.
 */
UmlConnectableElement *UmlLifeline::represents() const
{
    // This is a read-write association end

    return _represents;
}

void UmlLifeline::setRepresents(UmlConnectableElement *represents)
{
    // This is a read-write association end

    if (_represents != represents) {
        _represents = represents;
    }
}

/*!
    If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
 */
UmlValueSpecification *UmlLifeline::selector() const
{
    // This is a read-write association end

    return _selector;
}

void UmlLifeline::setSelector(UmlValueSpecification *selector)
{
    // This is a read-write association end

    if (_selector != selector) {
        // Adjust subsetted properties
        removeOwnedElement(_selector);

        _selector = selector;

        // Adjust subsetted properties
        if (selector) {
            addOwnedElement(selector);
        }
    }
}
