#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

enum class TextSpeed{
    NORMAL, //normal, instanteanea
    NARRATIVE, //lenta para imersao
    BATTLE //acelerada 
};

void setupTerminal();

void typeText(const std::string& text, TextSpeed speed = TextSpeed::NORMAL);

void narrativePrint(const std::string& narrator, const std::string& text);

void battlePrint(const std::string& text);

#endif