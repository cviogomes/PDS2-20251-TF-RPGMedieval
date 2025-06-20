#ifndef CAVALEIRO_DA_GUERRA_HPP
#define CAVALEIRO_DA_GUERRA_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class CavaleiroDaGuerra : public Inimigo {
    public:
    CavaleiroDaGuerra() : Inimigo("Cavaleiro da Guerra", 300, 25, 10) {}

    void aoAtacar(Jogador& jogador) override {
        jogador.ataque_ = std::max(1, jogador.ataque_ - 1);
        std::cout << nome_ << " enfraquece seu ataque! Agora em " << jogador.ataque_ << "\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<CavaleiroDaGuerra>(*this);
    }


};

#endif