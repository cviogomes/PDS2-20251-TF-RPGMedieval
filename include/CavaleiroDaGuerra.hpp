#ifndef CAVALEIRO_DA_GUERRA_HPP
#define CAVALEIRO_DA_GUERRA_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class CavaleiroDaGuerra : public Inimigo
{
public:
    CavaleiroDaGuerra() : Inimigo("Thargon, Cavaleiro da Guerra", 300, 25, 10) {}

    void aoAtacar(Jogador &jogador) override
    {
        jogador.reduzirAtaque(1);
        battlePrint(nome_ + " esmaga seu espirito de luta! Seu ataque foi reduzido para " + std::to_string(jogador.getAtaque()) + "!\n");
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<CavaleiroDaGuerra>(*this);
    }
};
#endif