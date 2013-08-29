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
#include "umlmessage_p.h"

#include "private/umlconnector_p.h"
#include "private/umlinteraction_p.h"
#include "private/umlmessageend_p.h"
#include "private/umlvaluespecification_p.h"

/*!
    \class UmlMessage

    \inmodule QtUml

    \brief A message defines a particular communication between lifelines of an interaction.
 */

UmlMessage::UmlMessage() :
    _connector(0),
    _interaction(0),
    _messageSort(QtUml::MessageSortSynchCall),
    _receiveEvent(0),
    _sendEvent(0),
    _signature(0)
{
}

// OWNED ATTRIBUTES

/*!
    The arguments of the Message
 */
const QList<UmlValueSpecification *> UmlMessage::argument() const
{
    // This is a read-write association end

    return _argument;
}

void UmlMessage::addArgument(UmlValueSpecification *argument)
{
    // This is a read-write association end

    if (!_argument.contains(argument)) {
        _argument.append(argument);

        // Adjust subsetted properties
        addOwnedElement(argument);
    }
}

void UmlMessage::removeArgument(UmlValueSpecification *argument)
{
    // This is a read-write association end

    if (_argument.contains(argument)) {
        _argument.removeAll(argument);

        // Adjust subsetted properties
        removeOwnedElement(argument);
    }
}

/*!
    The Connector on which this Message is sent.
 */
UmlConnector *UmlMessage::connector() const
{
    // This is a read-write association end

    return _connector;
}

void UmlMessage::setConnector(UmlConnector *connector)
{
    // This is a read-write association end

    if (_connector != connector) {
        _connector = connector;
    }
}

/*!
    The enclosing Interaction owning the Message
 */
UmlInteraction *UmlMessage::interaction() const
{
    // This is a read-write association end

    return _interaction;
}

void UmlMessage::setInteraction(UmlInteraction *interaction)
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
    The derived kind of the Message (complete, lost, found or unknown)
 */
QtUml::MessageKind UmlMessage::messageKind() const
{
    // This is a read-only derived property

    qWarning("UmlMessage::messageKind(): to be implemented (this is a derived property)");

    return QtUml::MessageKind();
}

void UmlMessage::setMessageKind(QtUml::MessageKind messageKind)
{
    // This is a read-only derived property

    qWarning("UmlMessage::messageKind(): to be implemented (this is a derived property)");
    Q_UNUSED(messageKind);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The sort of communication reflected by the Message
 */
QtUml::MessageSort UmlMessage::messageSort() const
{
    // This is a read-write property

    return _messageSort;
}

void UmlMessage::setMessageSort(QtUml::MessageSort messageSort)
{
    // This is a read-write property

    if (_messageSort != messageSort) {
        _messageSort = messageSort;
    }
}

/*!
    References the Receiving of the Message
 */
UmlMessageEnd *UmlMessage::receiveEvent() const
{
    // This is a read-write association end

    return _receiveEvent;
}

void UmlMessage::setReceiveEvent(UmlMessageEnd *receiveEvent)
{
    // This is a read-write association end

    if (_receiveEvent != receiveEvent) {
        _receiveEvent = receiveEvent;
    }
}

/*!
    References the Sending of the Message.
 */
UmlMessageEnd *UmlMessage::sendEvent() const
{
    // This is a read-write association end

    return _sendEvent;
}

void UmlMessage::setSendEvent(UmlMessageEnd *sendEvent)
{
    // This is a read-write association end

    if (_sendEvent != sendEvent) {
        _sendEvent = sendEvent;
    }
}

/*!
    The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
 */
UmlNamedElement *UmlMessage::signature() const
{
    // This is a read-write association end

    return _signature;
}

void UmlMessage::setSignature(UmlNamedElement *signature)
{
    // This is a read-write association end

    if (_signature != signature) {
        _signature = signature;
    }
}
