#ifndef BRUXA_HPP
#define BRUXA_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Efeitos.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Bruxa : public Inimigo
{
public:
    Bruxa() : Inimigo("Bruxa", 60, 18, 5) {}

    void aoAtacar(Jogador &jogador) override
    {
        battlePrint(nome_ + " lança uma maldicao em voce!\n");
        jogador.aplicarEfeito({TipoEfeito::Maldicao, 3});
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<Bruxa>(*this);
    }
};
#endif