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
#include "qumlexecutionenvironmentobject_p.h"

#include <QtUml/QUmlExecutionEnvironment>
#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlClass>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlClassifierTemplateParameter>
#include <QtUml/QUmlCollaborationUse>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnectableElement>
#include <QtUml/QUmlConnector>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDeployment>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlExtension>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlInterfaceRealization>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlNode>
#include <QtUml/QUmlOperation>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlPort>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlReception>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlRedefinableTemplateSignature>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>
#include <QtUml/QUmlUseCase>

QT_BEGIN_NAMESPACE

QUmlExecutionEnvironmentObject::QUmlExecutionEnvironmentObject(QUmlExecutionEnvironment *qModelingObject)
{
    setProperty("modelingObject", QVariant::fromValue(static_cast<QModelingObject *>(qModelingObject)));
}

QUmlExecutionEnvironmentObject::~QUmlExecutionEnvironmentObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->deletingFromQObject = true;
        delete qmodelingobjectproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedComments())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedElements())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlExecutionEnvironmentObject::owner() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->owner())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->owner()->asQObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlExecutionEnvironmentObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->clientDependencies())
        set.insert(element->asQObject());
    return set;
}

QString QUmlExecutionEnvironmentObject::name() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->name();
}

QObject *QUmlExecutionEnvironmentObject::nameExpression() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->nameExpression())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->nameExpression()->asQObject();
}

QObject *QUmlExecutionEnvironmentObject::namespace_() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->namespace_())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->namespace_()->asQObject();
}

QString QUmlExecutionEnvironmentObject::qualifiedName() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->qualifiedName();
}

// OWNED ATTRIBUTES [Namespace]

const QSet<QObject *> QUmlExecutionEnvironmentObject::elementImports() const
{
    QSet<QObject *> set;
    foreach (QUmlElementImport *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->elementImports())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::importedMembers() const
{
    QSet<QObject *> set;
    foreach (QUmlPackageableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->importedMembers())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::members() const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->members())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedMembers() const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedMembers())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedRules() const
{
    QSet<QObject *> set;
    foreach (QUmlConstraint *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedRules())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::packageImports() const
{
    QSet<QObject *> set;
    foreach (QUmlPackageImport *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->packageImports())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [ParameterableElement]

QObject *QUmlExecutionEnvironmentObject::owningTemplateParameter() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->owningTemplateParameter())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->owningTemplateParameter()->asQObject();
}

// OWNED ATTRIBUTES [PackageableElement]

QtUml::VisibilityKind QUmlExecutionEnvironmentObject::visibility() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->visibility();
}

// OWNED ATTRIBUTES [Type]

QObject *QUmlExecutionEnvironmentObject::package() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->package())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->package()->asQObject();
}

// OWNED ATTRIBUTES [RedefinableElement]

bool QUmlExecutionEnvironmentObject::isLeaf() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isLeaf();
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::redefinedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlRedefinableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->redefinedElements())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::redefinitionContexts() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->redefinitionContexts())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [TemplateableElement]

