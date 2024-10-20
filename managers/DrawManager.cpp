#include "DrawManager.h"


void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, std::shared_ptr<Drawer> drawer) {
    // Получение размера экрана вывода в пикселях и передала этих размеров камере для просвета координат левого верхнего пикселя
    size_t pixelsWidth = static_cast<size_t>(drawer->getImgWidth());
    size_t pixelsHeight = static_cast<size_t>(drawer->getImgHeight());
    camera->setCountPixelsViewport(pixelsWidth, pixelsHeight);
    // Создаем класс-стратегию алгоритма трассировки лучей
    //  TODO сделать CreateSolution для RayTracing
    std::shared_ptr<RayTracing> rayTracing = std::make_shared<StandardRayTracing>(scene, camera, drawer);

    // std::cout << "DrawManager::drawScene    scene\n" << *scene << std::endl;
    rayTracing->render();
}

// вычисляет разность времени в микросекундах
long int calc_elapsed_time(const struct timeval *beg, const struct timeval *end)
{
    return ((end->tv_sec - beg->tv_sec) * 1000 * 1000 +
            end->tv_usec - beg->tv_usec);
}

void DrawManager::collectTimeDataDrawScene(char *filename, std::shared_ptr<Scene> scene,
                                                            std::shared_ptr<Camera> camera, 
                                                            std::shared_ptr<Drawer> drawer) {
    size_t pixelsWidth = static_cast<size_t>(drawer->getImgWidth());
    size_t pixelsHeight = static_cast<size_t>(drawer->getImgHeight());
    camera->setCountPixelsViewport(pixelsWidth, pixelsHeight);
    std::shared_ptr<RayTracing> rayTracing = std::make_shared<StandardRayTracing>(scene, camera, drawer);

    // std::cout << "WxH = " << pixelsWidth << "x" << pixelsHeight << std::endl;

    struct timeval t_beg, t_end;
    long int timedata[7];
    std::vector<size_t> countThreads = {0, 1, 2, 4, 8, 16, 32};

    for (size_t i = 0; i < countThreads.size(); ++i) {
        std::cout << "threads = " << countThreads[i] << ":\n";
        gettimeofday(&t_beg, NULL);
        rayTracing->render(countThreads[i]);     
        gettimeofday(&t_end, NULL);
        timedata[i] = calc_elapsed_time(&t_beg, &t_end); 
        std::cout << timedata[i] << "\n";
    }
    std::ofstream f(filename, std::ios::app);
    if (f.is_open()) {
        for (size_t i = 0; i< countThreads.size(); ++i) {
            f << timedata[i] << "\t";
        }
    } else {
        std::cout << "Error: " << strerror(errno) << "\n";
    }
    
    
    f << "\n";
    f.close(); 
     
}
