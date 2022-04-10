// ModelArea.qml
import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.15

Rectangle {
    id: modelArea
    width: 0.4 * parent.width - 600 < 0 ? 0.4 * parent.width : 600
    height: parent.height
    color: "#eeeeee"

    Header { id: header }

    TreeView {
        id: treeView
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: header.bottom
        frameVisible: false
        headerVisible: false
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        model: treeModel
        selection: ItemSelectionModel { id: itemSelectionModel; model: treeModel }

        style: TreeViewStyle {
            backgroundColor: modelArea.color
            branchDelegate: BranchDelegate {}
            itemDelegate: MyItemDelegate {}
            rowDelegate: RowDelegate {}
        }

        TableViewColumn {
            id: tableViewColumn
            width: parent.width
        }
    }

    Rectangle {
        anchors.right: parent.right
        height: parent.height
        width: 1
        color: "#e0e0e0"
    }

    ContextMenu { id: contextMenu }
}
