#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"
#include "Jogador.hpp"

class Inimigo : public Personagem {
    public:
        Inimigo(const std::string& nome, int vida, int ataque, int defesa)
        : Personagem(nome, vida, ataque, defesa) {}
          virtual ~Inimigo() = default;

          virtual void aoReceberDano(int danoRecebido) {}

          virtual void aoAtacar(Jogador& jogador) {}

};

#endif // INIMIGO_HPP
