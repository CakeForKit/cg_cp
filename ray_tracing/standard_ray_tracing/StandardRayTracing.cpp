#include "StandardRayTracing.h"

StandardRayTracing::StandardRayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer,  size_t _maxDepth)
: RayTracing(_scene, _camera, _drawer, _maxDepth) {}

void StandardRayTracing::render(size_t countThreads) {
    if (countThreads == 0) {
        renderOneThread();
    } else {
        renderParallel(countThreads + 1);
    }
    // drawer->setScene();
}

// void castRayForParallel(threadData_t *data)
void *castRayForParallel(void *prlData) {
    threadData_t *data = static_cast<threadData_t*>(prlData);
    data->intens = data->alg->castRay(data->ray);
    pthread_exit(EXIT_SUCCESS);
}

void StandardRayTracing::renderParallel(size_t countThreads) {
    int rc;
    //выделяем память под массив идентификаторов потоков
	pthread_t* threads = static_cast<pthread_t*>(malloc(countThreads * sizeof(pthread_t)));
    assert(threads != NULL);
    //сколько потоков - столько и структур с потоковых данных
	threadData_t* prlData = static_cast<threadData_t*>(malloc(countThreads * sizeof(threadData_t)));
    assert(prlData != NULL);

    int h = drawer->getImgHeight();
    int w = drawer->getImgWidth();
    int hw = h * w;
    int cntThr = static_cast<int>(countThreads);
    int i = 0, ifor = 0, icout = 0;
    int count_for = static_cast<int>(static_cast<double>(hw) / cntThr);
    int count_cout = count_for / 20;
    time_t now_time, st_time = time(NULL);
    for (i = 0; i + cntThr <= hw; i += cntThr, ifor += 1) {
        // Инициализируем данные для функции castRayForParallel и запускаем потоки 
        for (int k = 0; k < cntThr; ++k) {
            (void) k;
            prlData[k].alg = this;
            prlData[k].ray = camera->createRay((i+k) / h, (i+k) % h);
            // std::cout << w << "x" << h << " i = " << i << "(" << (i+k)/h << ", " << (i+k)%h << ")\n";
            rc = pthread_create(&(threads[k]), NULL, &castRayForParallel, &(prlData[k]));
            if (rc != 0)
                assert(false); // TODO
        }
        //ожидаем выполнение всех потоков
        for(int k = 0; k < cntThr; ++k) {
            pthread_join(threads[k], NULL);
            drawer->setPixelColor((i+k) / h, (i+k) % h, Color(prlData[k].intens));
        }
        if (ifor % count_cout == 0) {
            now_time = time(NULL);
            std::cout << icout << "/20 time=" << now_time - st_time << " sec \n";
            icout += 1;
        }
    }
    
    if (i < hw) {
        int partThr = hw - i;
        for (int k = 0; k < partThr; ++k) {
            (void) k;
            prlData[k].alg = this;
            prlData[k].ray = camera->createRay((i+k) / h, (i+k) % h);
            rc = pthread_create(&(threads[k]), NULL, &castRayForParallel, &(prlData[k]));
            if (rc != 0)
                assert(false); // TODO
        }
        for(int k = 0; k < partThr; ++k) {
            pthread_join(threads[k], NULL);
            drawer->setPixelColor((i+k) / h, (i+k) % h, Color(prlData[k].intens));
        }
    }
    free(threads);
    free(prlData);
}

void StandardRayTracing::renderOneThread() {
    std::cout << "\n\nStandardRayTracing::renderOneThread()\n\n";
    for (int j = 0; j < drawer->getImgHeight(); ++j) {
        for (int i = 0; i < drawer->getImgWidth(); ++i) {
            Ray ray = camera->createRay(i, j);
            
            // Intensity intens;
            // if (i == 210 && j == 306) {
            //     intens = castRay(ray, 0, true);
            // } else {
            //     intens = castRay(ray);
            // }
            Intensity intens = castRay(ray);
            drawer->setPixelColor(i, j, Color(intens));
        }
    }
}