const QSet<QObject *> QUmlExecutionEnvironmentObject::templateBindings() const
{
    QSet<QObject *> set;
    foreach (QUmlTemplateBinding *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->templateBindings())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [Classifier]

const QSet<QObject *> QUmlExecutionEnvironmentObject::attributes() const
{
    QSet<QObject *> set;
    foreach (QUmlProperty *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->attributes())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::collaborationUses() const
{
    QSet<QObject *> set;
    foreach (QUmlCollaborationUse *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->collaborationUses())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::features() const
{
    QSet<QObject *> set;
    foreach (QUmlFeature *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->features())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::generalizations() const
{
    QSet<QObject *> set;
    foreach (QUmlGeneralization *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->generalizations())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::inheritedMembers() const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->inheritedMembers())
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::isFinalSpecialization() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isFinalSpecialization();
}

QObject *QUmlExecutionEnvironmentObject::ownedTemplateSignature() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedTemplateSignature())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedTemplateSignature()->asQObject();
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedUseCases() const
{
    QSet<QObject *> set;
    foreach (QUmlUseCase *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedUseCases())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::powertypeExtents() const
{
    QSet<QObject *> set;
    foreach (QUmlGeneralizationSet *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->powertypeExtents())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::redefinedClassifiers() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->redefinedClassifiers())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlExecutionEnvironmentObject::representation() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->representation())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->representation()->asQObject();
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::substitutions() const
{
    QSet<QObject *> set;
    foreach (QUmlSubstitution *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->substitutions())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlExecutionEnvironmentObject::templateParameter() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->templateParameter())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->templateParameter()->asQObject();
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::useCases() const
{
    QSet<QObject *> set;
    foreach (QUmlUseCase *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->useCases())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [StructuredClassifier]

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedConnectors() const
{
    QSet<QObject *> set;
    foreach (QUmlConnector *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedConnectors())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::parts() const
{
    QSet<QObject *> set;
    foreach (QUmlProperty *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->parts())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::roles() const
{
    QSet<QObject *> set;
    foreach (QUmlConnectableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->roles())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [EncapsulatedClassifier]

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedPorts() const
{
    QSet<QObject *> set;
    foreach (QUmlPort *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedPorts())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [BehavioredClassifier]

QObject *QUmlExecutionEnvironmentObject::classifierBehavior() const
{
    if (!qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->classifierBehavior())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->classifierBehavior()->asQObject();
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::interfaceRealizations() const
{
    QSet<QObject *> set;
    foreach (QUmlInterfaceRealization *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->interfaceRealizations())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedBehaviors() const
{
    QSet<QObject *> set;
    foreach (QUmlBehavior *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedBehaviors())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [Class]

const QSet<QObject *> QUmlExecutionEnvironmentObject::extensions() const
{
    QSet<QObject *> set;
    foreach (QUmlExtension *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->extensions())
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::isAbstract() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isAbstract();
}

bool QUmlExecutionEnvironmentObject::isActive() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isActive();
}

const QList<QObject *> QUmlExecutionEnvironmentObject::nestedClassifiers() const
{
    QList<QObject *> list;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->nestedClassifiers())
        list.append(element->asQObject());
    return list;
}

const QList<QObject *> QUmlExecutionEnvironmentObject::ownedAttributes() const
{
    QList<QObject *> list;
    foreach (QUmlProperty *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedAttributes())
        list.append(element->asQObject());
    return list;
}

const QList<QObject *> QUmlExecutionEnvironmentObject::ownedOperations() const
{
    QList<QObject *> list;
    foreach (QUmlOperation *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedOperations())
        list.append(element->asQObject());
    return list;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::ownedReceptions() const
{
    QSet<QObject *> set;
    foreach (QUmlReception *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->ownedReceptions())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::superClasses() const
{
    QSet<QObject *> set;
    foreach (QUmlClass *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->superClasses())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [DeploymentTarget]

const QSet<QObject *> QUmlExecutionEnvironmentObject::deployedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlPackageableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->deployedElements())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlExecutionEnvironmentObject::deployments() const
{
    QSet<QObject *> set;
    foreach (QUmlDeployment *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->deployments())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [Node]

const QSet<QObject *> QUmlExecutionEnvironmentObject::nestedNodes() const
{
    QSet<QObject *> set;
    foreach (QUmlNode *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->nestedNodes())
        set.insert(element->asQObject());
    return set;
}

// OPERATIONS [Element]

QSet<QObject *> QUmlExecutionEnvironmentObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->allOwnedElements())
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::mustBeOwned() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->mustBeOwned();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlExecutionEnvironmentObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->allNamespaces())
        set.append(element->asQObject());
    return set;
}

QSet<QObject *> QUmlExecutionEnvironmentObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->allOwningPackages())
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isDistinguishableFrom(qmodelingobjectproperty_cast<QUmlNamedElement *>(n), qmodelingobjectproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlExecutionEnvironmentObject::separator() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->separator();
}

// OPERATIONS [Namespace]

QSet<QObject *> QUmlExecutionEnvironmentObject::excludeCollisions(QSet<QObject *> imps) const
{
    QSet<QUmlPackageableElement *> impsConverted;
    foreach (QObject *object, imps)
        impsConverted.insert(qmodelingobjectproperty_cast<QUmlPackageableElement *>(object));
    QSet<QObject *> set;
    foreach (QUmlPackageableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->excludeCollisions(impsConverted))
        set.insert(element->asQObject());
    return set;
}

QSet<QString> QUmlExecutionEnvironmentObject::getNamesOfMember(QObject *element) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->getNamesOfMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(element));
}

QSet<QObject *> QUmlExecutionEnvironmentObject::importMembers(QSet<QObject *> imps) const
{
    QSet<QUmlPackageableElement *> impsConverted;
    foreach (QObject *object, imps)
        impsConverted.insert(qmodelingobjectproperty_cast<QUmlPackageableElement *>(object));
    QSet<QObject *> set;
    foreach (QUmlPackageableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->importMembers(impsConverted))
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::membersAreDistinguishable() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->membersAreDistinguishable();
}

// OPERATIONS [ParameterableElement]

bool QUmlExecutionEnvironmentObject::isCompatibleWith(QObject *p) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isCompatibleWith(qmodelingobjectproperty_cast<QUmlParameterableElement *>(p));
}

bool QUmlExecutionEnvironmentObject::isTemplateParameter() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isTemplateParameter();
}

// OPERATIONS [Type]
// OPERATIONS [RedefinableElement]

bool QUmlExecutionEnvironmentObject::isConsistentWith(QObject *redefinee) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isConsistentWith(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinee));
}

bool QUmlExecutionEnvironmentObject::isRedefinitionContextValid(QObject *redefined) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isRedefinitionContextValid(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefined));
}

