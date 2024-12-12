#include "MainWindow.h"

#include <iostream>
#include <gtest/gtest.h>

#include "Ray.h"

void see_work_ray() {
    Ray ray(Point3(1, -2, 0), Vector3(0, 1, 0));
    Point3 point(0, 0, 0);

    double dist = ray.dist2ToPoint(point);
    std::cout << "dist = " << dist << "\n";
}



int main(int argc, char **argv)
{
    see_work_ray();

    if (argc == 2) {
        std::cout << "See params" << std::endl;

        if (strcmp(argv[1], "-test") == 0) {

            ::testing::InitGoogleTest(&argc, argv);

            return RUN_ALL_TESTS();
        } else if (strcmp(argv[1], "-s") == 0) {
            try {
                // see_work_director();
            } catch (BaseException &ex) {
                std::cout << ex.what() << "\n";
            }
        } else if (strcmp(argv[1], "-time") == 0) {
            QApplication app (argc, argv);
            MainWindow mainwindow;
            mainwindow.show();
            mainwindow.hide();
            mainwindow.measureRenderTime();
            return app.exec();
        }
    } else {
        QApplication app (argc, argv);
        MainWindow mainwindow;
        mainwindow.show();
        return app.exec();
    }

}
