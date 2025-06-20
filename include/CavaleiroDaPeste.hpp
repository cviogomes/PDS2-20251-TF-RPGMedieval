#ifndef CAVALEIRO_DA_PESTE_HPP
#define CAVALEIRO_DA_PESTE_HPP

#include "Inimigo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

class CavaleiroDaPeste : public Inimigo {
    public:
    CavaleiroDaPeste() : Inimigo("Cavaleiro da Peste", 200, 30, 10) {}
    
    void aoAtacar(Jogador& jogador) override {
        int reducao = 1;
        jogador.defesa_ = std::max(0, jogador.defesa_ - reducao);
        std::cout << nome_ << " contamina você com a peste! Defesa agora em " << jogador.defesa_ << "\n";
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<CavaleiroDaPeste>(*this);
    }

};

#endif