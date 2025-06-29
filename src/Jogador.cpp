#include <iostream>
#include <algorithm>

#include "Jogador.hpp"
#include "Utils.hpp"

Jogador::Jogador(const std::string &nome, int vidaMax, int ataque, int defesa)
    : Personagem(nome, vidaMax, ataque, defesa),
      ouro_(100),
      pocoes_(3),
      investimento_(0.0),
      moral_(10),
      aliadoNyx_(false)
{}

void Jogador::ganharOuro(int quantidade)
{
    ouro_ += quantidade;
    battlePrint("Voce ganhou " + std::to_string(quantidade) + " de ouro! (Total: " + std::to_string(ouro_) + ")\n");
}

void Jogador::investirOuro(int quantidade)
{
    if (quantidade > 0 && quantidade <= ouro_)
    {
        ouro_ -= quantidade;
        investimento_ += quantidade;
        typeText("Voce investiu " + std::to_string(quantidade) + " de ouro!\n", TextSpeed::NORMAL);
    } else {
        typeText("Quantidade invalida ou ouro insuficiente!\n", TextSpeed::NORMAL);

    }
}

void Jogador::retornarInvestimento()
{
    if (investimento_ > 0)
    {
        int retorno = static_cast<int>(investimento_ * 1.5);
        ouro_ += retorno;
        typeText("Seu investimento rendeu " + std::to_string(retorno) + " de ouro! (Total: " + std::to_string(ouro_) + ")\n", TextSpeed::NORMAL);
        investimento_ = 0;
    }
}

void Jogador::usarPocao() {
    if (pocoes_ > 0) {
        pocoes_--;
        restaurarVida();
    } else {
        battlePrint("Voce nao tem pocoes!\n");
    }
}

int Jogador::getPocoes() const {
    return pocoes_;
}

void Jogador::adicionarMoral(int valor) {
    moral_ += valor;
    if (valor > 0) {
        battlePrint("[Sua moral aumentou!]\n");
    } else {
        battlePrint("[Sua moral diminuiu!]\n");
    }
}

int Jogador::getMoral() const {
    return moral_;
}

void Jogador::setAliadoNyx(bool valor) {
    aliadoNyx_ = valor;
}

bool Jogador::temAliadoNyx() const {
    return aliadoNyx_;
}

