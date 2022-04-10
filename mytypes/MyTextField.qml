// MyTextField.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

TextField {
    id: textField
    property string labelText: "Label"
    property string errorText: "Error"

    Material.accent: textField.acceptableInput ? "#673ab7" : "#e53935"
    implicitWidth: 300
    font.pointSize: 10
    selectByMouse: true
    color: textField.enabled ? "#212121" : "#9e9e9e"

    background: Rectangle {
        id: background
        anchors.bottom: textField.bottom
        anchors.bottomMargin: 10
        height: textField.activeFocus ? 2 : 1
        color: textField.enabled ? (textField.acceptableInput ? (textField.activeFocus ? "#673ab7" : "#212121") : "#e53935") : "#9e9e9e"
    }

    Label {
        id: label
        topPadding: textField.length !== 0 ? -9 : 10
        font.pointSize: textField.length !== 0 ? 8 : textField.font.pointSize
        color: textField.enabled ? (textField.activeFocus ? (textField.acceptableInput ? "#673ab7" : "#e53935") : "#616161") : "#9e9e9e"
        text: textField.labelText
    }

    Label {
        id: error
        topPadding: 32
        font.pointSize: 8
        color: "#e53935"
        text: textField.errorText
        visible: !textField.acceptableInput
    }

    states: [

        State {
            name: "state1"
            when: textField.activeFocus

            PropertyChanges {
                target: label
                topPadding: - 9
                font.pointSize: 8
            }
        }
    ]

    transitions: [

        Transition {
            from: ""
            to: "state1"
            reversible: true

            NumberAnimation {
                target: label
                properties: "topPadding, font.pointSize"
                duration: 90
            }
        }
    ]
}
