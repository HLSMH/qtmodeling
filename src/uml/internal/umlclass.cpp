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
#include "umlclass_p.h"

#include "private/umlclassifier_p.h"
#include "private/umlextension_p.h"
#include "private/umlnamedelement_p.h"
#include "private/umloperation_p.h"
#include "private/umlproperty_p.h"
#include "private/umlreception_p.h"

/*!
    \class UmlClass

    \inmodule QtUml

    \brief A class may be designated as active (i.e., each of its instances having its own thread of control) or passive (i.e., each of its instances executing within the context of some other object). A class may also specify which signals the instances of this class handle.A class describes a set of objects that share the same specifications of features, constraints, and semantics.A class has the capability to have an internal structure and ports.Class has derived association that indicates how it may be extended through one or more stereotypes. Stereotype is the only kind of metaclass that cannot be extended by stereotypes.
 */

UmlClass::UmlClass() :
    _isAbstract(false),
    _isActive(false)
{
}

// OWNED ATTRIBUTES

/*!
    References the Extensions that specify additional properties of the metaclass. The property is derived from the extensions whose memberEnds are typed by the Class.
 */
const QSet<UmlExtension *> UmlClass::extension() const
{
    // This is a read-only derived association end

    qWarning("UmlClass::extension(): to be implemented (this is a derived association end)");

    return QSet<UmlExtension *>();
}

void UmlClass::addExtension(UmlExtension *extension)
{
    // This is a read-only derived association end

    qWarning("UmlClass::extension(): to be implemented (this is a derived association end)");
    Q_UNUSED(extension);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust opposite properties
        if (extension) {
            extension->setMetaclass(this);
        }
    }
}

void UmlClass::removeExtension(UmlExtension *extension)
{
    // This is a read-only derived association end

    qWarning("UmlClass::extension(): to be implemented (this is a derived association end)");
    Q_UNUSED(extension);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust opposite properties
        if (extension) {
            extension->setMetaclass(0);
        }
    }
}

/*!
    If true, the Classifier does not provide a complete declaration and can typically not be instantiated. An abstract classifier is intended to be used by other classifiers e.g. as the target of general metarelationships or generalization relationships.True when a class is abstract.
 */
bool UmlClass::isAbstract() const
{
    // This is a read-write property

    return _isAbstract;
}

void UmlClass::setAbstract(bool isAbstract)
{
    // This is a read-write property

    if (_isAbstract != isAbstract) {
        _isAbstract = isAbstract;
    }
}

/*!
    Determines whether an object specified by this class is active or not. If true, then the owning class is referred to as an active class. If false, then such a class is referred to as a passive class.
 */
bool UmlClass::isActive() const
{
    // This is a read-write property

    return _isActive;
}

void UmlClass::setActive(bool isActive)
{
    // This is a read-write property

    if (_isActive != isActive) {
        _isActive = isActive;
    }
}

/*!
    References all the Classifiers that are defined (nested) within the Class.
 */
const QList<UmlClassifier *> UmlClass::nestedClassifier() const
{
    // This is a read-write association end

    return _nestedClassifier;
}

void UmlClass::addNestedClassifier(UmlClassifier *nestedClassifier)
{
    // This is a read-write association end

    if (!_nestedClassifier.contains(nestedClassifier)) {
        _nestedClassifier.append(nestedClassifier);

        // Adjust subsetted properties
        addOwnedMember(nestedClassifier);
    }
}

void UmlClass::removeNestedClassifier(UmlClassifier *nestedClassifier)
{
    // This is a read-write association end

    if (_nestedClassifier.contains(nestedClassifier)) {
        _nestedClassifier.removeAll(nestedClassifier);

        // Adjust subsetted properties
        removeOwnedMember(nestedClassifier);
    }
}

/*!
    The attributes (i.e. the properties) owned by the class.
 */
const QList<UmlProperty *> UmlClass::ownedAttribute() const
{
    // This is a read-write association end

    return _ownedAttribute;
}