// OPERATIONS [TemplateableElement]

QSet<QObject *> QUmlExecutionEnvironmentObject::parameterableElements() const
{
    QSet<QObject *> set;
    foreach (QUmlParameterableElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->parameterableElements())
        set.insert(element->asQObject());
    return set;
}

// OPERATIONS [Classifier]

QSet<QObject *> QUmlExecutionEnvironmentObject::allFeatures() const
{
    QSet<QObject *> set;
    foreach (QUmlFeature *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->allFeatures())
        set.insert(element->asQObject());
    return set;
}

QSet<QObject *> QUmlExecutionEnvironmentObject::allParents() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->allParents())
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::conformsTo(QObject *other) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->conformsTo(qmodelingobjectproperty_cast<QUmlClassifier *>(other));
}

bool QUmlExecutionEnvironmentObject::hasVisibilityOf(QObject *n) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->hasVisibilityOf(qmodelingobjectproperty_cast<QUmlNamedElement *>(n));
}

QSet<QObject *> QUmlExecutionEnvironmentObject::inheritableMembers(QObject *c) const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->inheritableMembers(qmodelingobjectproperty_cast<QUmlClassifier *>(c)))
        set.insert(element->asQObject());
    return set;
}

bool QUmlExecutionEnvironmentObject::isTemplate() const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->isTemplate();
}

bool QUmlExecutionEnvironmentObject::maySpecializeType(QObject *c) const
{
    return qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->maySpecializeType(qmodelingobjectproperty_cast<QUmlClassifier *>(c));
}

QSet<QObject *> QUmlExecutionEnvironmentObject::parents() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->parents())
        set.insert(element->asQObject());
    return set;
}

// OPERATIONS [Class]

QSet<QObject *> QUmlExecutionEnvironmentObject::inherit(QSet<QObject *> inhs) const
{
    QSet<QUmlNamedElement *> inhsConverted;
    foreach (QObject *object, inhs)
        inhsConverted.insert(qmodelingobjectproperty_cast<QUmlNamedElement *>(object));
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->inherit(inhsConverted))
        set.insert(element->asQObject());
    return set;
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlExecutionEnvironmentObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlExecutionEnvironmentObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlExecutionEnvironmentObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlExecutionEnvironmentObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlExecutionEnvironmentObject::setOwner(QObject *owner)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setOwner(qmodelingobjectproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlExecutionEnvironmentObject::addClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlExecutionEnvironmentObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlExecutionEnvironmentObject::setName(QString name)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setName(name);
}

