//MyToolBar.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15

ToolBar {

    background: Rectangle {
        id: background
        height: 48
        width: parent.width
        color: "#673ab7"
        layer.enabled: true

        layer.effect: DropShadow {
            transparentBorder: true
            radius: 7
            samples: 15
        }

        RowLayout {
            anchors.left: parent.left
            anchors.leftMargin: 5
            spacing: 5


            RoundButton {
                flat: true
                icon.source: "qrc:/pics/burger.png"
                onClicked: drawer.visible = true

                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
            }

            Text {
                text: "Configurator"
                font.pointSize: 12
                color: "#ffffff"
            }
        }

        RowLayout {
            anchors.right: parent.right
            spacing: -5

            RoundButton {
                flat: true
                icon.source: "qrc:/pics/save.png"

                HoverHandler {
                    cursorShape: Qt.PointingHandCursor
                }
            }

            RoundButton {
                flat: true
                icon.source: "qrc:/pics/dots.png"
                background: Rectangle {
                    height: 18
                    width: 18
                    radius: 18
                    color: {
                        if (popup.visible)
                            return "#512da8"
                        else if (mouseArea.containsMouse)
                            return "#5e35b1"
                        else
                            return "#673ab7"

                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true

                        onClicked: {
                           popup.popup(background.width - 205, background.height - 5)
                        }
                    }
                }
            }
        }

        MyPopup { id: popup }
    }
}



