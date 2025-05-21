#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador(const std::string& nome, int vidaMax, int ataque, int defesa)
    : Personagem(nome, vidaMax, ataque, defesa),
      ouro_(0),
      pocoes_(0),
      investimento_(0.0)
{

}

void Jogador::mostrarOuro() const {
    std::cout << "Ouro atual: " << ouro_ << std::endl;
}

void Jogador::ganharOuro(int quantidade) {
    ouro_ += quantidade;
    std::cout << "Você ganhou " << quantidade << " de ouro! (Total: " << ouro_ << ")\n";
}

void Jogador::investirOuro(int quantidade) {
    if (quantidade > 0 && quantidade <= ouro_) {
        ouro_ -= quantidade;
        investimento_ += quantidade;
        std::cout << "Você investiu " << quantidade << " de ouro!" << std::endl;
    } else {
        std::cout << "Aprenda matemática, campeão!" << std::endl;
    }
}

void Jogador::retornarInvestimento() {
    if (investimento_ > 0) {
        int retorno = static_cast<int>(investimento_ * 1.5);
        ouro_ += retorno;
        std::cout << "Seu investimento rendeu " << retorno << " de ouro! (Total: " << ouro_ << ")\n";
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
