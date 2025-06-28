#include "Musica.hpp"
#include <windows.h>
#include <mmsystem.h>
#include <string>

void Musica::PlayMusic(const std::string& filename) {
    PlaySoundA(filename.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Musica::StopMusic() {
    PlaySoundA(NULL, 0, 0);
}