cmake_minimum_required(VERSION 3.22)

project(coursework_chess LANGUAGES CXX)   # название проекта
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS --coverage)

set(CMAKE_AUTOMOC ON)
# автоматическая генерация ui_mainWindow.h в "./build/app.exe_autogen/include/ui_mainWindow.h"
set(CMAKE_AUTOUIC ON) 

add_compile_options(
    -Werror
    -Wno-unknown-pragmas

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

include_directories(
    .
    camera
    chessboard
    color
    commands
    commands/camera_commands
    commands/draw_commands
    commands/load_commands
    commands/material_commands
    commands/scene_commands
    commands/transform_commands
    commands/time_commands
    data_structs
    drawer
    exceptions
    facade_scene
    gui
    light
    load
    load/builder
    load/builder/triangles_model_builder
    load/director
    load/director/volume_model_director
    load/director/volume_model_director/triangles_model_director
    load/director/chessboard_director
    load/director_solution
    load/reader
    load/reader/volume_model_reader
    load/reader/volume_model_reader/triangles_model_reader/
    load/reader/data_chessborad_reader
    load/reader_solution
    material
    managers
    maps
    matrix4
    model
    model/volume_model
    model/volume_model/triangles
    ray
    ray_tracing
    ray_tracing/standard_ray_tracing
    scene
    transform
    triangle
    vector3
    
    tests
)

set(SRCS 
    config.h

    camera/Camera.h
    camera/Camera.cpp

    chessboard/Chessboard.h
    chessboard/Chessboard.cpp

    color/Color.h
    color/Color.cpp

    commands/BaseCommand.h
    commands/BaseCommand.cpp
    commands/camera_commands/RotateCameraCommand.h
    commands/camera_commands/RotateCameraCommand.cpp
    commands/camera_commands/MoveCameraCommand.h
    commands/camera_commands/MoveCameraCommand.cpp
    commands/draw_commands/BaseDrawCommand.h
    commands/draw_commands/BaseDrawCommand.cpp 
    commands/draw_commands/QtDrawCommand.h
    commands/draw_commands/QtDrawCommand.cpp
    commands/load_commands/BaseLoadCommand.h
    commands/load_commands/BaseLoadCommand.cpp
    commands/load_commands/TrianglesModelLoadCommand.h
    commands/load_commands/TrianglesModelLoadCommand.cpp
    commands/load_commands/TrianglesChessboardLoadCommand.h
    commands/load_commands/TrianglesChessboardLoadCommand.cpp
    commands/material_commands/SetActiveMaterialCommand.h
    commands/material_commands/SetActiveMaterialCommand.cpp
    commands/material_commands/SetChessboardMaterialCommand.cpp
    commands/material_commands/SetChessboardMaterialCommand.h
    commands/scene_commands/FillModelsTableCommand.h
    commands/scene_commands/FillModelsTableCommand.cpp
    commands/transform_commands/MoveCellModelCommand.cpp
    commands/transform_commands/MoveCellModelCommand.h
    commands/transform_commands/TransformCommand.h
    commands/transform_commands/TransformCommand.cpp
    commands/transform_commands/MoveModelCommand.h
    commands/transform_commands/MoveModelCommand.cpp
    commands/transform_commands/RemoveModelCommand.h
    commands/transform_commands/RemoveModelCommand.cpp
    commands/transform_commands/RotateModelCommand.h
    commands/transform_commands/RotateModelCommand.cpp
    commands/time_commands/DrawTimeCommand.h
    commands/time_commands/DrawTimeCommand.cpp

    data_structs/intersection_type.h
    data_structs/intersection_type.cpp
    data_structs/concepts.h

    drawer/Drawer.h
    drawer/Drawer.cpp
    drawer/QtDrawer.h
    drawer/QtDrawer.cpp

    exceptions/BaseException.h
    exceptions/BaseException.cpp
    exceptions/Exceptions.h

    facade_scene/FacadeScene.h
    facade_scene/FacadeScene.cpp

    gui/mainWindow.ui
    gui/MainWindow.h
    gui/MainWindow.cpp

    light/Light.h
    light/Light.cpp

    load/builder/VolumeModelBuilder.h
    load/builder/VolumeModelBuilder.cpp
    load/builder/triangles_model_builder/TrianglesModelBuilder.h
    load/builder/triangles_model_builder/TrianglesModelBuilder.cpp

    load/director/Director.h
    load/director/Director.cpp
    load/director/volume_model_director/VolumeModelDirector.h
    load/director/volume_model_director/VolumeModelDirector.cpp
    load/director/volume_model_director/triangles_model_director/TrianglesModelDirector.h
    load/director/volume_model_director/triangles_model_director/TrianglesModelDirector.cpp
    load/director/chessboard_director/ChessboardDirector.cpp
    load/director/chessboard_director/ChessboardDirector.h

    load/director_solution/DirectorCreator.h
    load/director_solution/DirectorCreator.cpp
    load/director_solution/DirectorSolution.h
    load/director_solution/DirectorSolution.cpp

    load/reader/Reader.h
    load/reader/Reader.cpp
    load/reader/volume_model_reader/VolumeModelReader.h
    load/reader/volume_model_reader/VolumeModelReader.cpp
    load/reader/volume_model_reader/triangles_model_reader/TrianglesModelReader.h
    load/reader/volume_model_reader/triangles_model_reader/TrianglesModelReader.cpp
    load/reader/data_chessborad_reader/DataChessboardReader.h
    load/reader/data_chessborad_reader/DataChessboardReader.cpp

    load/reader_solution/ReaderCreator.h
    load/reader_solution/ReaderCreator.cpp
    load/reader_solution/ReaderSolution.h
    load/reader_solution/ReaderSolution.cpp

    material/Material.h
    material/Material.cpp
    material/MaterialSolution.h
    material/MaterialSolution.cpp

    managers/DrawManager.h
    managers/DrawManager.cpp
    managers/SceneManager.h
    managers/SceneManager.cpp
    managers/LoadManager.h
    managers/LoadManager.cpp
    managers/MaterialManager.h
    managers/MaterialManager.cpp
    managers/TransformManager.h
    managers/TransformManager.cpp

    maps/dataMaps.h
    maps/dataMaps.cpp

    matrix4/Matrix4.h
    matrix4/Matrix4.cpp

    model/Model.h 
    model/Model.cpp

    model/volume_model/VolumeModel.h
    model/volume_model/VolumeModel.cpp
    model/volume_model/VolumeModelImpl.h
    model/volume_model/VolumeModelImpl.cpp
    model/volume_model/triangles/TrianglesModel.h
    model/volume_model/triangles/TrianglesModel.cpp

    ray/Ray.h
    ray/Ray.cpp

    ray_tracing/RayTracing.h
    ray_tracing/RayTracing.cpp
    ray_tracing/standard_ray_tracing/StandardRayTracing.h
    ray_tracing/standard_ray_tracing/StandardRayTracing.cpp 

    scene/Scene.h
    scene/Scene.cpp

    transform/TransformAction.h
    transform/TransformAction.cpp
    transform/MoveAction.h
    transform/MoveAction.cpp
    transform/RotateAction.h
    transform/RotateAction.cpp

    triangle/Triangle.h
    triangle/Triangle.cpp

    vector3/Vector3.h
    vector3/Vector3.cpp
)

set(TESTS
    tests/camera_tests.h
    tests/camera_tests.cpp

    tests/triangle_intersection_tests.h
    tests/triangle_intersection_tests.cpp

    tests/reflect_refract_tests.h
    tests/reflect_refract_tests.cpp

    # tests/std_ray_tracing_test.h
    # tests/std_ray_tracing_test.cpp
) 

add_executable(app.exe
    main.cpp
    ${SRCS}
    ${TESTS}
    )

# add_executable(test.exe 
#     ${TESTS} 
#     ${SRCS}
#     )

# gtests
# Qt5
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)
target_link_libraries(app.exe 
    PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core
    gtest gmock pthread)

# target_link_libraries(test.exe 
#     PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core
#     gtest gmock pthread)

# target_link_libraries(app.exe gtest gmock pthread)
