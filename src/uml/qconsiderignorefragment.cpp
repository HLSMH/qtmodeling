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

#include "qconsiderignorefragment.h"
#include "qconsiderignorefragment_p.h"

#include <QtUml/QNamedElement>

QT_BEGIN_NAMESPACE_QTUML

QConsiderIgnoreFragmentPrivate::QConsiderIgnoreFragmentPrivate() :
    messages(new QSet<QNamedElement *>)
{
}

QConsiderIgnoreFragmentPrivate::~QConsiderIgnoreFragmentPrivate()
{
    delete messages;
}
  
void QConsiderIgnoreFragmentPrivate::addMessage(const QNamedElement *message) 
{   
    this->messages->insert(const_cast<QNamedElement *>(message));  
}
 
void QConsiderIgnoreFragmentPrivate::removeMessage(const QNamedElement *message) 
{    
    this->messages->remove(const_cast<QNamedElement *>(message)); 
}

/*!
    \class QConsiderIgnoreFragment

    \inmodule QtUml

    \brief A consider ignore fragment is a kind of combined fragment that is used for the consider and ignore cases, which require lists of pertinent messages to be specified.
 */

QConsiderIgnoreFragment::QConsiderIgnoreFragment(QObject *parent)
    : QCombinedFragment(false, parent)
{
    d_umlptr = new QConsiderIgnoreFragmentPrivate;
}

QConsiderIgnoreFragment::QConsiderIgnoreFragment(bool createPimpl, QObject *parent)
    : QCombinedFragment(createPimpl, parent)
{
    if (createPimpl)
        d_umlptr = new QConsiderIgnoreFragmentPrivate;
}

QConsiderIgnoreFragment::~QConsiderIgnoreFragment()
{
}

/*!
    The set of messages that apply to this fragment
 */
const QSet<QNamedElement *> *QConsiderIgnoreFragment::messages() const
{
    Q_D(const QConsiderIgnoreFragment);
    return d->messages;
}

void QConsiderIgnoreFragment::addMessage(const QNamedElement *message)
{
    Q_D(QConsiderIgnoreFragment);
    d->addMessage(const_cast<QNamedElement *>(message));
}

void QConsiderIgnoreFragment::removeMessage(const QNamedElement *message)
{
    Q_D(QConsiderIgnoreFragment);
    d->removeMessage(const_cast<QNamedElement *>(message));
}

#include "moc_qconsiderignorefragment.cpp"

QT_END_NAMESPACE_QTUML

