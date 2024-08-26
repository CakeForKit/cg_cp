#include "VolumeModel.h"

VolumeModel::VolumeModel(std::shared_ptr<VolumeModelImpl> _impl) 
: impl(_impl) {}
