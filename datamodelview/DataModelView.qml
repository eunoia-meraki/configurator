// DataModelView.qml
import QtQuick 2.15
import "qrc:/parametersarea"
import "qrc:/modelarea"

Rectangle {
    id: dataModelView
    height: parent.height - toolBar.background.height
    width: parent.width
    anchors.bottom: parent.bottom

    ModelArea { id: modelArea }
    ParametersArea { id: parametersArea }
}
