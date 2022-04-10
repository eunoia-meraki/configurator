//MyItemDelegate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Item {
    CheckBox {
        id: checkBox
        Material.accent: "#673ab7"
        width: 30
        height: 30
        indicator.width: 18
        indicator.height: 18
        anchors.verticalCenter: parent.verticalCenter
        hoverEnabled: false
        down: false
        checked: model !== null ? model.checked : false
        enabled: model !== null ? model.enabled : false
        visible: model !== null ? model.checkable : false

        MouseArea {
            anchors.fill: parent
            onPressed: parent.checked !== true ? model.checked = true : model.checked = false
        }
    }

    Text {
        id: name
        text: model !== null ? model.name : ""
        font.pointSize: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: checkBox.visible ? 33 : 8
        color: !checkBox.visible || checkBox.checked ? "#212121" : "#9e9e9e"
    }

    Text {
        id: description
        text: model !== null ? model.description : ""
        font.pointSize: 9
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: name.right
        anchors.leftMargin: 8
        color: !checkBox.visible || checkBox.checked ? "#616161" : "#9e9e9e"
    }
}
