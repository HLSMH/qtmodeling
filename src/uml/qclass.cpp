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
** rights. These rights are described in the Nokia Qt LGPL Exception
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

#include "qclass.h"
#include "qclass_p.h"
#include "qnamespace_p.h"
#include "qclassifier_p.h"
#include "qnamespace_p.h"
#include "qclassifier_p.h"
#include "qnamespace_p.h"
#include "qnamespace_p.h"
#include "qclassifier_p.h"

#include <QtUml/QReception>
#include <QtUml/QNamedElement>
#include <QtUml/QOperation>
#include <QtUml/QClassifier>
#include <QtUml/QExtension>
#include <QtUml/QProperty>

QT_BEGIN_NAMESPACE_QTUML

QClassPrivate::QClassPrivate() :
    isAbstract(false),
    isActive(false),
    nestedClassifiers(new QList<QClassifier *>),
    ownedReceptions(new QSet<QReception *>),
    ownedOperations(new QList<QOperation *>),
    ownedAttributes(new QList<QProperty *>)
{
}

QClassPrivate::~QClassPrivate()
{
    delete nestedClassifiers;
    delete ownedReceptions;
    delete ownedOperations;
    delete ownedAttributes;
}

void QClassPrivate::setAbstract(bool isAbstract)
{
    this->isAbstract = isAbstract;
}

void QClassPrivate::setActive(bool isActive)
{
    this->isActive = isActive;
}
  
void QClassPrivate::addNestedClassifier(const QClassifier *nestedClassifier) 
{   
    this->nestedClassifiers->append(const_cast<QClassifier *>(nestedClassifier)); 

    // Adjust subsetted property(ies)
    addOwnedMember(nestedClassifier); 
}
 
void QClassPrivate::removeNestedClassifier(const QClassifier *nestedClassifier) 
{    
    this->nestedClassifiers->removeAll(const_cast<QClassifier *>(nestedClassifier)); 

    // Adjust subsetted property(ies)
    removeOwnedMember(nestedClassifier);
}
  
void QClassPrivate::addOwnedReception(const QReception *ownedReception) 
{   
    this->ownedReceptions->insert(const_cast<QReception *>(ownedReception)); 

    // Adjust subsetted property(ies)
    addFeature(ownedReception);
    addOwnedMember(ownedReception); 
}
 
void QClassPrivate::removeOwnedReception(const QReception *ownedReception) 
{    
    this->ownedReceptions->remove(const_cast<QReception *>(ownedReception)); 

    // Adjust subsetted property(ies)
    removeFeature(ownedReception);
    removeOwnedMember(ownedReception);
}
   
void QClassPrivate::addOwnedOperation(const QOperation *ownedOperation) 
{   
    this->ownedOperations->append(const_cast<QOperation *>(ownedOperation)); 

    // Adjust subsetted property(ies)
    addFeature(ownedOperation);
    addOwnedMember(ownedOperation); 
}
 
void QClassPrivate::removeOwnedOperation(const QOperation *ownedOperation) 
{    
    this->ownedOperations->removeAll(const_cast<QOperation *>(ownedOperation)); 

    // Adjust subsetted property(ies)
    removeFeature(ownedOperation);
    removeOwnedMember(ownedOperation);
}
  
void QClassPrivate::addOwnedAttribute(const QProperty *ownedAttribute) 
{   
    this->ownedAttributes->append(const_cast<QProperty *>(ownedAttribute)); 

    // Adjust subsetted property(ies)
    addOwnedMember(ownedAttribute);
    addAttribute(ownedAttribute); 
}
 
void QClassPrivate::removeOwnedAttribute(const QProperty *ownedAttribute) 
{    
    this->ownedAttributes->removeAll(const_cast<QProperty *>(ownedAttribute)); 

    // Adjust subsetted property(ies)
    removeOwnedMember(ownedAttribute);
    removeAttribute(ownedAttribute);
}
 
/*!
    \class QClass

    \inmodule QtUml

    \brief A class may be designated as active (i.e., each of its instances having its own thread of control) or passive (i.e., each of its instances executing within the context of some other object). A class may also specify which signals the instances of this class handle.A class describes a set of objects that share the same specifications of features, constraints, and semantics.A class has the capability to have an internal structure and ports.Class has derived association that indicates how it may be extended through one or more stereotypes. Stereotype is the only kind of metaclass that cannot be extended by stereotypes.
 */

