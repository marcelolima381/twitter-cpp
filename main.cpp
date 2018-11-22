#include <iostream>
#include "Interface/Login.hpp"

int main() {
    auto *login = new Interface::Login();
    login->exibir();
    return 0;
}