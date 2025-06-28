#ifndef CAVALEIRO_DA_MORTE_HPP
#define CAVALEIRO_DA_MORTE_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>

class CavaleiroDaMorte : public Inimigo {
public:
    CavaleiroDaMorte() : Inimigo("Moros, Cavaleiro da Morte", 500, 30, 12) {}

    void aoAtacar(Jogador& jogador) override {
        battlePrint("O ar gela ao redor de " + nome_ + "...\n");
    }
    
    void aoReceberDano(int danoRecebido) override {
        int chance = rand() % 100;
        if (chance < 20) { // 20% de chance de refletir
            battlePrint(nome_ + " reflete o dano de volta para você!\n");
            // A lógica de reflexão teria que ser mais complexa,
            // envolvendo o jogador diretamente, então por enquanto é um efeito narrativo.
        }
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<CavaleiroDaMorte>(*this);
    }
};
#endif