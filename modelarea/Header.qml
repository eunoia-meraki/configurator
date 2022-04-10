//Header.qml
import QtQuick 2.15

Rectangle {
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    height: 32
    color: parent.color

    RowButton {
        anchors.left: parent.left
        anchors.leftMargin: treeView.width - 33
        anchors.verticalCenter: parent.verticalCenter
        regularSource: "qrc:/pics/add.png"
        blurSource: "qrc:/pics/add-blur.png"
        onPressed: treeModel.addLd()
    }

    Text {
        text: "Model"
        font.pointSize: 10
        font.weight: Font.DemiBold
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        color: "#212121"
    }

    Rectangle {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 1
        color: "#e0e0e0"
    }
}
