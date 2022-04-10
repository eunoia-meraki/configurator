//MyPopup.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Menu {
    id: menu
    enter: Transition {}
    exit: Transition {}

    delegate: MenuItem {
        id: menuItem
        implicitHeight: 28

        background: Rectangle {
            color: parent.highlighted ? "#eeeeee" : "#ffffff"
        }

        contentItem: Item {
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: menuItem.action.text
                font.pointSize: 9
                color: "#212121"
            }

            Text{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: "#616161"
                text: menuItem.action.shortcut
                font.pointSize: 9
            }
        }
    }

    background: Rectangle {
        implicitWidth: 200
        radius: 2
        layer.enabled: true

        layer.effect: DropShadow {
            transparentBorder: true
            color: "#424242"
            radius: 4
            samples: 9
            horizontalOffset: 1
            verticalOffset: 1
        }
    }

    Action { text: "New"; shortcut: "Ctrl+N" ; onTriggered: treeModel.resetModel() }
    Action { text: "Open"; shortcut: "Ctrl+O"; onTriggered: fileDialog.open(); }
    Action { text: "Save As"; shortcut: "Ctrl+Shift+S";  }
    MenuSeparator {}
    Action { text: "Export ICD"; shortcut: "Ctrl+E" }


}