void QUmlExecutionEnvironmentObject::setNameExpression(QObject *nameExpression)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setNameExpression(qmodelingobjectproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlExecutionEnvironmentObject::setNamespace(QObject *namespace_)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setNamespace(qmodelingobjectproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlExecutionEnvironmentObject::setQualifiedName(QString qualifiedName)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setQualifiedName(qualifiedName);
}
// SLOTS FOR OWNED ATTRIBUTES [Namespace]

void QUmlExecutionEnvironmentObject::addElementImport(QObject *elementImport)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addElementImport(qmodelingobjectproperty_cast<QUmlElementImport *>(elementImport));
}

void QUmlExecutionEnvironmentObject::removeElementImport(QObject *elementImport)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeElementImport(qmodelingobjectproperty_cast<QUmlElementImport *>(elementImport));
}

void QUmlExecutionEnvironmentObject::addImportedMember(QObject *importedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addImportedMember(qmodelingobjectproperty_cast<QUmlPackageableElement *>(importedMember));
}

void QUmlExecutionEnvironmentObject::removeImportedMember(QObject *importedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeImportedMember(qmodelingobjectproperty_cast<QUmlPackageableElement *>(importedMember));
}

void QUmlExecutionEnvironmentObject::addMember(QObject *member)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(member));
}

void QUmlExecutionEnvironmentObject::removeMember(QObject *member)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(member));
}

void QUmlExecutionEnvironmentObject::addOwnedMember(QObject *ownedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(ownedMember));
}

void QUmlExecutionEnvironmentObject::removeOwnedMember(QObject *ownedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(ownedMember));
}

void QUmlExecutionEnvironmentObject::addOwnedRule(QObject *ownedRule)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedRule(qmodelingobjectproperty_cast<QUmlConstraint *>(ownedRule));
}

void QUmlExecutionEnvironmentObject::removeOwnedRule(QObject *ownedRule)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedRule(qmodelingobjectproperty_cast<QUmlConstraint *>(ownedRule));
}

void QUmlExecutionEnvironmentObject::addPackageImport(QObject *packageImport)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addPackageImport(qmodelingobjectproperty_cast<QUmlPackageImport *>(packageImport));
}

void QUmlExecutionEnvironmentObject::removePackageImport(QObject *packageImport)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removePackageImport(qmodelingobjectproperty_cast<QUmlPackageImport *>(packageImport));
}

// SLOTS FOR OWNED ATTRIBUTES [ParameterableElement]

void QUmlExecutionEnvironmentObject::setOwningTemplateParameter(QObject *owningTemplateParameter)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setOwningTemplateParameter(qmodelingobjectproperty_cast<QUmlTemplateParameter *>(owningTemplateParameter));
}
// SLOTS FOR OWNED ATTRIBUTES [PackageableElement]

void QUmlExecutionEnvironmentObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setVisibility(visibility);
}

void QUmlExecutionEnvironmentObject::unsetVisibility()
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("visibility"));
}

// SLOTS FOR OWNED ATTRIBUTES [Type]

void QUmlExecutionEnvironmentObject::setPackage(QObject *package)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setPackage(qmodelingobjectproperty_cast<QUmlPackage *>(package));
}

// SLOTS FOR OWNED ATTRIBUTES [RedefinableElement]

void QUmlExecutionEnvironmentObject::setLeaf(bool isLeaf)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setLeaf(isLeaf);
}

void QUmlExecutionEnvironmentObject::unsetLeaf()
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("leaf"));
}

void QUmlExecutionEnvironmentObject::addRedefinedElement(QObject *redefinedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addRedefinedElement(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlExecutionEnvironmentObject::removeRedefinedElement(QObject *redefinedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeRedefinedElement(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlExecutionEnvironmentObject::addRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addRedefinitionContext(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinitionContext));
}

void QUmlExecutionEnvironmentObject::removeRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeRedefinitionContext(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinitionContext));
}

// SLOTS FOR OWNED ATTRIBUTES [TemplateableElement]

