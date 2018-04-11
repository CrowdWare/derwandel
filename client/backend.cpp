/****************************************************************************
** Copyright (C) 2018 Olaf Japp
**
** This file is part of Wandel.
**
**  Wandel is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Wandel is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "backend.h"
#include <QTest>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

void BackEnd::onLinkActivated(const QString &link)
{
    qDebug() << "Link activated" << link;
    // do something useful here ;-)
}
