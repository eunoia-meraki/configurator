//MyMenu.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Menu {
    id: menu

    delegate: MenuItem {
        id: menuItem
        implicitHeight: 28

        background: Rectangle {
            opacity: menu.opacity < 1 ? 0 : 1
            color: menuItem.highlighted ? "#eeeeee" : "#ffffff"
        }

        contentItem: Text {
            text: menuItem.text
            font.pointSize: 9
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            color: "#212121"
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
}
