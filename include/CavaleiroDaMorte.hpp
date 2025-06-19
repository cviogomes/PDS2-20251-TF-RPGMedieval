#ifndef CAVALEIRO_DA_MORTE_HPP
#define CAVALEIRO_DA_MORTE_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <cstdlib>

class CavaleiroDaMorte : public Inimigo {
    CavaleiroDaMorte() : Inimigo("Cavaleiro da Morte", 500, 30, 12){}

    void aoReceberDano(int danoRecebido) override {
        int chance = rand() % 100;
        if (chance < 30) {
            std::cout << nome_ << " reflete o dano!\n";
            refletirProJogador_ = danoRecebido;
        }
    }
    
    int getRefletido() {
        int dano = refletirProJogador_;
        refletirProJogador_ = 0;
        return dano;
    }

    private:
    int refletirProJogador_ = 0;
};

#endif