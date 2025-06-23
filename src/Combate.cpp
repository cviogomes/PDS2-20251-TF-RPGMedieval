#include "Combate.hpp"
#include <iostream>

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>> inimigos) {
    while (jogador.estaVivo() && !inimigos.empty()) {
        auto& inimigo = *inimigos.front();
        std::cout << "\n" << inimigo.getNome() << " apareceu!\n";

        jogador.processarEfeitos();

        if (jogador.getEfeito().tipo == TipoEfeito::Paralisia && jogador.getEfeito().duracao > 0) {
            std::cout << jogador.getNome() << " está paralisado!\n";
            if (inimigo.estaVivo()) {
                inimigo.aoAtacar(jogador);
                inimigo.atacar(jogador);
            }
            continue; // pular o turno do jogador
        }

        std::cout << "Escolha uma ação:\n";
        std::cout << "1 - Atacar\n";
        std::cout << "2 - Defender\n";
        std::cout << "3 - Beber poção\n";
        std::cout << "Opção: ";
        int acao;
        std::cin >> acao;

        switch (acao) {
            case 1: {
                int dano = jogador.getAtaque();
                jogador.atacar(inimigo);
                inimigo.aoReceberDano(dano);
                break;
            }
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

        if (inimigo.estaVivo()) {
            inimigo.aoAtacar(jogador);
            inimigo.atacar(jogador);
        }

        if (!inimigo.estaVivo()) {
            inimigos.erase(inimigos.begin());
        }
    }
}

