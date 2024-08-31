cmake_minimum_required(VERSION 3.22)

project(coursework_chess LANGUAGES CXX)   # название проекта
set(CMAKE_CXX_STANDARD 20)

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
    commands
    commands/draw_commands
    data_structs
    drawer
    exceptions
    facade_scene
    gui
    load
    load/builder
    load/builder/triangles_model_builder
    load/director
    load/director/volume_model_director
    load/director/volume_model_director/triangles_model_director
    load/reader
    load/reader/volume_model_reader
    load/reader/volume_model_reader/triangles_model_reader/
    managers
    object_scene
    object_scene/model
    object_scene/model/triangles
    ray
    ray_tracing
    ray_tracing/standard_ray_tracing
    scene
    triangle
    vector3
    
    tests
)

set(SRCS 
    config.h

    camera/Camera.h
    camera/Camera.cpp

    commands/BaseCommand.h
    commands/BaseCommand.cpp
    commands/draw_commands/BaseDrawCommand.h
    commands/draw_commands/BaseDrawCommand.cpp 
    commands/draw_commands/QtDrawCommand.h
    commands/draw_commands/QtDrawCommand.cpp

    data_structs/intersection_type.h
    data_structs/intersection_type.cpp

    drawer/Color.h
    drawer/Color.cpp
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

    load/reader/Reader.h
    load/reader/Reader.cpp
    load/reader/volume_model_reader/VolumeModelReader.h
    load/reader/volume_model_reader/VolumeModelReader.cpp
    load/reader/volume_model_reader/triangles_model_reader/TrianglesModelReader.h
    load/reader/volume_model_reader/triangles_model_reader/TrianglesModelReader.cpp


    managers/DrawManager.h
    managers/DrawManager.cpp
    managers/SceneManager.h
    managers/SceneManager.cpp

    object_scene/ObjectScene.h 
    object_scene/ObjectScene.cpp
    object_scene/CompositeObjectScene.h
    object_scene/CompositeObjectScene.cpp

    object_scene/model/BaseModel.h
    object_scene/model/BaseModel.cpp
    object_scene/model/VolumeModel.h
    object_scene/model/VolumeModel.cpp
    object_scene/model/VolumeModelImpl.h
    object_scene/model/VolumeModelImpl.cpp
    object_scene/model/triangles/TrianglesModel.h
    object_scene/model/triangles/TrianglesModel.cpp

    ray/Ray.h
    ray/Ray.cpp

    ray_tracing/RayTracing.h
    ray_tracing/RayTracing.cpp
    ray_tracing/standard_ray_tracing/StandardRayTracing.h
    ray_tracing/standard_ray_tracing/StandardRayTracing.cpp 

    scene/Scene.h
    scene/Scene.cpp

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
)

# # google tests
# add_executable(tests.exe 
#     tests/main.cpp
#     tests/camera_tests.cpp

#     "${SRCS}"
#     )


 

add_executable(app.exe 
    main.cpp
    "${SRCS}"
    "${TESTS}"
    )

# gtests
# Qt5
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)
target_link_libraries(app.exe PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core
gtest gmock pthread)

# target_link_libraries(app.exe gtest gmock pthread)
