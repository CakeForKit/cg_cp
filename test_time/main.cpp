#include "FacadeScene.h"
#include "QtDrawCommand.h"
#include "TrianglesModelLoadCommand.h"
#include "MoveModelCommand.h"
#include "RotateModelCommand.h"
#include "RotateCameraCommand.h"
#include "MaterialSolution.h"
#include "DrawTimeCommand.h"

int main(void)
{
    QApplication app (argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    return app.exec();
    
    FacadeScene facade;

    char filename2[] = "/home/kathrine/cg_cp/data/pawn.txt";
    const char *f2 = &(filename2[0]);

    TrianglesModelLoadCommand load_command2(f2, idMaterial::RED);
    facade.execute(load_command2);

    QGraphicsView graphicsView;
    std::cout << "HERE 1\n";
    DrawTimeCommand time_draw_command(&graphicsView);
    facade.execute(time_draw_command);

    return 0;
}
