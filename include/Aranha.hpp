#ifndef ARANHA_HPP
#define ARANHA_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Efeitos.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Aranha : public Inimigo {
public:
    Aranha() : Inimigo("Aranha", 45, 12, 2) {}

    void aoAtacar(Jogador& jogador) override {
        battlePrint(nome_ + " cospe teia! Você ficará paralisado por 1 turno!\n");
        jogador.aplicarEfeito({TipoEfeito::Paralisia, 1});
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Aranha>(*this);
    }
};
#endif