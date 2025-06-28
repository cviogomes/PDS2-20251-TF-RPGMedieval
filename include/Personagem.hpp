PERSONAGEM.HPP ATUALIZADO
#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <vector>
#include <memory>

class Personagem {
public:
    Personagem(const std::string& nome, int vidaMax, int ataque, int defesa);
    virtual ~Personagem() = default;

    virtual void atacar(Personagem& alvo);
    void defender();
    void restaurarVida();

    bool estaVivo() const;
