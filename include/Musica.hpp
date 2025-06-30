#define MUSICA_HPP
#ifdef MUSICA_HPP

#include <string>

class Musica
{
public:
    // Toca o arquivo de música em loop (assíncrono)
    void PlayMusic(const std::string &filename);

    // Para a música
    static void StopMusic();
};

#endif // MUSICA_HPP