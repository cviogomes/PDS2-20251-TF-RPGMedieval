#ifndef ARANHA_HPP
#define ARANHA_HPP

#include "Inimigo.hpp"
#include <iostream>

class Aranha : public Inimigo {
    public:
    Aranha() : Inimigo("Aranha", 45, 12, 2), paralisado_(false) {}

    void aoAtacar(Jogador& jogador) override {
        std::cout << nome_ << " cospe teia! Você ficará por 1 turno!\n";
        paralisado_ = true;
    }

    bool estaParalisado() const { return paralisado_; }
    void limparParalisia() { paralisado_ = false; }

    private:
    bool paralisado_;
};

#endif