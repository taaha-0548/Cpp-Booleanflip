// Demo
#include <iostream>
#include "../include/boolflip.hpp"

int main() {
    flip_bool flag = true;
    std::cout << flag << "\n"; // 1
    ~flag;
    std::cout << flag << "\n"; // 0
    ~flag;
    std::cout << flag << "\n"; // 1
}