void QUmlExecutionEnvironmentObject::addTemplateBinding(QObject *templateBinding)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addTemplateBinding(qmodelingobjectproperty_cast<QUmlTemplateBinding *>(templateBinding));
}

void QUmlExecutionEnvironmentObject::removeTemplateBinding(QObject *templateBinding)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeTemplateBinding(qmodelingobjectproperty_cast<QUmlTemplateBinding *>(templateBinding));
}

// SLOTS FOR OWNED ATTRIBUTES [Classifier]

void QUmlExecutionEnvironmentObject::addAttribute(QObject *attribute)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addAttribute(qmodelingobjectproperty_cast<QUmlProperty *>(attribute));
}

void QUmlExecutionEnvironmentObject::removeAttribute(QObject *attribute)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeAttribute(qmodelingobjectproperty_cast<QUmlProperty *>(attribute));
}

void QUmlExecutionEnvironmentObject::addCollaborationUse(QObject *collaborationUse)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addCollaborationUse(qmodelingobjectproperty_cast<QUmlCollaborationUse *>(collaborationUse));
}

void QUmlExecutionEnvironmentObject::removeCollaborationUse(QObject *collaborationUse)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeCollaborationUse(qmodelingobjectproperty_cast<QUmlCollaborationUse *>(collaborationUse));
}

void QUmlExecutionEnvironmentObject::addFeature(QObject *feature)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addFeature(qmodelingobjectproperty_cast<QUmlFeature *>(feature));
}

void QUmlExecutionEnvironmentObject::removeFeature(QObject *feature)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeFeature(qmodelingobjectproperty_cast<QUmlFeature *>(feature));
}

void QUmlExecutionEnvironmentObject::addGeneralization(QObject *generalization)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addGeneralization(qmodelingobjectproperty_cast<QUmlGeneralization *>(generalization));
}

void QUmlExecutionEnvironmentObject::removeGeneralization(QObject *generalization)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeGeneralization(qmodelingobjectproperty_cast<QUmlGeneralization *>(generalization));
}

void QUmlExecutionEnvironmentObject::addInheritedMember(QObject *inheritedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addInheritedMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(inheritedMember));
}

void QUmlExecutionEnvironmentObject::removeInheritedMember(QObject *inheritedMember)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeInheritedMember(qmodelingobjectproperty_cast<QUmlNamedElement *>(inheritedMember));
}

void QUmlExecutionEnvironmentObject::setFinalSpecialization(bool isFinalSpecialization)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setFinalSpecialization(isFinalSpecialization);
}

void QUmlExecutionEnvironmentObject::unsetFinalSpecialization()
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("finalSpecialization"));
}

void QUmlExecutionEnvironmentObject::setOwnedTemplateSignature(QObject *ownedTemplateSignature)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setOwnedTemplateSignature(qmodelingobjectproperty_cast<QUmlRedefinableTemplateSignature *>(ownedTemplateSignature));
}

void QUmlExecutionEnvironmentObject::addOwnedUseCase(QObject *ownedUseCase)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedUseCase(qmodelingobjectproperty_cast<QUmlUseCase *>(ownedUseCase));
}

void QUmlExecutionEnvironmentObject::removeOwnedUseCase(QObject *ownedUseCase)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedUseCase(qmodelingobjectproperty_cast<QUmlUseCase *>(ownedUseCase));
}

void QUmlExecutionEnvironmentObject::addPowertypeExtent(QObject *powertypeExtent)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addPowertypeExtent(qmodelingobjectproperty_cast<QUmlGeneralizationSet *>(powertypeExtent));
}

void QUmlExecutionEnvironmentObject::removePowertypeExtent(QObject *powertypeExtent)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removePowertypeExtent(qmodelingobjectproperty_cast<QUmlGeneralizationSet *>(powertypeExtent));
}

void QUmlExecutionEnvironmentObject::addRedefinedClassifier(QObject *redefinedClassifier)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addRedefinedClassifier(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinedClassifier));
}

void QUmlExecutionEnvironmentObject::removeRedefinedClassifier(QObject *redefinedClassifier)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeRedefinedClassifier(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinedClassifier));
}

