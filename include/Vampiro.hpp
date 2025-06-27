#ifndef VAMPIRO_HPP
#define VAMPIRO_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Vampiro : public Inimigo {
public:
    Vampiro() : Inimigo("Vampiro", 80, 22, 4) {}

    void aoAtacar(Jogador& jogador) override {
        int dano = std::max(1, ataque_ - jogador.getDefesa());
        // Não atacamos aqui, a função atacar principal fará isso.
        // Apenas preparamos o efeito.
        vida_ = std::min(vidaMax_, vida_ + dano / 2);
        battlePrint(nome_ + " suga sua força vital e recupera " + std::to_string(dano / 2) + " de vida!\n");
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Vampiro>(*this);
    }
};
#endif