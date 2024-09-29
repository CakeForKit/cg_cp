#include "RayTracing.h"

RayTracing::RayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer,  size_t _maxDepth)
: scene(_scene), camera(_camera), drawer(_drawer), maxDepth(_maxDepth) {}