void QUmlExecutionEnvironmentObject::setRepresentation(QObject *representation)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setRepresentation(qmodelingobjectproperty_cast<QUmlCollaborationUse *>(representation));
}

void QUmlExecutionEnvironmentObject::addSubstitution(QObject *substitution)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addSubstitution(qmodelingobjectproperty_cast<QUmlSubstitution *>(substitution));
}

void QUmlExecutionEnvironmentObject::removeSubstitution(QObject *substitution)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeSubstitution(qmodelingobjectproperty_cast<QUmlSubstitution *>(substitution));
}

void QUmlExecutionEnvironmentObject::setTemplateParameter(QObject *templateParameter)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setTemplateParameter(qmodelingobjectproperty_cast<QUmlClassifierTemplateParameter *>(templateParameter));
}

void QUmlExecutionEnvironmentObject::addUseCase(QObject *useCase)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addUseCase(qmodelingobjectproperty_cast<QUmlUseCase *>(useCase));
}

void QUmlExecutionEnvironmentObject::removeUseCase(QObject *useCase)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeUseCase(qmodelingobjectproperty_cast<QUmlUseCase *>(useCase));
}

// SLOTS FOR OWNED ATTRIBUTES [StructuredClassifier]

void QUmlExecutionEnvironmentObject::addOwnedConnector(QObject *ownedConnector)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedConnector(qmodelingobjectproperty_cast<QUmlConnector *>(ownedConnector));
}

void QUmlExecutionEnvironmentObject::removeOwnedConnector(QObject *ownedConnector)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedConnector(qmodelingobjectproperty_cast<QUmlConnector *>(ownedConnector));
}

void QUmlExecutionEnvironmentObject::addPart(QObject *part)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addPart(qmodelingobjectproperty_cast<QUmlProperty *>(part));
}

void QUmlExecutionEnvironmentObject::removePart(QObject *part)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removePart(qmodelingobjectproperty_cast<QUmlProperty *>(part));
}

void QUmlExecutionEnvironmentObject::addRole(QObject *role)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addRole(qmodelingobjectproperty_cast<QUmlConnectableElement *>(role));
}

void QUmlExecutionEnvironmentObject::removeRole(QObject *role)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeRole(qmodelingobjectproperty_cast<QUmlConnectableElement *>(role));
}

// SLOTS FOR OWNED ATTRIBUTES [EncapsulatedClassifier]

void QUmlExecutionEnvironmentObject::addOwnedPort(QObject *ownedPort)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedPort(qmodelingobjectproperty_cast<QUmlPort *>(ownedPort));
}

void QUmlExecutionEnvironmentObject::removeOwnedPort(QObject *ownedPort)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedPort(qmodelingobjectproperty_cast<QUmlPort *>(ownedPort));
}

// SLOTS FOR OWNED ATTRIBUTES [BehavioredClassifier]

void QUmlExecutionEnvironmentObject::setClassifierBehavior(QObject *classifierBehavior)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setClassifierBehavior(qmodelingobjectproperty_cast<QUmlBehavior *>(classifierBehavior));
}

void QUmlExecutionEnvironmentObject::addInterfaceRealization(QObject *interfaceRealization)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addInterfaceRealization(qmodelingobjectproperty_cast<QUmlInterfaceRealization *>(interfaceRealization));
}

void QUmlExecutionEnvironmentObject::removeInterfaceRealization(QObject *interfaceRealization)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeInterfaceRealization(qmodelingobjectproperty_cast<QUmlInterfaceRealization *>(interfaceRealization));
}

void QUmlExecutionEnvironmentObject::addOwnedBehavior(QObject *ownedBehavior)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedBehavior(qmodelingobjectproperty_cast<QUmlBehavior *>(ownedBehavior));
}

void QUmlExecutionEnvironmentObject::removeOwnedBehavior(QObject *ownedBehavior)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedBehavior(qmodelingobjectproperty_cast<QUmlBehavior *>(ownedBehavior));
}

// SLOTS FOR OWNED ATTRIBUTES [Class]

void QUmlExecutionEnvironmentObject::addExtension(QObject *extension)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addExtension(qmodelingobjectproperty_cast<QUmlExtension *>(extension));
}