void Jogador::visitarLoja(int capitulo) {
    typeText("\n--- Loja do Mercador Errante ---\n", TextSpeed::NORMAL);
    retornarInvestimento();

    int escolha = 0;
    do {
        typeText("\nOuro atual: " + std::to_string(ouro_) + "\n", TextSpeed::NORMAL);
        typeText("---------------------------------\n", TextSpeed::NORMAL);

        if (capitulo == 1) {
            typeText("1 - Melhorar Ataque (+5)  (50 Ouro)\n", TextSpeed::NORMAL);
            typeText("2 - Melhorar Defesa (+5)  (50 Ouro)\n", TextSpeed::NORMAL);
            typeText("3 - Comprar Pocao de Cura (20 Ouro)\n", TextSpeed::NORMAL);
            typeText("4 - Investir Ouro (Retorno de 50%)\n", TextSpeed::NORMAL);
        } else if (capitulo == 2) {
            typeText("1 - Melhorar Ataque (+5)      (50 Ouro)\n", TextSpeed::NORMAL);
            typeText("2 - Melhorar Vida Maxima (+10) (60 Ouro)\n", TextSpeed::NORMAL);
            typeText("3 - Comprar Pocao de Cura      (40 Ouro)\n", TextSpeed::NORMAL);
            typeText("4 - Investir Ouro (Retorno de 50%)\n", TextSpeed::NORMAL);
        } else if (capitulo == 3) {
            typeText("1 - Melhorar Defesa (+5)       (60 Ouro)\n", TextSpeed::NORMAL);
            typeText("2 - Melhorar Vida Maxima (+15)  (80 Ouro)\n", TextSpeed::NORMAL);
            typeText("3 - Comprar Pocao de Cura       (60 Ouro)\n", TextSpeed::NORMAL);
            typeText("4 - Investir Ouro (Retorno de 50%)\n", TextSpeed::NORMAL);
        }
        typeText("5 - Sair da loja\n", TextSpeed::NORMAL);

        std::cout << "Opcao: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                if(capitulo == 1 || capitulo == 2) {
                    if (ouro_ >= 50) { ataque_ += 5; ouro_ -= 50; typeText("Ataque aumentado!\n", TextSpeed::NORMAL); }
                    else { typeText("Ouro insuficiente!\n", TextSpeed::NORMAL); }
                } else if (capitulo == 3) {
                     if (ouro_ >= 60) { defesa_ += 5; ouro_ -= 60; typeText("Defesa aumentada!\n", TextSpeed::NORMAL); }
                     else { typeText("Ouro insuficiente!\n", TextSpeed::NORMAL); }
                }
                break;
            case 2:
                if (capitulo == 1) {
                     if (ouro_ >= 50) { defesa_ += 5; ouro_ -= 50; typeText("Defesa aumentada!\n", TextSpeed::NORMAL); }
                     else { typeText("Ouro insuficiente!\n", TextSpeed::NORMAL); }
                } else if (capitulo == 2 || capitulo == 3) {
                    int custo = (capitulo == 2) ? 60 : 80;
                    int bonus = (capitulo == 2) ? 10 : 15;
                    if (ouro_ >= custo) { vidaMax_ += bonus; vida_ = vidaMax_; ouro_ -= custo; typeText("Vida maxima aumentada!\n", TextSpeed::NORMAL); }
                    else { typeText("Ouro insuficiente!\n", TextSpeed::NORMAL); }
                }
                break;
            case 3: {
                int custo = (capitulo == 1) ? 20 : (capitulo == 2 ? 40 : 60);
                if (ouro_ >= custo) { pocoes_++; ouro_ -= custo; typeText("Voce comprou uma pocao!\n", TextSpeed::NORMAL); }
                else { typeText("Ouro insuficiente!\n", TextSpeed::NORMAL); }
                break;
            }
            case 4: {
                int valor;
                typeText("Quanto deseja investir? ", TextSpeed::NORMAL);
                std::cin >> valor;
                investirOuro(valor);
                break;
            }
            case 5:
                typeText("Voce saiu da loja.\n", TextSpeed::NORMAL);
                break;
            default:
                typeText("Opcao invalida.\n", TextSpeed::NORMAL);
                break;
        }
    } while (escolha != 5);
}

void Jogador::aplicarEfeito(const Efeito &efeito)
{
    efeito_ = efeito;
    battlePrint(nome_ + " foi afetado por um efeito por " + std::to_string(efeito.duracao) + " turnos.\n");
}


void Jogador::processarEfeitos() {
    if (efeito_.duracao > 0) {
        switch (efeito_.tipo) {
            case TipoEfeito::Veneno:
                vida_ -= 5;
                battlePrint(nome_ + " sofre 5 de dano de veneno! Vida atual: " + std::to_string(vida_) + "/" + std::to_string(vidaMax_) + "\n");
                break;
            case TipoEfeito::Paralisia:
                battlePrint(nome_ + " esta paralisado e perde o turno!\n");
                break;
            case TipoEfeito::Maldicao:
                ataque_ = std::max(1, ataque_ - 1);
                battlePrint(nome_ + " esta amaldicoado! Ataque reduzido para " + std::to_string(ataque_) + "\n");
                break;
            default:
                break;

        }
        efeito_.duracao--;
    }
}

Efeito Jogador::getEfeito() const
{
    return efeito_;
}

void Jogador::setVidaMax(int novaVidaMax) {

    vidaMax_ = novaVidaMax;
    if (vida_ > vidaMax_)
    {
        vida_ = vidaMax_;
    }
}

void Jogador::reduzirAtaque(int valor) {
    ataque_ -= valor;
    if (ataque_ < 0) ataque_ = 0;
}

void Jogador::setDefesa(int defesa) {
    defesa_ = defesa;

}
