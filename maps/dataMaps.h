#pragma once

#include <iostream>
#include <map>
#include <QComboBox>

enum class typeChess {
    PAWN,
    ROOK
};

std::map<typeChess, std::string> chessMap {
    {typeChess::PAWN, "/home/kathrine/cg_cp/data/pawn.txt"},
    {typeChess::ROOK, "/home/kathrine/cg_cp/data/rook.txt"}
};

void fillModelsComboBox(QComboBox *cb);
