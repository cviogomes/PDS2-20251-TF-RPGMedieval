#ifndef CAVALEIRO_DA_FOME_HPP
#define CAVALEIRO_DA_FOM_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class CavaleiroDaFome : public Inimigo{
    public:
    CavaleiroDaFome() : Inimigo("Cavaleiro da Fome", 400, 20, 8){}

    int getVidaMax() const {
    return vidaMax_;
    }

    void setVidaMax(int novaVidaMax) {
    vidaMax_ = novaVidaMax;
    }
    
    void aoAtacar(Jogador& jogador) override {
        jogador.setVidaMax(std::max(10, jogador.getVidaMax() - 5));
        if (jogador.getVida() > jogador.getVidaMax())
            jogador.setVida(jogador.getVidaMax());
        std::cout << nome_ << " te enfraquece! Vida máxima agora em " << jogador.getVidaMax() << "\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<CavaleiroDaFome>(*this);
    }

};

#endif