void UmlClass::addOwnedAttribute(UmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (!_ownedAttribute.contains(ownedAttribute)) {
        _ownedAttribute.append(ownedAttribute);

        // Adjust subsetted properties
        addOwnedMember(ownedAttribute);
        addAttribute(ownedAttribute);

        // Adjust opposite properties
        if (ownedAttribute) {
            ownedAttribute->setClass(this);
        }
    }
}

void UmlClass::removeOwnedAttribute(UmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (_ownedAttribute.contains(ownedAttribute)) {
        _ownedAttribute.removeAll(ownedAttribute);

        // Adjust subsetted properties
        removeOwnedMember(ownedAttribute);
        removeAttribute(ownedAttribute);

        // Adjust opposite properties
        if (ownedAttribute) {
            ownedAttribute->setClass(0);
        }
    }
}

/*!
    The operations owned by the class.
 */
const QList<UmlOperation *> UmlClass::ownedOperation() const
{
    // This is a read-write association end

    return _ownedOperation;
}

void UmlClass::addOwnedOperation(UmlOperation *ownedOperation)
{
    // This is a read-write association end

    if (!_ownedOperation.contains(ownedOperation)) {
        _ownedOperation.append(ownedOperation);

        // Adjust subsetted properties
        addFeature(ownedOperation);
        addOwnedMember(ownedOperation);

        // Adjust opposite properties
        if (ownedOperation) {
            ownedOperation->setClass(this);
        }
    }
}

void UmlClass::removeOwnedOperation(UmlOperation *ownedOperation)
{
    // This is a read-write association end

    if (_ownedOperation.contains(ownedOperation)) {
        _ownedOperation.removeAll(ownedOperation);

        // Adjust subsetted properties
        removeFeature(ownedOperation);
        removeOwnedMember(ownedOperation);

        // Adjust opposite properties
        if (ownedOperation) {
            ownedOperation->setClass(0);
        }
    }
}

/*!
    Receptions that objects of this class are willing to accept.
 */
const QSet<UmlReception *> UmlClass::ownedReception() const
{
    // This is a read-write association end

    return _ownedReception;
}

void UmlClass::addOwnedReception(UmlReception *ownedReception)
{
    // This is a read-write association end

    if (!_ownedReception.contains(ownedReception)) {
        _ownedReception.insert(ownedReception);

        // Adjust subsetted properties
        addFeature(ownedReception);
        addOwnedMember(ownedReception);
    }
}

void UmlClass::removeOwnedReception(UmlReception *ownedReception)
{
    // This is a read-write association end

    if (_ownedReception.contains(ownedReception)) {
        _ownedReception.remove(ownedReception);

        // Adjust subsetted properties
        removeFeature(ownedReception);
        removeOwnedMember(ownedReception);
    }
}

/*!
    This gives the superclasses of a class.
 */
const QSet<UmlClass *> UmlClass::superClass() const
{
    // This is a read-write derived association end

    qWarning("UmlClass::superClass(): to be implemented (this is a derived association end)");

    return QSet<UmlClass *>();
}

void UmlClass::addSuperClass(UmlClass *superClass)
{
    // This is a read-write derived association end

    qWarning("UmlClass::superClass(): to be implemented (this is a derived association end)");
    Q_UNUSED(superClass);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void UmlClass::removeSuperClass(UmlClass *superClass)
{
    // This is a read-write derived association end

    qWarning("UmlClass::superClass(): to be implemented (this is a derived association end)");
    Q_UNUSED(superClass);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

// OPERATIONS

/*!
    The inherit operation is overridden to exclude redefined properties.
 */
QSet<UmlNamedElement *> UmlClass::inherit(
    QSet<UmlNamedElement *> inhs) const
{
    qWarning("UmlClass::inherit(): to be implemented (operation)");

    Q_UNUSED(inhs);
    return QSet<UmlNamedElement *> ();
}
