#include "Model.h"

std::ostream& operator<<(std::ostream &os, const Model &model) {
    return model.print(os);
}

void Model::setTypeChess(typeChess t) noexcept {
    type = t;
}

typeChess Model::getTypeChess() const noexcept {
    return type;
}

// bool Model::isComposite() const
// {
//     return false;
// }

// bool Model::add(std::initializer_list<PtrModel> comp) 
// { 
//     (void) comp;
//     return false; 
// }

// bool Model::remove(const iterator& it) 
// { 
//     (void) it;
//     return false; 
// }

// Model::iterator Model::begin() const 
// { 
//     return iterator(); 
// }

// Model::iterator Model::end() const 
// { 
//     return iterator(); 
// }