
#include "sceneentity.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Qt3DCore::QNode node;
    auto sceneEntity = new SceneEntity(&node);
    sceneEntity->loadMesh();
    engine.rootContext()->setContextProperty(QStringLiteral("sceneEntity"), sceneEntity);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
