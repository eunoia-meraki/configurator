// ParametersArea.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import TreeModel 1.0
//import TreeItem 1.0

import "qrc:/mytypes"

Rectangle {
    id: parametersArea
    property var currentIndex

    function displayParameters(model)
    {
        if (model.itemType === /*TreeItem.LD*/ 1)
        {
            ldName.text = model.name
            ldDescription.text = model.description
            lnParameters.visible = false
            doParameters.visible = false
            ldParameters.visible = true
            currentIndex = model.qModelIndex
        }

        if (model.itemType === /*TreeItem.LN*/ 2)
        {
            lnClass.text = model.name
            lnDescription.text = model.description
            ldParameters.visible = false
            doParameters.visible = false
            lnParameters.visible = true
            currentIndex = model.qModelIndex
        }

        if (model.itemType === /*TreeItem.DO*/ 3)
        {
            doDescription.text = model.description
            ldParameters.visible = false
            lnParameters.visible = false
            doParameters.visible = true
            currentIndex = model.qModelIndex
        }
    }

    function setLdParameters(name, description)
    {
        treeModel.setData(currentIndex, name, TreeModel.NameRole)
        treeModel.setData(currentIndex, description, TreeModel.DescriptionRole)
    }

    function setLnParameters(prefix, lnClass, number, description)
    {

        treeModel.setData(currentIndex, lnClass, TreeModel.NameRole)
        treeModel.setData(currentIndex, description, TreeModel.DescriptionRole)
    }

    function setDoParameters(description)
    {
        treeModel.setData(currentIndex, description, TreeModel.DescriptionRole)
    }

    anchors.left: modelArea.right
    width: parent.width - modelArea.width
    height: parent.height

    Rectangle {
        id: header
        height: 32

        Text {
            text: "Parameters"
            font.pointSize: 10
            font.weight: Font.DemiBold
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            color: "#212121"
        }
    }

    ColumnLayout {
        id: ldParameters
        visible: false
        spacing: 30
        anchors.top: header.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 20

        MyTextField {
            id: ldName
            labelText: "Name"
            errorText: "The value must not be empty"
            validator: RegularExpressionValidator { regularExpression: /[A-Za-z0-9][0-9A-Za-z_]*/ }
            maximumLength: 64
            onTextEdited: parametersArea.setLdParameters(ldName.text, ldDescription.text)
        }

        MyTextField {
            id: ldDescription
            labelText: "Description"
            onTextEdited: parametersArea.setLdParameters(ldName.text, ldDescription.text)

        }
    }

    ColumnLayout {
        id: lnParameters
        visible: false
        spacing: 30
        anchors.top: header.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 20

        MyTextField {
            id: lnPrefix
            labelText: "Prefix"
            errorText: "The value must not be empty"
            validator: RegularExpressionValidator { regularExpression: /^$|[A-Za-z][0-9A-Za-z_]*/ }
            maximumLength: 12
            enabled: lnClass.text === "LLN0" ? false : true
        }

        MyTextField {
            id: lnClass
            labelText: "Class"
            enabled: false
            onTextEdited: parametersArea.setLnParameters(lnPrefix.text, lnClass.text, lnNumber.text, lnDescription.text)
        }

        MyTextField {
            id: lnNumber
            labelText: "Number"
            errorText: "The value must not be empty"
            validator: RegularExpressionValidator { regularExpression: lnNumber.enabled ? /[0-9]{1,12}/ : /^$|[0-9]{1,12}/ }
            enabled: lnClass.text === "LLN0" ? false : true
        }

        MyTextField {
            id: lnDescription
            labelText: "Description"
            onTextEdited: parametersArea.setLnParameters(lnPrefix.text, lnClass.text, lnNumber.text, lnDescription.text)
        }
    }

    ColumnLayout {
        id: doParameters
        visible: false
        spacing: 30
        anchors.top: header.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 20

        MyTextField {
            id: doDescription
            labelText: "Description"
            onTextEdited: parametersArea.setDoParameters(doDescription.text)
        }
    }


}
