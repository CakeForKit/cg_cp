#pragma once

#include "ObjectScene.h"
#include "Exceptions.h"
#include "Ray.h"
#include "Vector3.h"

class Camera : public ObjectScene
{
protected:
    Vector3 right, up, dir; // базис x, y, z
    float focalLength;
    Vector3 cameraPos;

    float viewportHeight, viewportWidth;    // высота области просмотра, в координатах
    Vector3 width_of_one_pixel, height_of_one_pixel;   // ширина и высота одного пикселя
    Point3 upperLeftPixelCoord; // координата центра пикселя (0, 0)

public:
    Camera() noexcept;

    void setFocalLength(float focal_length, bool update = true);
    void setViewportHeight(float viewport_height, bool update = true);
    void setCameraPos(Point3 pos, bool update = true) noexcept;
    void setCountPixelsViewport(size_t countPixWidth, size_t countPixHeight, bool update = true);

    void updateUpperLeftPixelCoord();
    /// @brief Создает луч направленный в пиксель (xp, yp)
    Ray createRay(size_t ip, size_t jp);

    std::ostream& print(std::ostream& os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Camera &camera);

