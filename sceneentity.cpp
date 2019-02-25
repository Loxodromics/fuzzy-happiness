#include "sceneentity.h"

#include <Qt3DExtras/QGoochMaterial>
#include <QDebug>

SceneEntity::SceneEntity(Qt3DCore::QNode *parent): Qt3DCore::QEntity(parent)
{
    m_mesh = new Qt3DRender::QMesh(this);
    this->addComponent(m_mesh);

    auto material = new Qt3DExtras::QGoochMaterial(this);
    material->setDiffuse(QColor(QRgb(0x00ee11)));
    this->addComponent(material);
}

void SceneEntity::loadMesh(QString fileNameString)
{
    auto connection =
      QObject::connect(m_mesh, &Qt3DRender::QMesh::statusChanged, this, &SceneEntity::meshStatusChanged);
    assert(static_cast<bool>(connection));

    const QUrl fileUrl(fileNameString);
    m_mesh->setSource(fileUrl);
}

void SceneEntity::meshStatusChanged(Qt3DRender::QMesh::Status status)
{
    using QMesh = Qt3DRender::QMesh;

    if (status == QMesh::Loading)
    {
        qDebug() << "Mesh loading";
    }

    if (status == QMesh::Ready)
    {
        qDebug() << "Mesh loaded";
    }

    if (status == QMesh::Error)
    {
        qDebug() << "Mesh load error";
    }

    emit meshLoaded(status == QMesh::Ready);
}
