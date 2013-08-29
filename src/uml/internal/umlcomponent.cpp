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
#include "umlcomponent_p.h"

#include "private/umlclassifier_p.h"
#include "private/umlcomponentrealization_p.h"
#include "private/umlinterface_p.h"
#include "private/umlpackageableelement_p.h"

/*!
    \class UmlComponent

    \inmodule QtUml

    \brief In the namespace of a component, all model elements that are involved in or related to its definition are either owned or imported explicitly. This may include, for example, use cases and dependencies (e.g. mappings), packages, components, and artifacts.A component represents a modular part of a system that encapsulates its contents and whose manifestation is replaceable within its environment.
 */

UmlComponent::UmlComponent() :
    _isIndirectlyInstantiated(true)
{
}

// OWNED ATTRIBUTES

/*!
    isIndirectlyInstantiated : Boolean {default = true} The kind of instantiation that applies to a Component. If false, the component is instantiated as an addressable object. If true, the Component is defined at design-time, but at run-time (or execution-time) an object specified by the Component does not exist, that is, the component is instantiated indirectly, through the instantiation of its realizing classifiers or parts. Several standard stereotypes use this meta attribute (e.g., �specification�, �focus�, �subsystem�).
 */
bool UmlComponent::isIndirectlyInstantiated() const
{
    // This is a read-write property

    return _isIndirectlyInstantiated;
}

void UmlComponent::setIndirectlyInstantiated(bool isIndirectlyInstantiated)
{
    // This is a read-write property

    if (_isIndirectlyInstantiated != isIndirectlyInstantiated) {
        _isIndirectlyInstantiated = isIndirectlyInstantiated;
    }
}

/*!
    The set of PackageableElements that a Component owns. In the namespace of a component, all model elements that are involved in or related to its definition may be owned or imported explicitly. These may include e.g. Classes, Interfaces, Components, Packages, Use cases, Dependencies (e.g. mappings), and Artifacts.
 */
const QSet<UmlPackageableElement *> UmlComponent::packagedElement() const
{
    // This is a read-write association end

    return _packagedElement;
}

void UmlComponent::addPackagedElement(UmlPackageableElement *packagedElement)
{
    // This is a read-write association end

    if (!_packagedElement.contains(packagedElement)) {
        _packagedElement.insert(packagedElement);

        // Adjust subsetted properties
        addOwnedMember(packagedElement);
    }
}

void UmlComponent::removePackagedElement(UmlPackageableElement *packagedElement)
{
    // This is a read-write association end

    if (_packagedElement.contains(packagedElement)) {
        _packagedElement.remove(packagedElement);

        // Adjust subsetted properties
        removeOwnedMember(packagedElement);
    }
}

/*!
    The interfaces that the component exposes to its environment. These interfaces may be Realized by the Component or any of its realizingClassifiers, or they may be the Interfaces that are provided by its public Ports.
 */
const QSet<UmlInterface *> UmlComponent::provided() const
{
    // This is a read-only derived association end

    qWarning("UmlComponent::provided(): to be implemented (this is a derived association end)");

    return QSet<UmlInterface *>();
}

void UmlComponent::addProvided(UmlInterface *provided)
{
    // This is a read-only derived association end

    qWarning("UmlComponent::provided(): to be implemented (this is a derived association end)");
    Q_UNUSED(provided);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void UmlComponent::removeProvided(UmlInterface *provided)
{
    // This is a read-only derived association end

    qWarning("UmlComponent::provided(): to be implemented (this is a derived association end)");
    Q_UNUSED(provided);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The set of Realizations owned by the Component. Realizations reference the Classifiers of which the Component is an abstraction; i.e., that realize its behavior.
 */
const QSet<UmlComponentRealization *> UmlComponent::realization() const
{
    // This is a read-write association end

    return _realization;
}

void UmlComponent::addRealization(UmlComponentRealization *realization)
{
    // This is a read-write association end

    if (!_realization.contains(realization)) {
        _realization.insert(realization);

        // Adjust subsetted properties
        addOwnedElement(realization);

        // Adjust opposite properties
        if (realization) {
            realization->setAbstraction(this);
        }
    }
}

void UmlComponent::removeRealization(UmlComponentRealization *realization)
{
    // This is a read-write association end

    if (_realization.contains(realization)) {
        _realization.remove(realization);

        // Adjust subsetted properties
        removeOwnedElement(realization);

        // Adjust opposite properties
        if (realization) {
            realization->setAbstraction(0);
        }
    }
}

/*!
    The interfaces that the component requires from other components in its environment in order to be able to offer its full set of provided functionality. These interfaces may be used by the Component or any of its realizingClassifiers, or they may be the Interfaces that are required by its public Ports.
 */
const QSet<UmlInterface *> UmlComponent::required() const
{
    // This is a read-only derived association end

    qWarning("UmlComponent::required(): to be implemented (this is a derived association end)");

    return QSet<UmlInterface *>();
}

void UmlComponent::addRequired(UmlInterface *required)
{
    // This is a read-only derived association end

    qWarning("UmlComponent::required(): to be implemented (this is a derived association end)");
    Q_UNUSED(required);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void UmlComponent::removeRequired(UmlInterface *required)
{
    // This is a read-only derived association end

    qWarning("UmlComponent::required(): to be implemented (this is a derived association end)");
    Q_UNUSED(required);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

// OPERATIONS

/*!
    Utility returning the set of realized interfaces of a component.
 */
QSet<UmlInterface *> UmlComponent::realizedInterfaces(
    UmlClassifier *classifier) const
{
    qWarning("UmlComponent::realizedInterfaces(): to be implemented (operation)");

    Q_UNUSED(classifier);
    return QSet<UmlInterface *> ();
}

/*!
    Utility returning the set of used interfaces of a component.
 */
QSet<UmlInterface *> UmlComponent::usedInterfaces(
    UmlClassifier *classifier) const
{
    qWarning("UmlComponent::usedInterfaces(): to be implemented (operation)");

    Q_UNUSED(classifier);
    return QSet<UmlInterface *> ();
}
