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
#include "qumltemplateableelement.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateSignature>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlTemplateableElement

    \inmodule QtUml

    \brief A templateable element is an element that can optionally be defined as a template and bound to other templates.
 */

QUmlTemplateableElement::QUmlTemplateableElement() :
    _ownedTemplateSignature(0)
{
    d_ptr->object.setProperty("ownedTemplateSignature", QVariant::fromValue((QUmlTemplateSignature *)(0)));
    d_ptr->object.setProperty("templateBinding", QVariant::fromValue(&_templateBinding));
}

// OWNED ATTRIBUTES

/*!
    The optional template signature specifying the formal template parameters.
 */
QUmlTemplateSignature *QUmlTemplateableElement::ownedTemplateSignature() const
{
    // This is a read-write association end

    return _ownedTemplateSignature;
}

void QUmlTemplateableElement::setOwnedTemplateSignature(QUmlTemplateSignature *ownedTemplateSignature)
{
    // This is a read-write association end

    if (_ownedTemplateSignature != ownedTemplateSignature) {
        // Adjust subsetted properties
        removeOwnedElement(_ownedTemplateSignature);

        _ownedTemplateSignature = ownedTemplateSignature;

        // Adjust subsetted properties
        if (ownedTemplateSignature) {
            addOwnedElement(ownedTemplateSignature);
        }
    }
}

/*!
    The optional bindings from this element to templates.
 */
QSet<QUmlTemplateBinding *> QUmlTemplateableElement::templateBinding() const
{
    // This is a read-write association end

    return _templateBinding;
}

void QUmlTemplateableElement::addTemplateBinding(QUmlTemplateBinding *templateBinding)
{
    // This is a read-write association end

    if (!_templateBinding.contains(templateBinding)) {
        _templateBinding.insert(templateBinding);

        // Adjust subsetted properties
        addOwnedElement(templateBinding);

        // Adjust opposite properties
        if (templateBinding) {
            templateBinding->setBoundElement(this);
        }
    }
}

void QUmlTemplateableElement::removeTemplateBinding(QUmlTemplateBinding *templateBinding)
{
    // This is a read-write association end

    if (_templateBinding.contains(templateBinding)) {
        _templateBinding.remove(templateBinding);

        // Adjust subsetted properties
        removeOwnedElement(templateBinding);

        // Adjust opposite properties
        if (templateBinding) {
            templateBinding->setBoundElement(0);
        }
    }
}

// OPERATIONS

/*!
    The query isTemplate() returns whether this templateable element is actually a template.
 */
bool QUmlTemplateableElement::isTemplate(
    ) const
{
    qWarning("QUmlTemplateableElement::isTemplate(): to be implemented (operation)");

    return bool ();
}

/*!
    The query parameterableElements() returns the set of elements that may be used as the parametered elements for a template parameter of this templateable element. By default, this set includes all the owned elements. Subclasses may override this operation if they choose to restrict the set of parameterable elements.
 */
QSet<QUmlParameterableElement *> QUmlTemplateableElement::parameterableElements(
    ) const
{
    qWarning("QUmlTemplateableElement::parameterableElements(): to be implemented (operation)");

    return QSet<QUmlParameterableElement *> ();
}

QT_END_NAMESPACE

