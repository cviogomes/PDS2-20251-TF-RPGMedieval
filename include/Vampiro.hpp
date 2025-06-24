#ifndef VAMPIRO_HPP
#define VAMPIRO_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Efeitos.hpp"
#include <iostream>
#include <memory>

class Vampiro : public Inimigo {
public:
    Vampiro() : Inimigo("Vampiro", 80, 22, 4) {}

    void aoAtacar(Jogador& jogador) override {
        int dano = std::max(1, ataque_ - jogador.getDefesa());
        jogador.setVida(jogador.getVida() - dano);
        vida_ = std::min(vidaMax_, vida_ + dano / 2);
        std::cout << nome_ << " suga " << dano << " de vida e recupera " << dano / 2 << "!\n";

        // Aplica paralisia por 1 turno
        Efeito paralisia{TipoEfeito::Paralisia, 1};
        jogador.aplicarEfeito(paralisia);
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Vampiro>(*this);
    }
};

#endif // VAMPIRO_HPP
