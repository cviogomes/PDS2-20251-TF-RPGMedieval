#ifndef CAVALEIRO_DA_PESTE_HPP
#define CAVALEIRO_DA_PESTE_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

class CavaleiroDaPeste : public Inimigo {
public:
    CavaleiroDaPeste() : Inimigo("Vorstag, Cavaleiro da Peste", 150, 22, 10) {}

    void aoAtacar(Jogador& jogador) override {
        int reducao = 1;
        jogador.setDefesa(std::max(0, jogador.getDefesa() - reducao));
        battlePrint(nome_ + " contamina voce com a peste! Sua defesa foi reduzida para " + std::to_string(jogador.getDefesa()) + "!\n");
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<CavaleiroDaPeste>(*this);
    }
};
#endif
