#ifndef BRUXA_HPP
#define BRUXA_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Efeitos.hpp"
#include <iostream>
#include <memory>

class Bruxa : public Inimigo
{
public:
    Bruxa() : Inimigo("Bruxa", 60, 18, 5) {}

    void aoAtacar(Jogador &jogador) override
    {
        Efeito maldicao{TipoEfeito::Maldicao, 3}; // 3 turnos de maldição
        jogador.aplicarEfeito(maldicao);
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<Bruxa>(*this);
    }
};

#endif // BRUXA_HPP
