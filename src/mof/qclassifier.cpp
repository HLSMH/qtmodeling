/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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

#include "qclassifier.h"
#include "qclassifier_p.h"

#include "qfeature_p.h"

#include <QtMof/QGeneralization>
#include <QtMof/QNamedElement>
#include <QtMof/QProperty>
#include <QtMof/QFeature>

QT_BEGIN_NAMESPACE_QTMOF

QClassifierPrivate::QClassifierPrivate() :
    isAbstract(false),
    isFinalSpecialization(false),
    attributes(new QSet<QProperty *>),
    features(new QSet<QFeature *>),
    redefinedClassifiers(new QSet<QClassifier *>),
    generalizations(new QSet<QGeneralization *>)
{
}

QClassifierPrivate::~QClassifierPrivate()
{
    delete attributes;
    delete features;
    delete redefinedClassifiers;
    delete generalizations;
}

void QClassifierPrivate::addAttribute(QProperty *attribute)
{
    // This is a read-only derived-union association end

    if (!this->attributes->contains(attribute)) {
        this->attributes->insert(attribute);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(this))->addFeature(qmofobject_cast<QFeature *>(attribute));
    }
}

void QClassifierPrivate::removeAttribute(QProperty *attribute)
{
    // This is a read-only derived-union association end

    if (this->attributes->contains(attribute)) {
        this->attributes->remove(attribute);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(this))->removeFeature(qmofobject_cast<QFeature *>(attribute));
    }
}

void QClassifierPrivate::addFeature(QFeature *feature)
{
    // This is a read-only derived-union association end

    if (!this->features->contains(feature)) {
        this->features->insert(feature);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamespacePrivate *>(this))->addMember(qmofobject_cast<QNamedElement *>(feature));

        // Adjust opposite property
        Q_Q(QClassifier);
        (qmofobject_cast<QFeaturePrivate *>(feature->d_func()))->addFeaturingClassifier(q);
    }
}

void QClassifierPrivate::removeFeature(QFeature *feature)
{
    // This is a read-only derived-union association end

    if (this->features->contains(feature)) {
        this->features->remove(feature);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamespacePrivate *>(this))->removeMember(qmofobject_cast<QNamedElement *>(feature));

        // Adjust opposite property
        Q_Q(QClassifier);
        if (feature)
            (qmofobject_cast<QFeaturePrivate *>(feature->d_func()))->removeFeaturingClassifier(q);
    }
}

/*!
    \class QClassifier

    \inmodule QtMof

    \brief A classifier is a classification of instances - it describes a set of instances that have features in common. A classifier can specify a generalization hierarchy by referencing its general classifiers.
 */

QClassifier::QClassifier(QMofObject *parent, QMofObject *wrapper) :
    QMofObject(*new QClassifierPrivate, parent, wrapper),
    _wrappedType(new QType(this, this)),
    _wrappedRedefinableElement(new QRedefinableElement(this, this)),
    _wrappedNamespace(new QNamespace(this, this))
{
}

QClassifier::QClassifier(QClassifierPrivate &dd, QMofObject *parent, QMofObject *wrapper) :
    QMofObject(dd, parent, wrapper),
    _wrappedType(new QType(this, this)),
    _wrappedRedefinableElement(new QRedefinableElement(this, this)),
    _wrappedNamespace(new QNamespace(this, this))
{
}

QClassifier::~QClassifier()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QClassifier::ownedElements() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QClassifier::owner() const
{
    return (qmofobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QClassifier::ownedComments() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedComments();
}

void QClassifier::addOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QClassifier::removeOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QClassifier::name() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->name();
}

