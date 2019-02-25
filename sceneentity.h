#ifndef SCENEENTITY_H
#define SCENEENTITY_H

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QMesh>

class SceneEntity : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit SceneEntity(Qt3DCore::QNode *parent = nullptr);

    void loadMesh(QString fileNameString);

    Qt3DRender::QMesh *m_mesh = nullptr;

public slots:
    void meshStatusChanged(Qt3DRender::QMesh::Status status);

signals:
    void meshLoaded(bool success);
};

#endif    // SCENEENTITY_H
