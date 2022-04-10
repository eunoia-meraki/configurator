import QtQuick 2.15
import TreeModel 1.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3
import "qrc:/drawer"
import "qrc:/toolbar"
import "qrc:/datamodelview"
import "qrc:/mappingview"

ApplicationWindow {
    id: appWindow

    function enableDataModelView()
    {
        mappingView.visible = false
        dataModelView.visible = true
    }

    function enableMappingView()
    {
        dataModelView.visible = false
        mappingView.visible = true
    }

    width: 860
    height: 640
    visible: true
    title: qsTr("Hello World")
    Material.background: "#ffffff"
    header: MyToolBar { id: toolBar }
    Pane { anchors.fill: parent; focusPolicy: Qt.ClickFocus }

    MyDrawer {
        id: drawer
        onTriggered: {
            if (view === 1)
                appWindow.enableDataModelView()
            else if (view === 2)
                appWindow.enableMappingView()
        }
    }

    DataModelView { id: dataModelView; visible: false }
    MappingView { id: mappingView }

    TreeModel { id: treeModel }

    FileDialog {
        id: fileDialog
        title: qsTr("Choose XML file")
        folder: shortcuts.desktop
        nameFilters: ["XML files (*.xml)"]
        onAccepted: treeModel.setupModelData(fileUrl)
    }

}

