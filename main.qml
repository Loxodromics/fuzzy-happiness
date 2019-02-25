import Qt3D.Core 2.12
import Qt3D.Extras 2.12
import Qt3D.Render 2.12
import QtQuick 2.12
import QtQuick.Scene3D 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Fuzzy Happiness")

    Scene3D {
        id: sceneView
        objectName: "sceneView"
        anchors.fill: parent
        focus: true
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        Entity {
            id: rootEntity
            Camera {
                id: camera
                projectionType: CameraLens.PerspectiveProjection
                fieldOfView: 45
                nearPlane: 0.1
                farPlane: 1000.0
                position: Qt.vector3d(2.0, 4.0, 8.0)
                upVector: Qt.vector3d(0.0, 1.0, 0.0)
                viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
            }
            components: [
                RenderSettings {
                    activeFrameGraph: ForwardRenderer {
                        camera: camera
                        clearColor: "transparent"
                    }
                }
            ]
        }
    }

    Component.onCompleted: {
        sceneEntity.setParent(rootEntity)
    }
}
