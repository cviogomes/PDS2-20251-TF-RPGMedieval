#ifndef CAVALEIRO_DA_FOME_HPP
#define CAVALEIRO_DA_FOME_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class CavaleiroDaFome : public Inimigo
{
public:
    CavaleiroDaFome() : Inimigo("Seraphina, Cavaleira da Fome", 400, 20, 8) {}

    void aoAtacar(Jogador &jogador) override
    {
        jogador.setVidaMax(std::max(10, jogador.getVidaMax() - 5));
        if (jogador.getVida() > jogador.getVidaMax())
            jogador.setVida(jogador.getVidaMax());
        battlePrint(nome_ + " te enfraquece com a fome! Sua vida maxima agora e' " + std::to_string(jogador.getVidaMax()) + "!\n");
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<CavaleiroDaFome>(*this);
    }
};
#endif