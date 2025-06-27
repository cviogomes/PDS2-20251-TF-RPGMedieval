#include "Combate.hpp"
#include <iostream>

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>>& inimigos) { 
    for (auto& inimigo : inimigos) { 
        if (!jogador.estaVivo()) break;

        std::cout << "\n" << inimigo->getNome() << " apareceu!\n";

        while (jogador.estaVivo() && inimigo->estaVivo()) {
            jogador.processarEfeitos();
            if (jogador.getEfeito().tipo == TipoEfeito::Paralisia && jogador.getEfeito().duracao > 0) {
                 std::cout << jogador.getNome() << " está paralisado!\n";
            } else {
                std::cout << "Escolha uma ação:\n";
                std::cout << "1 - Atacar\n";
                std::cout << "2 - Defender\n";
                std::cout << "3 - Beber poção\n";
                std::cout << "Opção: ";
                int acao;
                std::cin >> acao;

                switch (acao) {
                    case 1:
                        jogador.atacar(*inimigo);
                        break;
                    case 2:
                        jogador.defender();
                        break;
                    case 3:
                        jogador.usarPocao();
                        break;
                    default:
                        std::cout << "Ação inválida. Perdeu o turno!\n";
                        break;
                }
            }

            if (inimigo->estaVivo()) {
                inimigo->atacar(jogador);
            }
        }

        if (!inimigo->estaVivo()) {
            std::cout << inimigo->getNome() + " foi derrotado!\n";
        }
    }
    inimigos.clear(); // Limpa a lista no final
}