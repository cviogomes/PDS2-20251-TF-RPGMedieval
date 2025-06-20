#ifndef CAVALEIRO_DA_FOME_HPP
#define CAVALEIRO_DA_FOM_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class CavaleiroDaFome : public Inimigo{
    public:
    CavaleiroDaFome() : Inimigo("Cavaleiro da Fome", 400, 20, 8){}

    void aoAtacar(Jogador& jogador) override {
        jogador.vidaMax_ = std::max(10, jogador.vidaMax_ - 5);
        if (jogador.vida_ > jogador.vidaMax_)
        jogador.vida_ = jogador.vidaMax_;
        std::cout << nome_ << " te enfraquece! Vida máxima agora em " << jogador.vidaMax_ << "\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<CavaleiroDaFome>(*this);
    }

};

#endif