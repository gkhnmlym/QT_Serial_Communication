import QtQuick 2.6
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Serial Port Test"

    Rectangle {
        width: parent.width
        height: parent.height

        Column {
            spacing: 10
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter

            Row {
                spacing: 10
                TextArea {
                    id: messageInput
                    width: parent.width * 0.7
                    height: 30
                    wrapMode: TextArea.Wrap
                }

                Button {
                    text: "Send Message"
                    onClicked: {
                        mainWindow.sendMessage(messageInput.text)
                        messageInput.text = ""
                    }
                }
            }

            Text {
                text: "Received Messages"
                font.bold: true
                font.pixelSize: 16
            }

            ListView {
                id: messageList
                width: parent.width * 0.8
                height: parent.height * 0.7
                model: messageModel
                delegate: Text {
                    text: modelData
                    font.pixelSize: 14
                }
            }
        }
    }
}
