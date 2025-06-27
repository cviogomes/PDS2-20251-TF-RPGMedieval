#include "Jogador.hpp"
#include "Utils.hpp"
#include <iostream>
#include <algorithm>


Jogador::Jogador(const std::string& nome, int vidaMax, int ataque, int defesa)
    : Personagem(nome, vidaMax, ataque, defesa),
      ouro_(0),
      pocoes_(3),
      investimento_(0.0),
      moral_(10),
      aliadoNyx_(false)
{}

void Jogador::ganharOuro(int quantidade) {
    ouro_ += quantidade;
    battlePrint("Você ganhou " + std::to_string(quantidade) + " de ouro! (Total: " + std::to_string(ouro_) + ")\n");
}

void Jogador::investirOuro(int quantidade) {
    if (quantidade > 0 && quantidade <= ouro_) {
        ouro_ -= quantidade;
        investimento_ += quantidade;
        typeText("Você investiu " + std::to_string(quantidade) + " de ouro!\n", TextSpeed::NORMAL);
    } else {
        typeText("Quantidade inválida ou ouro insuficiente!\n", TextSpeed::NORMAL);
    }
}

void Jogador::retornarInvestimento() {
    if (investimento_ > 0) {
        int retorno = static_cast<int>(investimento_ * 1.5);
        ouro_ += retorno;
        typeText("Seu investimento rendeu " + std::to_string(retorno) + " de ouro! (Total: " + std::to_string(ouro_) + ")\n", TextSpeed::NORMAL);
        investimento_ = 0;
    }
}

int Jogador::getPocoes() const {
    return pocoes_;
}

void Jogador::usarPocao() {
    if (pocoes_ > 0) {
        pocoes_--;
        restaurarVida();
        std::cout << getNome() << " usou uma poção e recuperou vida! (" << getVida() << "/" << getVidaMax() << ")\n";

    } else {
        std::cout << "Você não tem poções!\n";
    }
}

void Jogador::visitarLoja() {

    std::cout << "\n--- Loja ---\n";
    retornarInvestimento();
    std::cout << "1 - Aumentar ataque (50 ouro)\n";
    std::cout << "2 - Aumentar defesa (50 ouro)\n";
    std::cout << "3 - Aumentar vida (50 ouro)\n";
    std::cout << "4 - Comprar poção de cura (8 ouro)\n";
    std::cout << "5 - Investir ouro\n";
    std::cout << "6 - Sair da loja\n";
    int escolha;

    do{    
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    switch (escolha) {
        case 1:
            if (ouro_ >= 50) {
                ataque_ += 5;
                ouro_ -= 50;
                std::cout << "Ataque aumentado em 5! Ouro restante: " << ouro_ << std::endl;
                } else {
                    std::cout << "Ouro insuficiente!" << std::endl;
            }
            break;

        case 2:
        if (ouro_ >= 50){
            defesa_ += 5;
            ouro_ -=50;
            std::cout << "Defesa aumentada em 5! Ouro restante: " << ouro_ << std::endl;
        } else {
            std::cout << "Ouro insuficiente!" << std::endl;
        }
        break;

        case 3:
            if (ouro_ >= 50) {
                vidaMax_ += 10;
                vida_ = vidaMax_;
                ouro_ -= 50;
                std::cout << "Vida máxima aumentada em 10! Ouro restante: " << ouro_ << std::endl;
            } else {
                std::cout << "Ouro insuficiente!" << std::endl;
            }
            break;

        case 4:
            if (ouro_ >= 8) {
                ouro_ -= 8;
                pocoes_++;
                std::cout << "Você comprou uma poção! Agora tem " << pocoes_ << " poções." << std::endl;
            } else {
                std::cout << "Ouro insuficiente para comprar poção." << std::endl;
            }
            break;

        case 5: {
                int valor;
                std::cout << "Quanto deseja investir? (Ouro atual: " << ouro_ << "): ";
                std::cin >> valor;
                investirOuro(valor);
                break;
            }

        case 6:
            std::cout << "Você saiu da loja." << std::endl;
            break;

        default:
            std::cout << "Saindo da loja...\n";
            break;
        }
    }while (escolha != 6);
}

void Jogador::aplicarEfeito(const Efeito& efeito) {
    efeito_ = efeito;
    std::cout << nome_ << " foi afetado por " << static_cast<int>(efeito.tipo) << " por " << efeito.duracao << " turnos.\n";
}

void Jogador::processarEfeitos() {
    if (efeito_.duracao > 0) {
        switch (efeito_.tipo) {
            case TipoEfeito::Veneno:
                vida_ -= 5;
                std::cout << nome_ << " sofre 5 de dano de veneno! Vida atual: " << vida_ << "/" << vidaMax_ << "\n";
                break;
            case TipoEfeito::Paralisia:
                std::cout << nome_ << " está paralisado e perde o turno!\n";
                break;
            case TipoEfeito::Maldição:
                ataque_ = std::max(1, ataque_ - 1);
                std::cout << nome_ << " está amaldiçoado! Ataque reduzido para " << ataque_ << "\n";
                break;
            default:
                break;
        }
        efeito_.duracao--;
    }
}

Efeito Jogador::getEfeito() const {
    return efeito_;
}

int Jogador::getAtaque() const {
    return ataque_;
}

void Jogador::setVida(int novaVida) {
    vida_ = std::max(0, std::min(novaVida, vidaMax_));
}

void Jogador::setVidaMax(int novaVidaMax) {
    vidaMax_ = novaVidaMax;
    if (vida_ > vidaMax_) {
        vida_ = vidaMax_;
    }
}

int Jogador::getDefesa() const {
    return defesa_;
}

