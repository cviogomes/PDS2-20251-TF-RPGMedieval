#ifndef ARANHA_HPP
#define ARANHA_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Aranha : public Inimigo {
    public:
    Aranha() : Inimigo("Aranha", 45, 12, 2), paralisado_(false) {}

    void aoAtacar(Jogador& jogador) override {
        std::cout << nome_ << " cospe teia! Você ficará por 1 turno!\n";
        paralisado_ = true;
    }

    bool estaParalisado() const { return paralisado_; }
    void limparParalisia() { paralisado_ = false; }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<Aranha>(*this);
    }

    private:
    bool paralisado_;
};

#endif