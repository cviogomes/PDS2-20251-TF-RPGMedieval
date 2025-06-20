#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"
#include "Jogador.hpp"
#include <memory>
#include <vector>

class Inimigo : public Personagem {
    public:
        
        Inimigo(const std::string& nome, int vida, int ataque, int defesa)
        : Personagem(nome, vida, ataque, defesa) {}
          virtual ~Inimigo() = default;

          virtual void aoReceberDano(int danoRecebido) {}

          virtual void aoAtacar(Jogador& jogador) {}
          
          virtual std::unique_ptr<Inimigo> clone() const = 0;

};

#endif // INIMIGO_HPP
