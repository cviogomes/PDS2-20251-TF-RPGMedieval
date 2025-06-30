#include "Musica.hpp"
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <filesystem>
#include <stdexcept>

void Musica::PlayMusic(const std::string &filename)
{
    if (!std::filesystem::exists(filename)) {
        throw std::runtime_error("Arquivo de musica nao encontrado: " + filename);
    }
    PlaySoundA(filename.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Musica::StopMusic()
{
    PlaySoundA(NULL, 0, 0);
}