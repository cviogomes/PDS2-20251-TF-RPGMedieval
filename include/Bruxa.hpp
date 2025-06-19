#ifndef BRUXA_HPP
#define BRUXA_HPP

#include "Inimigo.hpp"
#include <iostream>

class Bruxa : public Inimigo{
    public:
    Bruxa() : Inimigo("Bruxa", 60, 18, 5), turnosMaldito_(3) {}

    void aoAtacar(Jogador& jogador) override {
        std::cout << nome_ << " lança uma maldição! Sua defesa será reduzida temporariamente.\n";
        jogador.defesa_ = std::max(0, jogador.defesa_ - 5);
        jogadorEstados_ = &jogador;
        turnoAtual_ = 0;
        maldito_ = true;
    }

    void aoReceberDano(int) override {
        if (maldito_ && ++turnoAtual_ >= turnosMaldito_){
            jogadorEstados_->defesa_ += 5;
            std::cout << "A maldição se esvai. Defesa restaurada.\n";
            maldito_ = false;
        }
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<Bruxa>(*this);
    }


    private:
    Jogador* jogadorEstados_ = nullptr;
    bool maldito_ = false;
    int turnosMaldito_;
    int turnoAtual_ = 0;
};

#endif