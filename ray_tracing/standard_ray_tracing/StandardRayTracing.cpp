#include "StandardRayTracing.h"

StandardRayTracing::StandardRayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer,  size_t _maxDepth)
: RayTracing(_scene, _camera, _drawer, _maxDepth) {}

void StandardRayTracing::render() {
    for (int j = 0; j < drawer->getImgHeight(); ++j) {
        for (int i = 0; i < drawer->getImgWidth(); ++i) {
            Ray ray = camera->createRay(i, j);
            Intensity intens = castRay(ray);
            // bool problem = !(0 <= intens.x() && intens.x() <= 1 &&
            //                 0 <= intens.y() && intens.y() <= 1 &&
            //                 0 <= intens.z() && intens.z() <= 1);
            // if (problem)
            //     std::cout << intens << "\n";
            // Color color(static_cast<int>(std::round(intens.x() * 255)), 
            //             static_cast<int>(std::round(intens.y() * 255)), 
            //             static_cast<int>(std::round(intens.z() * 255)));
            Color color(intens);

            drawer->setPixelColor(i, j, color);
        }
    }


    drawer->setScene();
}

// TODO научится определять цвет фона из вне
Intensity StandardRayTracing::castRay(Ray &ray, const size_t depth) const noexcept {
    (void) depth;
    if (!ray.getDirection().isNormalized())
        ray.getDirection().normalize();

    Intensity color(0, 0, 0);// цвет фона

    intersection_t intersect;
    if (scene->intersection(ray, intersect) && depth < maxDepth) {
        
        // Выпускаем луч отражения
        Vector3 reflectVec = ray.getDirection().reflect(intersect.normal);
        Ray reflectRay(intersect.point + 1e-3 * intersect.normal, reflectVec);
        Intensity reflectIntensity = castRay(reflectRay, depth + 1);
        // Зеркальное отражение в глобальной модели освещения
        color += intersect.material->getKs() * reflectIntensity;


        Point3 posLight;    // координаты ист света
        Vector3 L;          // век направленный на ист света из точки пересечения
        intersection_t tmpIntersect;
        Vector3 diff, spec;
        for (Scene::iteratorLight it = scene->beginLight(); it != scene->endLight(); ++it) {

            if ((*it)->getType() == typeLight::POINT) {
                // Диффузное отражение: kd * Il * (n*L)
                
                assert((*it)->getPos(posLight));
                L = (posLight - intersect.point).normalized();  

                if (!intersect.normal.isNormalized())
                    intersect.normal.normalize();
                double nL = L.scalarProduct(intersect.normal);  // (n * L)

                // Если век направленный на источник света не пересекается ни с какими обьектами (точка НЕ в тени)
                if (nL > 0 && !scene->intersection(Ray(intersect.point + 1e-3 * intersect.normal, L), tmpIntersect)) {

                    diff = intersect.material->getKd() * nL;

                    // Зеркальное отражение (света - блик)
                    Vector3 reflectLight = L.reflect(intersect.normal);
                    double SR = reflectLight.scalarProduct(-ray.getDirection());
                    if (SR < 0)
                        SR = 0;

                    spec = intersect.material->getKs() * pow(SR, intersect.material->getN());
                    
                    color += (diff + spec) * (*it)->getIntensity() / (intersect.distance / 100 + EPS);  // TODO деление на 100 надо запихнуть в config
                }

            } else if ((*it)->getType() == typeLight::AMBIENT) {
                color += intersect.material->getKa() * (*it)->getIntensity();

            } else {
                assert(false);
            }

            // std::cout << "Color = " << Intensity(static_cast<int>(std::round(color.x() * 255)), 
            //                                     static_cast<int>(std::round(color.y() * 255)), 
            //                                     static_cast<int>(std::round(color.z() * 255))) << "\n";
        }
        
        // std::cout << "Color = " << color << "\n";
    }
    else {
        // color = Intensity(0.5, 0.5, 0.5);
        color = Intensity(0, 0, 0);
    }
    
    
    return color;
}