void QUmlExecutionEnvironmentObject::removeExtension(QObject *extension)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeExtension(qmodelingobjectproperty_cast<QUmlExtension *>(extension));
}

void QUmlExecutionEnvironmentObject::setAbstract(bool isAbstract)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setAbstract(isAbstract);
}

void QUmlExecutionEnvironmentObject::unsetAbstract()
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("abstract"));
}

void QUmlExecutionEnvironmentObject::setActive(bool isActive)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->setActive(isActive);
}

void QUmlExecutionEnvironmentObject::unsetActive()
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("active"));
}

void QUmlExecutionEnvironmentObject::addNestedClassifier(QObject *nestedClassifier)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addNestedClassifier(qmodelingobjectproperty_cast<QUmlClassifier *>(nestedClassifier));
}

void QUmlExecutionEnvironmentObject::removeNestedClassifier(QObject *nestedClassifier)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeNestedClassifier(qmodelingobjectproperty_cast<QUmlClassifier *>(nestedClassifier));
}

void QUmlExecutionEnvironmentObject::addOwnedAttribute(QObject *ownedAttribute)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedAttribute(qmodelingobjectproperty_cast<QUmlProperty *>(ownedAttribute));
}

void QUmlExecutionEnvironmentObject::removeOwnedAttribute(QObject *ownedAttribute)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedAttribute(qmodelingobjectproperty_cast<QUmlProperty *>(ownedAttribute));
}

void QUmlExecutionEnvironmentObject::addOwnedOperation(QObject *ownedOperation)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedOperation(qmodelingobjectproperty_cast<QUmlOperation *>(ownedOperation));
}

void QUmlExecutionEnvironmentObject::removeOwnedOperation(QObject *ownedOperation)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedOperation(qmodelingobjectproperty_cast<QUmlOperation *>(ownedOperation));
}

void QUmlExecutionEnvironmentObject::addOwnedReception(QObject *ownedReception)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addOwnedReception(qmodelingobjectproperty_cast<QUmlReception *>(ownedReception));
}

void QUmlExecutionEnvironmentObject::removeOwnedReception(QObject *ownedReception)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeOwnedReception(qmodelingobjectproperty_cast<QUmlReception *>(ownedReception));
}

void QUmlExecutionEnvironmentObject::addSuperClass(QObject *superClass)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addSuperClass(qmodelingobjectproperty_cast<QUmlClass *>(superClass));
}

void QUmlExecutionEnvironmentObject::removeSuperClass(QObject *superClass)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeSuperClass(qmodelingobjectproperty_cast<QUmlClass *>(superClass));
}

// SLOTS FOR OWNED ATTRIBUTES [DeploymentTarget]

void QUmlExecutionEnvironmentObject::addDeployedElement(QObject *deployedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addDeployedElement(qmodelingobjectproperty_cast<QUmlPackageableElement *>(deployedElement));
}

void QUmlExecutionEnvironmentObject::removeDeployedElement(QObject *deployedElement)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeDeployedElement(qmodelingobjectproperty_cast<QUmlPackageableElement *>(deployedElement));
}

void QUmlExecutionEnvironmentObject::addDeployment(QObject *deployment)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addDeployment(qmodelingobjectproperty_cast<QUmlDeployment *>(deployment));
}

void QUmlExecutionEnvironmentObject::removeDeployment(QObject *deployment)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeDeployment(qmodelingobjectproperty_cast<QUmlDeployment *>(deployment));
}

// SLOTS FOR OWNED ATTRIBUTES [Node]

void QUmlExecutionEnvironmentObject::addNestedNode(QObject *nestedNode)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->addNestedNode(qmodelingobjectproperty_cast<QUmlNode *>(nestedNode));
}

void QUmlExecutionEnvironmentObject::removeNestedNode(QObject *nestedNode)
{
    qmodelingobjectproperty_cast<QUmlExecutionEnvironment *>(this)->removeNestedNode(qmodelingobjectproperty_cast<QUmlNode *>(nestedNode));
}

QT_END_NAMESPACE
