//CBranchDelegate.qml
import QtQuick 2.15

Image {
    source : {
        if (styleData.isExpanded)
            return mouseArea.containsMouse ? "qrc:/pics/arrow-down.png" : "qrc:/pics/arrow-blur-down.png"
        else
            return mouseArea.containsMouse ? "qrc:/pics/arrow-right.png" : "qrc:/pics/arrow-blur-right.png"
    }

    sourceSize.width: 15
    sourceSize.height: 15

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onPressed: {
            if (!styleData.isExpanded)
                treeView.expand(styleData.index)
            else
                treeView.collapse(styleData.index)
        }
    }
}







