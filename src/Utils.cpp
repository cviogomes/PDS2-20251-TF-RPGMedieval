#include "Utils.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <clocale>
#include <codecvt>
#include <locale>
#include <conio.h>


// Inclui bibliotecas específicas do Windows para configurar o terminal
#ifdef _WIN32
#include <windows.h>
#endif

void setupTerminal() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::setlocale(LC_ALL, "");
    try {
    std::wcout.imbue(std::locale(""));
    } catch (...) {
    std::wcout.imbue(std::locale("C"));
    }// usa locale do sistema no wcout
}

// Função auxiliar para converter string UTF-8 para wstring
std::wstring utf8ToWstring(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

void typeText(const std::string& text, TextSpeed speed) {
    int delay_ms = 0;

    switch (speed) {
        case TextSpeed::NARRATIVE: delay_ms = 40; break;
        case TextSpeed::BATTLE: delay_ms = 10; break;
        case TextSpeed::NORMAL:
        default: delay_ms = 0; break;
    }

    std::wstring wtext = utf8ToWstring(text);

    if (delay_ms == 0) {
        std::wcout << wtext;
    } else {
        bool skip = false;
        for (wchar_t c : wtext) {
#ifdef _WIN32
            if (!skip && _kbhit()) {
                int ch = _getch();
                if (ch == 13) { // ENTER pressionado
                    skip = true;
                }
            }
#endif
            std::wcout << c << std::flush;
            if (!skip)
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    }
}

void narrativePrint(const std::string& narrator, const std::string& text) {
    std::wcout << L"\n";
    typeText(narrator + ": ", TextSpeed::BATTLE);
    typeText(text + "\n", TextSpeed::NARRATIVE);
}

void battlePrint(const std::string& text) {
    typeText(text, TextSpeed::BATTLE);
}
