#include "personagem.hpp"
#include <iostream>
#include <algorithm>

Personagem::Personagem(const std::string& nome, int vidaMax, int ataque, int defesa)
    : nome_(nome),
      vida_(vidaMax),
      vidaMax_(vidaMax),
      ataque_(ataque),
      defesa_(defesa)
{

}

void Personagem::atacar(Personagem& alvo){
    //interessante comentar essa linha abaixo durante a apresentacao hein
    int dano = std::max(1, ataque_ - alvo.defesa_);
    alvo.vida_ -= dano;
    std::cout << nome_ << " ataca " << alvo.nome_ << " causando " << dano << " de dano! ( " << alvo.vida_ << "/" << alvo.vidaMax_ << " )\n";
}

void Personagem::defender(){
    //so avisa que ta defendendo
    std::cout << nome_ << " assume postura defensiva" << std::endl;
}

void Personagem::restaurarVida(){
    vida_ = vidaMax_;
    std::cout << nome_ << " restaurou a vida para " << vida_ << "/" << vidaMax_ << std::endl;
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


