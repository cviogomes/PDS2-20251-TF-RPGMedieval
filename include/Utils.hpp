#ifndef UTILS_HPP
#define UTILS_HPP

#pragma once

#include <string>    
#include <sstream>   

enum class TextSpeed {
    NORMAL,     // instantânea
    NARRATIVE,  // lenta para imersão
    BATTLE      // acelerada
};

void setupTerminal();
void typeText(const std::string& text, TextSpeed speed = TextSpeed::NORMAL);
void narrativePrint(const std::string& narrator, const std::string& text);
void battlePrint(const std::string& text);

void logError(const std::string& msg);

#endif
