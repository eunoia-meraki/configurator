//RowDelegate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import TreeModel 1.0
import QtQml.Models 2.15

Rectangle {
    height: 28
    width: treeView.width
    color: styleData.selected ? "#bbdefb" : mouseArea.containsMouse ? "#e0e0e0" : "#eeeeee"

    MouseArea {
        id: mouseArea
        height: parent.height
        width: treeView.width
        hoverEnabled: true
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onPressed: {
            itemSelectionModel.setCurrentIndex(model.qModelIndex, ItemSelectionModel.SelectCurrent)

            parametersArea.displayParameters(model)

            if (mouse.button === Qt.RightButton)
                contextMenu.popup(model)

            mouse.accepted = false
        }
    }
}