void QClassifier::setName(QString name)
{
    (qmofobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QClassifier::qualifiedName() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QClassifier::namespace_() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->namespace_();
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QPackageableElement
// ---------------------------------------------------------------

/*!
    Indicates that packageable elements must always have a visibility, i.e., visibility is not optional.
 */
QtMof::VisibilityKind QClassifier::visibility() const
{
    return (qmofobject_cast<const QPackageableElement *>(this))->visibility();
}

void QClassifier::setVisibility(QtMof::VisibilityKind visibility)
{
    (qmofobject_cast<QPackageableElement *>(this))->setVisibility(visibility);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QType
// ---------------------------------------------------------------

/*!
    Specifies the owning package of this classifier, if any.
 */
QPackage *QClassifier::package() const
{
    return (qmofobject_cast<const QType *>(this))->package();
}

void QClassifier::setPackage(QPackage *package)
{
    (qmofobject_cast<QType *>(this))->setPackage(package);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QClassifier::isLeaf() const
{
    return (qmofobject_cast<const QRedefinableElement *>(this))->isLeaf();
}

void QClassifier::setLeaf(bool isLeaf)
{
    (qmofobject_cast<QRedefinableElement *>(this))->setLeaf(isLeaf);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
const QSet<QRedefinableElement *> *QClassifier::redefinedElements() const
{
    return (qmofobject_cast<const QRedefinableElement *>(this))->redefinedElements();
}

/*!
    References the contexts that this element may be redefined from.
 */
const QSet<QClassifier *> *QClassifier::redefinitionContexts() const
{
    return (qmofobject_cast<const QRedefinableElement *>(this))->redefinitionContexts();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamespace
// ---------------------------------------------------------------

/*!
    References the PackageImports owned by the Namespace.
 */
const QSet<QPackageImport *> *QClassifier::packageImports() const
{
    return (qmofobject_cast<const QNamespace *>(this))->packageImports();
}

void QClassifier::addPackageImport(QPackageImport *packageImport)
{
    (qmofobject_cast<QNamespace *>(this))->addPackageImport(packageImport);
}

void QClassifier::removePackageImport(QPackageImport *packageImport)
{
    (qmofobject_cast<QNamespace *>(this))->removePackageImport(packageImport);
}

/*!
    A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
 */
const QSet<QNamedElement *> *QClassifier::members() const
{
    return (qmofobject_cast<const QNamespace *>(this))->members();
}

/*!
    References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
 */
const QSet<QPackageableElement *> *QClassifier::importedMembers() const
{
    return (qmofobject_cast<const QNamespace *>(this))->importedMembers();
}

/*!
    References the ElementImports owned by the Namespace.
 */
const QSet<QElementImport *> *QClassifier::elementImports() const
{
    return (qmofobject_cast<const QNamespace *>(this))->elementImports();
}

void QClassifier::addElementImport(QElementImport *elementImport)
{
    (qmofobject_cast<QNamespace *>(this))->addElementImport(elementImport);
}

void QClassifier::removeElementImport(QElementImport *elementImport)
{
    (qmofobject_cast<QNamespace *>(this))->removeElementImport(elementImport);
}

/*!
    Specifies a set of Constraints owned by this Namespace.
 */
const QSet<QConstraint *> *QClassifier::ownedRules() const
{
    return (qmofobject_cast<const QNamespace *>(this))->ownedRules();
}

void QClassifier::addOwnedRule(QConstraint *ownedRule)
{
    (qmofobject_cast<QNamespace *>(this))->addOwnedRule(ownedRule);
}

void QClassifier::removeOwnedRule(QConstraint *ownedRule)
{
    (qmofobject_cast<QNamespace *>(this))->removeOwnedRule(ownedRule);
}

/*!
    A collection of NamedElements owned by the Namespace.
 */
const QSet<QNamedElement *> *QClassifier::ownedMembers() const
{
    return (qmofobject_cast<const QNamespace *>(this))->ownedMembers();
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QClassifier
// ---------------------------------------------------------------

/*!
    If true, the Classifier does not provide a complete declaration and can typically not be instantiated. An abstract classifier is intended to be used by other classifiers e.g. as the target of general metarelationships or generalization relationships.
 */
bool QClassifier::isAbstract() const
{
    // This is a read-write attribute

    Q_D(const QClassifier);
    return d->isAbstract;
}

void QClassifier::setAbstract(bool isAbstract)
{
    // This is a read-write attribute

    Q_D(QClassifier);
    if (d->isAbstract != isAbstract) {
        d->isAbstract = isAbstract;
    }
}

/*!
    If true, the Classifier cannot be specialized by generalization. Note that this property is preserved through package merge operations; that is, the capability to specialize a Classifier (i.e., isFinalSpecialization =false) must be preserved in the resulting Classifier of a package merge operation where a Classifier with isFinalSpecialization =false is merged with a matching Classifier with isFinalSpecialization =true: the resulting Classifier will have isFinalSpecialization =false.
 */
bool QClassifier::isFinalSpecialization() const
{
    // This is a read-write attribute

    Q_D(const QClassifier);
    return d->isFinalSpecialization;
}

void QClassifier::setFinalSpecialization(bool isFinalSpecialization)
{
    // This is a read-write attribute

    Q_D(QClassifier);
    if (d->isFinalSpecialization != isFinalSpecialization) {
        d->isFinalSpecialization = isFinalSpecialization;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QClassifier
// ---------------------------------------------------------------

/*!
    Refers to all of the Properties that are direct (i.e. not inherited or imported) attributes of the classifier.
 */
const QSet<QProperty *> *QClassifier::attributes() const
{
    // This is a read-only derived-union association end

    Q_D(const QClassifier);
    return d->attributes;
}

/*!
    Specifies each feature defined in the classifier.
 */
const QSet<QFeature *> *QClassifier::features() const
{
    // This is a read-only derived-union association end

    Q_D(const QClassifier);
    return d->features;
}

/*!
    Specifies the general Classifiers for this Classifier.
 */
const QSet<QClassifier *> *QClassifier::generals() const
{
    // This is a read-write derived association end

    qWarning("QClassifier::generals: to be implemented (this is a derived associationend)");

    return 0; // change here to your derived return
}

void QClassifier::addGeneral(QClassifier *general)
{
    // This is a read-write derived association end

    qWarning("QClassifier::addGeneral: to be implemented (this is a derived associationend)");
    Q_UNUSED(general);

    if (false) { // change to your derived inclusion criteria
        // change to your derived code
    }
}

void QClassifier::removeGeneral(QClassifier *general)
{
    // This is a read-write derived association end

    qWarning("QClassifier::removeGeneral: to be implemented (this is a derived associationend)");
    Q_UNUSED(general);

    if (false) { // change to your derived exclusion criteria
        // change to your derived code
    }
}

/*!
    References the Classifiers that are redefined by this Classifier.
 */
const QSet<QClassifier *> *QClassifier::redefinedClassifiers() const
{
    // This is a read-write association end

    Q_D(const QClassifier);
    return d->redefinedClassifiers;
}

void QClassifier::addRedefinedClassifier(QClassifier *redefinedClassifier)
{
    // This is a read-write association end

    Q_D(QClassifier);
    if (!d->redefinedClassifiers->contains(redefinedClassifier)) {
        d->redefinedClassifiers->insert(redefinedClassifier);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QRedefinableElementPrivate *>(d))->addRedefinedElement(qmofobject_cast<QRedefinableElement *>(redefinedClassifier));
    }
}

void QClassifier::removeRedefinedClassifier(QClassifier *redefinedClassifier)
{
    // This is a read-write association end

    Q_D(QClassifier);
    if (d->redefinedClassifiers->contains(redefinedClassifier)) {
        d->redefinedClassifiers->remove(redefinedClassifier);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QRedefinableElementPrivate *>(d))->removeRedefinedElement(qmofobject_cast<QRedefinableElement *>(redefinedClassifier));
    }
}

/*!
    Specifies all elements inherited by this classifier from the general classifiers.
 */
const QSet<QNamedElement *> *QClassifier::inheritedMembers() const
{
    // This is a read-only derived association end

    qWarning("QClassifier::inheritedMembers: to be implemented (this is a derived associationend)");

    return 0; // change here to your derived return
}

/*!
    Specifies the Generalization relationships for this Classifier. These Generalizations navigaten to more general classifiers in the generalization hierarchy.
 */
const QSet<QGeneralization *> *QClassifier::generalizations() const
{
    // This is a read-write association end

    Q_D(const QClassifier);
    return d->generalizations;
}

void QClassifier::addGeneralization(QGeneralization *generalization)
{
    // This is a read-write association end

    Q_D(QClassifier);
    if (!d->generalizations->contains(generalization)) {
        d->generalizations->insert(generalization);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QElementPrivate *>(d))->addOwnedElement(qmofobject_cast<QElement *>(generalization));

        // Adjust opposite property
        generalization->setSpecific(this);
    }
}

void QClassifier::removeGeneralization(QGeneralization *generalization)
{
    // This is a read-write association end

    Q_D(QClassifier);
    if (d->generalizations->contains(generalization)) {
        d->generalizations->remove(generalization);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QElementPrivate *>(d))->removeOwnedElement(qmofobject_cast<QElement *>(generalization));

        // Adjust opposite property
        generalization->setSpecific(0);
    }
}

/*!
    The query allFeatures() gives all of the features in the namespace of the classifier. In general, through mechanisms such as inheritance, this will be a larger set than feature.
 */
const QSet<QFeature *> *QClassifier::allFeatures() const
{
    qWarning("QClassifier::allFeatures: operation to be implemented");

    return 0; // change here to your derived return
}

/*!
    The query allParents() gives all of the direct and indirect ancestors of a generalized Classifier.
 */
const QSet<QClassifier *> *QClassifier::allParents() const
{
    qWarning("QClassifier::allParents: operation to be implemented");

    return 0; // change here to your derived return
}

/*!
    The query conformsTo() gives true for a classifier that defines a type that conforms to another. This is used, for example, in the specification of signature conformance for operations.
 */
bool QClassifier::conformsTo(const QClassifier *other) const
{
    qWarning("QClassifier::conformsTo: operation to be implemented");
    Q_UNUSED(other);

    return bool(); // change here to your derived return
}

/*!
    The query hasVisibilityOf() determines whether a named element is visible in the classifier. By default all are visible. It is only called when the argument is something owned by a parent.
 */
bool QClassifier::hasVisibilityOf(const QNamedElement *n) const
{
    qWarning("QClassifier::hasVisibilityOf: operation to be implemented");
    Q_UNUSED(n);

    return bool(); // change here to your derived return
}

/*!
    The query inherit() defines how to inherit a set of elements. Here the operation is defined to inherit them all. It is intended to be redefined in circumstances where inheritance is affected by redefinition.
 */
const QSet<QNamedElement *> *QClassifier::inherit(const QSet<QNamedElement *> *inhs) const
{
    qWarning("QClassifier::inherit: operation to be implemented");
    Q_UNUSED(inhs);

    return 0; // change here to your derived return
}

/*!
    The query inheritableMembers() gives all of the members of a classifier that may be inherited in one of its descendants, subject to whatever visibility restrictions apply.
 */
const QSet<QNamedElement *> *QClassifier::inheritableMembers(const QClassifier *c) const
{
    qWarning("QClassifier::inheritableMembers: operation to be implemented");
    Q_UNUSED(c);

    return 0; // change here to your derived return
}

/*!
    The query maySpecializeType() determines whether this classifier may have a generalization relationship to classifiers of the specified type. By default a classifier may specialize classifiers of the same or a more general type. It is intended to be redefined by classifiers that have different specialization constraints.
 */
bool QClassifier::maySpecializeType(const QClassifier *c) const
{
    qWarning("QClassifier::maySpecializeType: operation to be implemented");
    Q_UNUSED(c);

    return bool(); // change here to your derived return
}

/*!
    The query parents() gives all of the immediate ancestors of a generalized Classifier.
 */
const QSet<QClassifier *> *QClassifier::parents() const
{
    qWarning("QClassifier::parents: operation to be implemented");

    return 0; // change here to your derived return
}

#include "moc_qclassifier.cpp"

QT_END_NAMESPACE_QTMOF
