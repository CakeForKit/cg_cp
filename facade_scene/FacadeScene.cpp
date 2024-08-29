#include "FacadeScene.h"

#include "VolumeModel.h"
#include "TrianglesModel.h"

FacadeScene::FacadeScene() {
    drawManager = std::make_shared<DrawManager>();
    sceneManager = std::make_shared<SceneManager>();

    std::shared_ptr<Point3> p1, p2, p3;
    p1 = std::make_shared<Point3>(0, 0, 0);
    p2 = std::make_shared<Point3>(20, 0, 0);
    p3 = std::make_shared<Point3>(0, 20, 0);
    // std::shared_ptr<Triangle> tr1 = std::make_shared<Triangle>(p1, p2, p3);
    std::shared_ptr<VolumeModelImpl> trModel1 = std::make_shared<TrianglesModel>();
    trModel1->addVertex(p1);
    trModel1->addVertex(p2);
    trModel1->addVertex(p3);
    trModel1->addFace({p1, p2, p3});
    trModel1->setCenter(Point3(0, 0, 0));
    std::shared_ptr<ObjectScene> model1 = std::make_shared<VolumeModel>(trModel1);
    sceneManager->addModel(model1);


    std::shared_ptr<Point3> p4, p5, p6, p7;
    p4 = std::make_shared<Point3>(-50, 0, 0);
    p5 = std::make_shared<Point3>(-50, 20, 0);
    p6 = std::make_shared<Point3>(-50, 0, -50);
    p7 = std::make_shared<Point3>(0, 30, 0);
    // std::shared_ptr<Triangle> tr2 = std::make_shared<Triangle>(p4, p5, p6);
    // std::shared_ptr<Triangle> tr3 = std::make_shared<Triangle>(p6, p5, p7);

    std::shared_ptr<VolumeModelImpl> trModel2 = std::make_shared<TrianglesModel>();
    trModel2->addVertex(p4);
    trModel2->addVertex(p5);
    trModel2->addVertex(p6);
    trModel2->addVertex(p7);
    trModel2->addFace({p4, p5, p6});
    // trModel2->addFace({p6, p5, p7});
    std::shared_ptr<ObjectScene> model2 = std::make_shared<VolumeModel>(trModel2);
    sceneManager->addModel(model2);

}

void FacadeScene::execute(BaseCommand &cmd) {
    cmd.setManagers(drawManager, sceneManager);
    cmd.execute();
}