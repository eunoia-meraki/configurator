// MappingView.qml
import QtQuick 2.15
import EventModel 1.0
import ProxyModel 1.0
import CellModel 1.0
import QtQuick.Controls 2.15

Rectangle {
    id: mappingView
    height: parent.height - toolBar.background.height
    width: parent.width
    anchors.bottom: parent.bottom

    ProxyModel { id: proxyModel; sourceModel: treeModel }
    EventModel { id: eventModel }
    CellModel { id: cellModel; eventModel: eventModel; proxyModel: proxyModel }

    TableView {
        id: cells
        property var hoveredCell
        anchors.top: events.bottom
        anchors.topMargin: -1
        anchors.left: data.right
        anchors.right: mappingView.right
        anchors.bottom: mappingView.bottom
        model: cellModel
        columnSpacing: -1
        rowSpacing: -1
        syncView: events
        syncDirection: Qt.Horizontal
        boundsBehavior: Flickable.OvershootBounds

        delegate: Rectangle {
            id: cell
            implicitHeight: 20
            implicitWidth: 20
            border.color: "#000000"
            color: cells.hoveredCell === undefined || cells.dragging ? "#ffffff" : (cells.hoveredCell.row === model.row || cells.hoveredCell.column === model.column ? "#e0e0e0" : "#ffffff")

            Rectangle {
                height: 18
                width: 2
                anchors.centerIn: cell
                color: "#000000"
                rotation: 45
                visible: model.cell
            }

            Rectangle {
                height: 2
                width: 18
                anchors.centerIn: cell
                color: "#000000"
                rotation: 45
                visible: model.cell
            }

            MouseArea {
                anchors.fill: cell
                cursorShape: cells.dragging ? Qt.ClosedHandCursor : Qt.ArrowCursor
                onDoubleClicked: model.cell = !model.cell
                hoverEnabled: true
                onEntered: cells.hoveredCell = model
                onExited: cells.hoveredCell = undefined
            }
        }
    }

    TableView {
        id: events
        anchors.top: mappingView.top
        anchors.topMargin: -1
        anchors.left: header.right
        anchors.right: mappingView.right
        height: 160
        model: eventModel
        columnSpacing: -1
        rowSpacing: -1
        boundsBehavior: Flickable.OvershootBounds

        delegate: Rectangle {
            id: event
            implicitHeight: events.height
            implicitWidth: 20
            border.color: "#000000"
            color: cells.hoveredCell === undefined || cells.dragging ? "#ffffff" : (cells.hoveredCell.column === model.column ? "#e0e0e0" : "#ffffff")

            Text {
                font.pointSize: 10
                text: model.event
                anchors.bottom: event.bottom
                anchors.left: event.horizontalCenter
                transformOrigin: Text.Left
                rotation: -90
            }

            ToolTip {
                delay : 750
                visible: eventMouseArea.containsMouse
                text: model.event
            }

            MouseArea {
                id: eventMouseArea
                anchors.fill: event
                cursorShape: events.dragging ? Qt.ClosedHandCursor : Qt.ArrowCursor
                hoverEnabled: true
            }
        }
    }

    Rectangle {
        id: data
        anchors.top: header.bottom
        anchors.topMargin: -1
        anchors.bottom: mappingView.bottom
        width: 0.4 * mappingView.width - 600 < 0 ? 0.4 * mappingView.width : 600
        color: "#eeeeee"

        TableView {
            id: dataView
            anchors.fill: data
            model: proxyModel
            columnSpacing: -1
            rowSpacing: -1
            syncView: cells
            syncDirection: Qt.Vertical
            boundsBehavior: Flickable.OvershootBounds

            delegate: Rectangle {
                id: dataItem
                implicitHeight: 20
                implicitWidth: dataView.width
                height: 20
                width: dataView.width
                color: cells.hoveredCell === undefined || cells.dragging ? "#eeeeee" : (cells.hoveredCell.row === model.row ? "#e0e0e0" : "#eeeeee")
                border.color: "#e0e0e0"

                Text {
                    font.pointSize: 10
                    text: model.data
                    anchors.verticalCenter: dataItem.verticalCenter
                    leftPadding: 20
                }

                ToolTip {
                    delay : 750
                    visible: dataMouseArea.containsMouse
                    text: model.data
                }

                MouseArea {
                    id: dataMouseArea
                    anchors.fill: dataItem
                    cursorShape: dataView.dragging ? Qt.ClosedHandCursor : Qt.ArrowCursor
                    hoverEnabled: true
                }
            }
        }

        Rectangle {
            anchors.right: data.right
            height: data.height
            width: 1
            color: "#e0e0e0"
        }
    }

    Rectangle {
        id: header
        anchors.top: mappingView.top
        anchors.topMargin: -1
        height: 160
        width: 0.4 * mappingView.width - 600 < 0 ? 0.4 * mappingView.width : 600
        color: "#eeeeee"
        border.color: "#e0e0e0"

        Text {
            font.pointSize: 10
            font.weight: Font.DemiBold
            color: "#212121"
            text: qsTr("Data/Events")
            anchors.centerIn: header
        }
    }
}
