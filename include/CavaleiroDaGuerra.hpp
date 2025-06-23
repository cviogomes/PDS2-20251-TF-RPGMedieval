#ifndef CAVALEIRO_DA_GUERRA_HPP
#define CAVALEIRO_DA_GUERRA_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class CavaleiroDaGuerra : public Inimigo {
    public:
    CavaleiroDaGuerra() : Inimigo("Cavaleiro da Guerra", 300, 25, 10) {}

    int getAtaque() const {
        return ataque_;
    }

    void aoAtacar(Jogador& jogador) override {
        jogador.reduzirAtaque(1);
        std::cout << nome_ << " enfraquece seu ataque! Agora em " << jogador.getAtaque() << "\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<CavaleiroDaGuerra>(*this);
    }


};

#endif