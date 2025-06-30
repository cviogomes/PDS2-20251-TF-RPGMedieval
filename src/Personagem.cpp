#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Personagem.hpp"
#include "Utils.hpp"


Personagem::Personagem(const std::string& nome, int vidaMax, int ataque, int defesa)
    : nome_(nome),
      vida_(vidaMax),
      vidaMax_(vidaMax),
      ataque_(ataque),
      defesa_(defesa)
{}

void Personagem::atacar(Personagem& alvo) {
    int dano = std::max(1, ataque_ - alvo.getDefesa());
    alvo.setVida(alvo.getVida() - dano);

    std::string mensagem = nome_ + " ataca " + alvo.getNome() + " causando " + std::to_string(dano) + " de dano! (" + std::to_string(alvo.getVida()) + "/" + std::to_string(alvo.getVidaMax()) + ")\n";
    battlePrint(mensagem);
}

void Personagem::defender() {
    battlePrint(nome_ + " assume postura defensiva.\n");
}

void Personagem::restaurarVida() {
    vida_ = vidaMax_;
    battlePrint(nome_ + " restaurou a vida para " + std::to_string(vida_) + "/" + std::to_string(vidaMax_) + "!\n");
}

bool Personagem::estaVivo() const {
    return vida_ > 0;
}

const std::string& Personagem::getNome() const {
    return nome_;
}

int Personagem::getVida() const {
    return vida_;
}

int Personagem::getVidaMax() const {
    return vidaMax_;
}

int Personagem::getAtaque() const {
    return ataque_;
}

int Personagem::getDefesa() const {
    return defesa_;
}

void Personagem::setVida(int novaVida) {

    vida_ = std::max(0, novaVida);
}

