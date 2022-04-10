//RowButton.qml
import QtQuick 2.15

Image {
    property string regularSource: ""
    property string blurSource: ""
    signal pressed()
    sourceSize.width: 18
    sourceSize.height: 18
    source: mouseArea.containsMouse ? regularSource : blurSource

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onPressed: { parent.pressed() }
    }
}
