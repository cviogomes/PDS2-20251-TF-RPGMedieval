#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Goblin : public Inimigo {
public:
    Goblin() : Inimigo("Goblin", 60, 16, 3) {}

    void aoAtacar(Jogador& jogador) override {
        int roubo = 20;
        jogador.ganharOuro(-roubo);
        battlePrint(nome_ + " te acerta e rouba " + std::to_string(roubo) + " de ouro!\n");
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Goblin>(*this);
    }
};
#endif