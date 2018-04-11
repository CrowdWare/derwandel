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

import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.3
import QtQuick.Dialogs 1.2
import org.derwandel.backend 1.0
import Theme 1.0

ApplicationWindow
{
    id: root
    width: 1024
    height: 640
    title: "DerWandel Client"
    visible: true
    style: ApplicationWindowStyle
    {
        background: Rectangle
        {
            color: Theme.windowBackground
        }
    }
    statusBar: StatusBar
    {
        style: StatusBarStyle
        {
            background: Rectangle
            {
                color: Theme.windowBackground
            }
        }

        RowLayout
        {
            anchors.fill: parent
            Label { color: Theme.textColor; text: "Ready" }
        }
    }

    BackEnd
    {
        id: backend
    }

    SplitView {
          anchors.fill: parent
          orientation: Qt.Horizontal

          Text
          {
              width: 200
              Layout.maximumWidth: 400
              text: "<h3>Navigation</h3><ul>" +
                    "<li><a href='#profile'>Profil</a></li>" +
                    "<li><a href='#events'>Veranstaltungen</a></li>" +
                    "</ul>"
              color: Theme.textColor
              onLinkActivated: backend.onLinkActivated(link)

              MouseArea
              {
                  anchors.fill: parent
                  acceptedButtons: Qt.NoButton
                  cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
              }
          }

          Rectangle {
              id: centerItem
              Layout.minimumWidth: 50
              Layout.fillWidth: true
              Layout.margins: 20
              color: Theme.windowBackground

              Text {
                  text: "Willkommen bei <b>Der Wandel</b>"
                  textFormat: Text.StyledText
                  font.pointSize: 20
                  color: "white"

              }
          }
          Text
          {
              width: 200
              Layout.maximumWidth: 400
              text: "<h3>Freunde</h3><ul>" +
                    "<li><a href='#user:1'>Art Anidos Ananada</a></li>" +
                    "<li><a href='#user:2'>Angela Mahr</a></li>" +
                    "<li><a href='#user:3'>Monika Mahr</a></li>" +
                    "<li><a href='#user:4'>Eo Et</a></li>" +
                    "</ul>"
              color: Theme.textColor
              onLinkActivated: backend.onLinkActivated(link)

              MouseArea
              {
                  anchors.fill: parent
                  acceptedButtons: Qt.NoButton
                  cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
              }
          }
      }
}
