#include "Combate.hpp"
#include "Utils.hpp" // Adicione esta linha no topo do arquivo
#include <iostream>
#include <limits>

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>>& inimigos) {
    for (auto& inimigo : inimigos) {
        if (!jogador.estaVivo()) break;

        battlePrint("\n" + inimigo->getNome() + " apareceu!\n");

        while (jogador.estaVivo() && inimigo->estaVivo()) {
            std::cout << "\n";
            battlePrint("Vida: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + " | Poções: " + std::to_string(jogador.getPocoes()) + "\n");
            battlePrint("Inimigo: " + inimigo->getNome() + " | Vida: " + std::to_string(inimigo->getVida()) + "/" + std::to_string(inimigo->getVidaMax()) + "\n");

            jogador.processarEfeitos();
            if (!jogador.estaVivo()) break;

            // Lógica de paralisia e ação ainda não estão finais aqui
            typeText("Escolha uma ação:\n1 - Atacar\n2 - Defender\n3 - Usar Poção\nOpção: ", TextSpeed::NORMAL);
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
                    battlePrint("Ação inválida. Você perdeu o turno!\n");
                    break;
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