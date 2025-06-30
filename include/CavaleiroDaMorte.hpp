#ifndef CAVALEIRO_DA_MORTE_HPP
#define CAVALEIRO_DA_MORTE_HPP

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>

class CavaleiroDaMorte : public Inimigo
{
public:
    CavaleiroDaMorte() : Inimigo("Moros, Cavaleiro da Morte", 500, 30, 12), danoParaRefletir_(0) {}

    // Guarda o dano recebido.
    void aoReceberDano(int danoRecebido) override
    {
        if ((rand() % 100) < 30)
        {
            battlePrint(nome_ + " prepara-se para refletir o dano!\n");
            danoParaRefletir_ = danoRecebido;
        }
    }

    // aoAtacar agora SÓ cuida da reflexão.
    void aoAtacar(Jogador &jogador) override
    {
        if (danoParaRefletir_ > 0)
        {
            battlePrint(nome_ + " reflete " + std::to_string(danoParaRefletir_) + " de dano em voce!\n");
            jogador.setVida(jogador.getVida() - danoParaRefletir_);
        }
    }

    // Informa ao loop de combate que a reflexão substitui o ataque normal.
    bool habilidadeSubstituiAtaque() const override
    {
        bool refletiu = (danoParaRefletir_ > 0);
        if (refletiu)
        {
            danoParaRefletir_ = 0; // Reseta o dano aqui, após a verificação.
        }
        return refletiu;
    }

    std::unique_ptr<Inimigo> clone() const override
    {
        return std::make_unique<CavaleiroDaMorte>(*this);
    }

    void setDanoParaRefletir(int dano)
    {
        //setter de danoParaRefletir_ para testes ou outras lógicas.
        danoParaRefletir_ = dano;
    }

private:
    // Esta variável precisa ser 'mutable' para que possamos alterá-la em um método 'const'.
    mutable int danoParaRefletir_;
};
#endif