// TODO научится определять цвет фона из вне
Intensity StandardRayTracing::castRay(Ray &ray, const size_t depth, bool printing) const noexcept {
    (void) printing;
    if (!ray.getDirection().isNormalized())
        ray.getDirection().normalize();
    // if (printing) {
    //     std::cout << "Ray = " << ray << "\n";

    Intensity color(0, 0, 0);// цвет фона
    intersection_t intersect;
    if (scene->intersection(ray, intersect) && depth <= maxDepth) {
        // if (printing) 
        //     std::cout << intersect << "\n";
        
        Point3 posLight;    // координаты ист света
        Vector3 L;          // век направленный на ист света из точки пересечения
        intersection_t tmpIntersect;
        Vector3 diff, spec;
        bool countReflect = !intersect.material->getKs().isNull();
        double ddist;
        for (Scene::iteratorLight it = scene->beginLight(); it != scene->endLight(); ++it) {
            if ((*it)->getType() == typeLight::POINT) {
                // Диффузное отражение: kd * Il * (n*L)

                assert((*it)->getPos(posLight));
                L = (posLight - intersect.point).normalized();  

                if (fabs(intersect.normal.length()) < EPS) {
                    // std::cout << "inters = " << intersect << "\n";
                    return Intensity(1, 0, 0);
                }
                if (!intersect.normal.isNormalized())
                    intersect.normal.normalize();
                double nL = L.scalarProduct(intersect.normal);  // (n * L)

                // Если век направленный на источник света не пересекается ни с какими обьектами (точка НЕ в тени)
                if (nL > 0 && !scene->intersection(Ray(intersect.point + 1e-3 * intersect.normal, L), tmpIntersect)) {

                    diff = intersect.material->getKd() * nL;
                    // if (printing) {
                    //     std::cout << "Diff: \n";
                    //     std::cout << "norm = " << intersect.normal << ", \nL = " << L << "\n";
                    //     std::cout << "kd = " << intersect.material->getKd() << "\n";
                    //     std::cout << "diff = " << diff << "\n\n";
                    // }

                    // Зеркальное отражение (света - блик)
                    if (countReflect) {
                        Vector3 reflectLight = L.reflect(intersect.normal);
                        double SR = reflectLight.scalarProduct(-ray.getDirection());
                        if (SR < 0)
                            SR = 0;

                        spec = intersect.material->getKs() * pow(SR, intersect.material->getN());
                        // if (printing) {
                        //     std::cout << "Reflect: \n";
                        //     std::cout << "S = " << reflectLight << ", \nR = " << -ray.getDirection() << "\n";
                        //     std::cout << "SR = " << SR << ", n = " << intersect.material->getN() << "\n";
                        //     std::cout << "ks = " << intersect.material->getKs() << "\n";
                        //     std::cout << "spec = " << spec << "\n\n";
                        // }
                    } else
                        spec = Vector3(0, 0, 0);

                    ddist = 1.2 * (posLight - intersect.point).length() / (posLight.length() + EPS);
                    if (ddist > 1.0)
                        ddist = 1;
                    else if (ddist < 0.4)
                        ddist = 0.4;
                    color += (diff + spec) * (*it)->getIntensity() / ddist;  
                    // if (printing) {
                    //     std::cout << "diff + spec: \n";
                    //     std::cout << "I_l = " << (*it)->getIntensity() << ", dist_to_camera = " << dist_to_camera << "\n";
                    //     std::cout << "+color = " << (diff + spec) * (*it)->getIntensity() / (dist_to_camera / light_dist_to_camera + EPS) << "\n\n";
                    // }
                }

            } else if ((*it)->getType() == typeLight::AMBIENT) {
                color += intersect.material->getKa() * (*it)->getIntensity();
                // if (printing) {
                //     std::cout << "AMBIENT: \n";
                //     std::cout << "I_l = " << (*it)->getIntensity() << ", ka = " << intersect.material->getKa() << "\n";
                //     std::cout << "+color = " << intersect.material->getKa() * (*it)->getIntensity() << "\n\n";
                // }
            } else {
                assert(false);
            }
            // std::cout << "Color = " << Intensity(static_cast<int>(std::round(color.x() * 255)), 
            //                                     static_cast<int>(std::round(color.y() * 255)), 
            //                                     static_cast<int>(std::round(color.z() * 255))) << "\n";
        }
        
        if (countReflect) {
            // Выпускаем луч отражения
            Vector3 reflectVec = ray.getDirection().reflect(intersect.normal);
            Ray reflectRay(intersect.point + 1e-3 * intersect.normal, reflectVec);
            Intensity reflectIntensity = castRay(reflectRay, depth + 1);
            color += intersect.material->getKs() * reflectIntensity; // Зеркальное отражение в глобальной модели освещения
            // if (printing) {
            //     std::cout << "ADD REFLECT Ray: \n";
            //     std::cout << "reflectIntensity = " << reflectIntensity << ", ks = " << intersect.material->getKs() << "\n";
            //     std::cout << "+color = " << intersect.material->getKs() * reflectIntensity << "\n\n";
            //     std::cout << "ИТОГ: " << color << "\n\n";
            // }
        }
    } else {
        // color = Intensity(0, 0, 0);
        color = Intensity(0.3, 0.3, 0.3);
        // color = Intensity(0.93, 0.678, 0.678);
    }
    return color;
}

