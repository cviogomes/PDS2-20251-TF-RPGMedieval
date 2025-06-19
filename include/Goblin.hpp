#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Inimigo.hpp"
#include <iostream>

class Goblin : public Inimigo {
    public:
    Goblin() : Inimigo("Goblin", 60, 16, 3) {}

    void aoAtacar(Jogador& jogador) override {
        int roubo = 20;
        jogador.investirOuro(-roubo);
        std::cout << nome_ << " te acerta e rouba " << roubo << " de ouro!\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<Goblin>(*this);
    }


};

#endif