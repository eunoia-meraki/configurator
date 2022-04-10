// TableArea.qml
import QtQuick 2.15

Rectangle {
    id: tableArea
    anchors.top: parent.top
    anchors.topMargin: toolBar.background.height
    anchors.left: listArea.right
    anchors.right: parent.right
    anchors.bottom: parent.bottom

    TableView {
        id: tableView
        anchors.fill: parent
        model: tableModel
        columnSpacing: -1
        rowSpacing: -1

        delegate: Rectangle {
            implicitHeight: model.isHeader ? 100 : 30
            implicitWidth: 30
            border.color: "black"

            Text {
                font.pointSize: 10
                visible: model.isHeader ? true : false
                rotation: -90
                text: model.headerData
                anchors.left: parent.horizontalCenter
                anchors.bottom: parent.bottom
                transformOrigin: Item.Left
            }

            Rectangle {
                anchors.centerIn: parent
                height: 10
                width: 10
                radius: 10
                color: "black"
                visible: !model.isHeader && model.cellData
            }

            MouseArea {
                anchors.fill: parent
                onPressed: model.cellData = !model.cellData
            }

        }
    }
}
