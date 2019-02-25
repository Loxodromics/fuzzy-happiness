
#include <QCoreApplication>
#include <QtGui>
#include <QtTest/QtTest>
#include <QSignalSpy>

#include "sceneentity.h"

class GUItest : public QObject
{
    Q_OBJECT

public:
    GUItest();
    ~GUItest();

    Qt3DCore::QNode node;

private slots:
    void initTestCase();
    void test_case1();
};

GUItest::GUItest()
{}

GUItest::~GUItest()
{}

void GUItest::initTestCase()
{
    QTEST_SET_MAIN_SOURCE_PATH;
}

void GUItest::test_case1()
{
    auto sceneEntity = new SceneEntity(&node);
    sceneEntity->loadMesh(QStringLiteral(":/quad.obj"));

    QSignalSpy meshStatusChangedSpy(sceneEntity, &SceneEntity::meshLoaded);
    QVERIFY(meshStatusChangedSpy.wait());
}

QTEST_MAIN(GUItest)

#include "tst_guitest.moc"
