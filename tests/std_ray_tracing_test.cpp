#include "std_ray_tracing_test.h"

// Window::Window(QWidget *parent): QMainWindow(parent)
// {
//     scene=new QGraphicsScene(this);
//     graphicsView=new QGraphicsView(this);
//     graphicsView->setScene(scene);
//     scene->setSceneRect(0, 0, 388, 572);
//     setCentralWidget(graphicsView);
// }

// void Window::setImg(QImage &img) {
//     QGraphicsScene* scene = new QGraphicsScene();
//     scene->addPixmap(QPixmap::fromImage(*img));
//     graphicsView->setScene(scene);
// }

// void Window::closee() {
//     this->close();
// }
 

class TestRayTracing : public testing::TestWithParam<raytracing_test_data_t> 
{
public:
    // QApplication app = QApplication(argc, NULL);
    std::shared_ptr<Camera> camera;
    std::shared_ptr<RayTracing> rayTracing;
protected:
    void SetUp() override {
        int img_width = 201;
        int img_height = 512;

        std::shared_ptr<DrawManager> drawManager = std::make_shared<DrawManager>();
        std::shared_ptr<SceneManager> sceneManager = std::make_shared<SceneManager>();
        std::shared_ptr<LoadManager> loadManager = std::make_shared<LoadManager>();
        std::shared_ptr<MaterialManager> materialManager = std::make_shared<MaterialManager>();
        std::shared_ptr<TransformManager> transformManager = std::make_shared<TransformManager>();
        idReaderCreator id_reader = idReaderCreator::TRIANGLES;
        idDirectorCreator id_director = idDirectorCreator::TRIANGLES;
        size_t stepOfRevolving = 10;
        {
            const char *filename = "/home/kathrine/cg_cp/tests/data_for_tests/test_model_4.txt";
            std::shared_ptr<Material> material = materialManager->getMaterial(idMaterial::GLOSSY_WHITE);
            PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
            sceneManager->addModel(model, 3, 4);
        }
        {
            const char *filename = "/home/kathrine/cg_cp/tests/data_for_tests/pawn.txt";
            std::shared_ptr<Material> material = materialManager->getMaterial(idMaterial::RED);
            PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
            sceneManager->addModel(model, 4, 4);
        }
        
        std::shared_ptr<QImage> img = std::make_shared<QImage>(img_width, img_height, QImage::Format_RGB32);
        std::shared_ptr<Drawer> drawer = std::make_shared<QtDrawer>(img);
        std::shared_ptr<Scene> scene = sceneManager->getScene();
        scene->show_chessboard = 0;
        camera = scene->getActiveCamera();
        transformManager->moveCamera(camera, 400, false);
        size_t pixelsWidth = static_cast<size_t>(drawer->getImgWidth());
        size_t pixelsHeight = static_cast<size_t>(drawer->getImgHeight());
        camera->setCountPixelsViewport(pixelsWidth, pixelsHeight);
        
        std::cout << "Camera---------\n" << *camera << "\n\n";
        
        rayTracing = std::make_shared<StandardRayTracing>(scene, camera, drawer);

        // Window window;
        // window.show();
        // window.hide();
        
    }

    // void TearDown() override {
    //     app.exit();
    // }
};

TEST_P(TestRayTracing, DiffRays) {
    raytracing_test_data_t tdata = GetParam();
    Ray ray = camera->createRay(tdata.xi, tdata.yi);
    // std::cout << "xi = " << tdata.xi << ", yi = " << tdata.yi << "\n";
    // std::cout << "Ray-------------- " << ray << "\n";
    Intensity intens = rayTracing->castRay(ray);
    std::cout << "\n\nintens = " << intens << "\n\n";
    EXPECT_TRUE(intens == tdata.expIntens);
}



INSTANTIATE_TEST_SUITE_P(
    RayTracingTestSuite,
    TestRayTracing,
    testing::Values(
        raytracing_test_data[0],
        raytracing_test_data[1], 
        raytracing_test_data[2], 
        raytracing_test_data[3]
    )
);
