#include "Combate.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>>& inimigos) {
    for (auto& inimigo : inimigos) {
        if (!jogador.estaVivo()) break;

        battlePrint("\n" + inimigo->getNome() + " apareceu!\n");

        while (jogador.estaVivo() && inimigo->estaVivo()) {
            std::cout << "\n";
            battlePrint("Vida: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + " | Pocoes: " + std::to_string(jogador.getPocoes()) + "\n");
            battlePrint("Inimigo: " + inimigo->getNome() + " | Vida: " + std::to_string(inimigo->getVida()) + "/" + std::to_string(inimigo->getVidaMax()) + "\n");

            jogador.processarEfeitos();
            if (!jogador.estaVivo()) break;

            if (jogador.getEfeito().tipo != TipoEfeito::Paralisia) { // Lógica de paralisia refinada
                typeText("Escolha uma acao:\n1 - Atacar\n2 - Defender\n3 - Usar Pocao\nOpcao: ", TextSpeed::NORMAL);
                int acao;
                std::cin >> acao;

                switch (acao) {
                    case 1:
                        jogador.atacar(*inimigo);
                        inimigo->aoReceberDano(jogador.getAtaque());
                        break;
                    case 2:
                        jogador.defender();
                        break;
                    case 3:
                        jogador.usarPocao();
                        break;
                    default:
                        battlePrint("Acao invalida. Voce perdeu o turno!\n");
                        std::cin.clear(); // Tratamento de erro
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Tratamento de erro
                        break;
                }
            }

            if (inimigo->estaVivo()) {
                inimigo->aoAtacar(jogador);
                inimigo->atacar(jogador);
            }
        }

        if (!inimigo->estaVivo()) {
            battlePrint(inimigo->getNome() + " foi derrotado!\n");
        }
    }
    inimigos.clear();
}