/*

. . . . . . . .
. o o . . o o .
. o o . . o o .     HOLOPLOT
. o o o o o o .     www.holoplot.com
. o o o o o o .
. o o . . o o .     Copyright (c) Holoplot GmbH
. o o . . o o .     All rights reserved
. . . . . . . .

*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
