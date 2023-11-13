import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

import RPMControl 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("RPM Dashboard")

    property int rpmCount: control.RPMCount

    onRpmCountChanged: {
        if ( rpmCount <= 3000 ) {
            mainText.color = "#008000"
        } else if ( rpmCount > 3000 && rpmCount <= 6000 ) {
            mainText.color = "#DAA520"
        } else {
            mainText.color = "#DC143C"
        }
    }

    Component.onCompleted: {
        control.doStart();
    }

    RPMControl {
        id: control
    }

    Rectangle {
        width: parent.width
        height: parent.height

        Text {
            id: mainText
            text: "RPM: " + root.rpmCount
            font.pixelSize: 20
            font.bold: true
            anchors.centerIn: parent
        }

        Dial {
            id: rpmDial
            from: 0
            to: 8000
            value: root.rpmCount
            width: parent.width * 0.8
            height: parent.height * 0.8
            stepSize: 1000
            onValueChanged: {
                control.RPMCount = value;
            }
            anchors.centerIn: parent
        }
    }
}
