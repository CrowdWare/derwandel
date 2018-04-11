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

#include <QApplication>
#include <QQmlApplicationEngine>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("DerWandel Browser");
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationName("derwandel.org");

    qmlRegisterType<BackEnd>("org.derwandel.backend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;
    engine.addImportPath("http://localhost/imports");
    engine.load(QUrl("http://localhost/main.qml"));

    return a.exec();
}
