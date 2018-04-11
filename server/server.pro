#-------------------------------------------------
#    Copyright (C) 2018 Olaf Japp
#    https://facebook.com/artanidos
#
#    This file is part of Wandel.
#
#    Wandel is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Wandel is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Wandel.  If not, see <http://www.gnu.org/licenses/>.

QT -= gui
QT += sql core

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = /var/www/html/cgi-bin

SOURCES += main.cpp

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: LIBS += -L$$PWD/lib/ -lmysqlclient

DISTFILES += \
    content/main.qml \
    content/Theme/qmldir \
    content/imports/Theme/qmldir \
    content/imports/Theme/theme.qml

content.commands += $(COPY_DIR) /home/olaf/SourceCode/Wandel/server/content/* /var/www/html
imports.commands += $(COPY_DIR) /home/olaf/SourceCode/Wandel/server/content/imports/Theme/* /var/www/html/imports/Theme
first.depends = $(first) content imports
export(first.depends)
export(content.commands)
QMAKE_EXTRA_TARGETS += first content imports


