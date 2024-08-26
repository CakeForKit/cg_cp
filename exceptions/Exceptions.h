#pragma once
#include "BaseException.h"

#pragma region Scene

class LastCameraSceneException: public SceneException
{
public:
    LastCameraSceneException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Can't delete the last camera") noexcept:
                  SceneException(time, filename, line, class_name, method_name, info){};
};

#pragma region end

#pragma region Camera

class CountPixelsCameraException: public CameraException
{
public:
    CountPixelsCameraException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Count pixels wight or height can not be 0") noexcept:
                  CameraException(time, filename, line, class_name, method_name, info){};
};

class FocalLengthCameraException: public CameraException
{
public:
    FocalLengthCameraException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Focal length can not be < 0") noexcept:
                  CameraException(time, filename, line, class_name, method_name, info){};
};

class ViewportHeightCameraException: public CameraException
{
public:
    ViewportHeightCameraException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Viewport height can not be < 0") noexcept:
                  CameraException(time, filename, line, class_name, method_name, info){};
};

#pragma region end


#pragma region TrianglesModel

// class PointExistsTrianglesModelException: public TrianglesModelException
// {
// public:
//     PointExistsTrianglesModelException(const char *time, const char *filename,
//                   const size_t line, const char *class_name,
//                   const char *method_name, const char *info = "Try to add existing point to triangleModel") noexcept:
//                   TrianglesModelException(time, filename, line, class_name, method_name, info){};
// };

// class TriangleExistsTrianglesModelException: public TrianglesModelException
// {
// public:
//     TriangleExistsTrianglesModelException(const char *time, const char *filename,
//                   const size_t line, const char *class_name,
//                   const char *method_name, const char *info = "Try to add existing triangle to triangleModel") noexcept:
//                   TrianglesModelException(time, filename, line, class_name, method_name, info){};
// };

class SizeFaceTrianglesModelException: public TrianglesModelException
{
public:
    SizeFaceTrianglesModelException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Number of vertices in a face is not 3") noexcept:
                  TrianglesModelException(time, filename, line, class_name, method_name, info){};
};

#pragma region end

#pragma region Triangle

class SamePointsTriangleException: public TriangleException
{
public:
    SamePointsTriangleException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Try create Triangle from same points") noexcept:
                  TriangleException(time, filename, line, class_name, method_name, info){};
};

class DegenerateTriangleException: public TriangleException
{
public:
    DegenerateTriangleException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Try create degenerate Triangle") noexcept:
                  TriangleException(time, filename, line, class_name, method_name, info){};
};

#pragma region end