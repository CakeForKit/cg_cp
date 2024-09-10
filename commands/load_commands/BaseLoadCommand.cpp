#include "BaseLoadCommand.h"

BaseLoadCommand::BaseLoadCommand(std::shared_ptr<Material> _material)
: material(_material) {}

BaseLoadCommand::~BaseLoadCommand() = default;

idReaderCreator BaseLoadCommand::getReaderId() { return id_reader; }

idDirectorCreator BaseLoadCommand::getDirectorId() { return id_director; }
