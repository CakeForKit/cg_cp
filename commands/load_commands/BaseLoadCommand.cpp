#include "BaseLoadCommand.h"


BaseLoadCommand::~BaseLoadCommand() = default;

idReaderCreator BaseLoadCommand::getReaderId() { return id_reader; }

idDirectorCreator BaseLoadCommand::getDirectorId() { return id_director; }
