cmake_minimum_required(VERSION 3.22)

project(coursework_chess LANGUAGES CXX)   # название проекта
set(CMAKE_CXX_STANDARD 20)
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
    exceptions
    object_scene
    object_scene/model
    object_scene/model/triangles
    ray
    scene
    triangle
    vector3
    
    tests
)

set(SRCS 
    config.h

    camera/Camera.h
    camera/Camera.cpp

    exceptions/BaseException.h
    exceptions/BaseException.cpp
    exceptions/Exceptions.h

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

    scene/Scene.h
    scene/Scene.cpp

    triangle/Triangle.h
    triangle/Triangle.cpp

    vector3/Vector3.h
    vector3/Vector3.cpp
)

# google tests
add_executable(tests.exe 
    tests/main.cpp
    tests/camera_tests.cpp

    "${SRCS}"
    )

target_link_libraries(tests.exe gtest gmock pthread)
## 

add_executable(app.exe 
    main.cpp
    "${SRCS}"
    )

# Qt5

# QGraphicsView Class
find_package(Qt5 REQUIRED COMPONENTS Widgets)
target_link_libraries(app.exe PRIVATE Qt5::Widgets)

#Qimage
find_package(Qt6 REQUIRED COMPONENTS Gui)
target_link_libraries(mytarget PRIVATE Qt6::Gui)

