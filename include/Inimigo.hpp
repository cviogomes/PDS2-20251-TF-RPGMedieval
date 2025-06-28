INIMIGO.HPP ATUALIZADO
#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"

class Jogador;

class Inimigo : public Personagem {
public:
    Inimigo(const std::string& nome, int vida, int ataque, int defesa)
        : Personagem(nome, vida, ataque, defesa) {}
    virtual ~Inimigo() = default;
