PERSONAGEM.CPP ATUALIZADO
#include "Personagem.hpp"
#include "Utils.hpp" // Incluído para usar battlePrint
#include <iostream>
#include <algorithm>

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
