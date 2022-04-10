//MyDrawer.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Drawer {
    id: drawer
    signal triggered(int view)

    width: 240
    height: parent.height

    ListView {
        id: listView
        anchors.fill: parent

        header: Rectangle {
            id: header
            height: toolBar.background.height
            width: listView.width

            Text {
                anchors.verticalCenter: header.verticalCenter
                leftPadding: 20
                text: qsTr("Configurator")
                font.pointSize: 12
            }

            MenuSeparator {
                width: header.width
                anchors.verticalCenter: header.bottom
            }
        }

        model: ListModel {
            ListElement {
                text: qsTr("Data Model")
                iconSource: "qrc:/pics/model.png"
            }

            ListElement {
                text: qsTr("Mapping")
                iconSource: "qrc:/pics/matrix.png"
            }
        }

        delegate: ItemDelegate {
            id: itemDelegate
            width: listView.width
            icon.source: model.iconSource
            text: model.text

            indicator: Rectangle {
                id: indicator
                anchors.fill: itemDelegate
                color: mouseArea.containsMouse ? "#eeeeee" : "#ffffff"
                clip: true

                Rectangle {
                    id: circle
                    height: 0
                    width: 0
                    color: "#bdbdbd"

                    transform: Translate {
                        x: -circle.width / 2
                        y: -circle.height / 2
                    }
                }

                MouseArea {
                    id: mouseArea
                    property bool check : false

                    hoverEnabled: true
                    anchors.fill: indicator

                    onPressed: {
                        circleAnimation.stop()
                        circle.x = mouseX
                        circle.y = mouseY
                        circleAnimation.start()
                    }

                    onReleased: {
                        if (mouseArea.check) {
                            circle.width = 0
                            circle.height = 0
                            mouseArea.check = false
                            drawer.triggered(model.row + 1)
                            drawer.visible = false
                        }
                    }
                }

                PropertyAnimation {
                    id: circleAnimation
                    target: circle
                    properties: "width,height,radius"
                    from: 0
                    to: mouseArea.mouseX < itemDelegate.width / 2 ? 2.5 * (itemDelegate.width - mouseArea.mouseX) : 2.5 * mouseArea.mouseX
                    duration: 1000

                    onStopped: {
                        if (mouseArea.pressed && circle.width === circleAnimation.to)
                            mouseArea.check = true
                        else
                        {
                            circle.width = 0
                            circle.height = 0
                            drawer.triggered(model.row + 1)
                            drawer.visible = false
                        }
                    }
                }
            }
        }
    }
}
