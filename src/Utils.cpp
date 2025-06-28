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

void typeText(const std::string& text, TextSpeed speed) {
    int delay_ms = 0;

    switch (speed) {
        case TextSpeed::NARRATIVE:
            delay_ms = 40;
            break;
        case TextSpeed::BATTLE:
            delay_ms = 10;
            break;
        case TextSpeed::NORMAL:
        default:
            delay_ms = 0;
            break;
    }

    if (delay_ms == 0) {
        std::cout << text;
    } else {
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    }
}

void narrativePrint(const std::string& narrator, const std::string& text) {
    std::cout << "\n";
    typeText(narrator + ": ", TextSpeed::BATTLE); // Narrador fala rápido
    typeText(text + "\n", TextSpeed::NARRATIVE);
}