QClass::QClass(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QClassPrivate;
}

QClass::QClass(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QClassPrivate;
}

QClass::~QClass()
{
}

/*!
    If true, the Classifier does not provide a complete declaration and can typically not be instantiated. An abstract classifier is intended to be used by other classifiers e.g. as the target of general metarelationships or generalization relationships.True when a class is abstract.
 */
bool QClass::isAbstract() const
{
    Q_D(const QClass);
    return d->isAbstract;
}

void QClass::setAbstract(bool isAbstract)
{
    Q_D(QClass);
    d->setAbstract(isAbstract);
}

/*!
    Determines whether an object specified by this class is active or not. If true, then the owning class is referred to as an active class. If false, then such a class is referred to as a passive class.
 */
bool QClass::isActive() const
{
    Q_D(const QClass);
    return d->isActive;
}

void QClass::setActive(bool isActive)
{
    Q_D(QClass);
    d->setActive(isActive);
}

/*!
    References all the Classifiers that are defined (nested) within the Class.
 */
const QList<QClassifier *> *QClass::nestedClassifiers() const
{
    Q_D(const QClass);
    return d->nestedClassifiers;
}

void QClass::addNestedClassifier(const QClassifier *nestedClassifier)
{
    Q_D(QClass);
    d->addNestedClassifier(const_cast<QClassifier *>(nestedClassifier));
}

void QClass::removeNestedClassifier(const QClassifier *nestedClassifier)
{
    Q_D(QClass);
    d->removeNestedClassifier(const_cast<QClassifier *>(nestedClassifier));
}

/*!
    Receptions that objects of this class are willing to accept.
 */
const QSet<QReception *> *QClass::ownedReceptions() const
{
    Q_D(const QClass);
    return d->ownedReceptions;
}

void QClass::addOwnedReception(const QReception *ownedReception)
{
    Q_D(QClass);
    d->addOwnedReception(const_cast<QReception *>(ownedReception));
}

void QClass::removeOwnedReception(const QReception *ownedReception)
{
    Q_D(QClass);
    d->removeOwnedReception(const_cast<QReception *>(ownedReception));
}

/*!
    References the Extensions that specify additional properties of the metaclass. The property is derived from the extensions whose memberEnds are typed by the Class.
 */
const QSet<QExtension *> *QClass::extensions() const
{
    qWarning("QClass::extensions: to be implemented (this is a derived associationend)");
}

/*!
    The operations owned by the class.
 */
const QList<QOperation *> *QClass::ownedOperations() const
{
    Q_D(const QClass);
    return d->ownedOperations;
}

void QClass::addOwnedOperation(const QOperation *ownedOperation)
{
    Q_D(QClass);
    d->addOwnedOperation(const_cast<QOperation *>(ownedOperation));
}

void QClass::removeOwnedOperation(const QOperation *ownedOperation)
{
    Q_D(QClass);
    d->removeOwnedOperation(const_cast<QOperation *>(ownedOperation));
}

/*!
    The attributes (i.e. the properties) owned by the class.
 */
const QList<QProperty *> *QClass::ownedAttributes() const
{
    Q_D(const QClass);
    return d->ownedAttributes;
}

void QClass::addOwnedAttribute(const QProperty *ownedAttribute)
{
    Q_D(QClass);
    d->addOwnedAttribute(const_cast<QProperty *>(ownedAttribute));
}

void QClass::removeOwnedAttribute(const QProperty *ownedAttribute)
{
    Q_D(QClass);
    d->removeOwnedAttribute(const_cast<QProperty *>(ownedAttribute));
}

/*!
    This gives the superclasses of a class.
 */
const QSet<QClass *> *QClass::superClasses() const
{
    qWarning("QClass::superClasses: to be implemented (this is a derived associationend)");
}

void QClass::addSuperClass(const QClass *superClass)
{
    qWarning("QClass::addSuperClass: to be implemented (this is a derived associationend)");
}

void QClass::removeSuperClass(const QClass *superClass)
{
    qWarning("QClass::removeSuperClass: to be implemented (this is a derived associationend)");
}

/*!
    The inherit operation is overridden to exclude redefined properties.
 */
const QSet<QNamedElement *> *QClass::inherit(const QSet<QNamedElement *> *inhs) const
{
    qWarning("QClass::inherit: operation to be implemented");
}

#include "moc_qclass.cpp"

QT_END_NAMESPACE_QTUML

