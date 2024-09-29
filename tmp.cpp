#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

void print(glm::mat4 &m) {
    std::cout << "Mat4:\n";
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print(glm::vec4 &m) {
    std::cout << "Vec4(";
    for (size_t j = 0; j < 4; ++j) {
        std::cout << m[j] << " ";
    }
    std::cout << ")\n";
    
}

int main(void) {
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 0.0f);
    print(vec);
    glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 0.0f));
    glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 2.0f, 2.0f));
    
    print(trans);
    print(rotate);
    print(scale);
    glm::mat4 mmm = trans * rotate * scale;
    print(mmm);

    vec = trans * vec;
    print(vec);

    // print_mat4(matrix1);

    return 0;
}