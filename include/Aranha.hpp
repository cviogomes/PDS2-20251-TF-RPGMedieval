#ifndef ARANHA_HPP
#define ARANHA_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Efeitos.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Aranha : public Inimigo
{
public:
    Aranha() : Inimigo("Aranha", 45, 12, 2) {}

    void aoAtacar(Jogador &jogador) override
    {
        if (jogador.getEfeito().tipo != TipoEfeito::Paralisia)
        {
            battlePrint(nome_ + " cospe teia! Voce ficara paralisado por 1 turno!\n");
            jogador.aplicarEfeito({TipoEfeito::Paralisia, 1});
        }
        else
        {
            battlePrint(nome_ + " tenta paralisar, mas voce ja esta imobilizado!\n");
        }
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<Aranha>(*this);
    }
};
#endif