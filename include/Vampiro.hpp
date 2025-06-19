#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Inimigo.hpp"
#include <iostream>

class Vampiro : public Inimigo {
    public:
    Vampiro() : Inimigo("Vampiro", 80, 22, 4) {}

    void aoAtacar(Jogador& jogador) override {
        int dano = std::max(1, ataque_ - jogador.defesa_);
        jogador.vida_ -= dano;
        vida_ = std::min(vidaMax_, vida_ + dano / 2);
        std::cout << nome_ << " suga " << dano << " de vida e recupera " << dano / 2 << "!\n";
    }
};

#endif
