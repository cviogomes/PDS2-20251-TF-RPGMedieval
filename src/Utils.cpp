UTILS.CPP
#include "Utils.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <clocale>

// Inclui bibliotecas específicas do Windows para configurar o terminal
#ifdef _WIN32
#include <windows.h>
#endif

void setupTerminal() {
    // Código para Windows
#ifdef _WIN32

    // Define a página de código do console para UTF-8 para suportar acentos
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // Define o locale para suportar caracteres do sistema operacional
    setlocale(LC_ALL, "");
}
