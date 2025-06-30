#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"
#include <vector>
#include <memory>

class Jogador;

class Inimigo : public Personagem
{
public:
    Inimigo(const std::string &nome, int vida, int ataque, int defesa)
        : Personagem(nome, vida, ataque, defesa) {}
    virtual ~Inimigo() = default;

    virtual void aoReceberDano(int danoRecebido) {}
    virtual void aoAtacar(Jogador &jogador) {}

    virtual std::unique_ptr<Inimigo> clone() const = 0;

    // função chamada quando o inimigo morre. retorna uma lista vazia por padrão
    virtual std::vector<std::unique_ptr<Inimigo>> onDeathSpawn()
    {
        return {}; // retorna um vetor vazio
    }
    virtual bool habilidadeSubstituiAtaque() const
    {
        return false;
    }
};

#endif // INIMIGO_HPP
