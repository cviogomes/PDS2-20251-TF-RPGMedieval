#include "Combate.hpp"
#include <iostream>

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>> inimigos) {
    while (jogador.estaVivo() && !inimigos.empty()) {
        auto& inimigo = *inimigos.front();

        std::cout << "\n" << inimigo.getNome() << " apareceu!\n";

        std::cout << "Escolha uma acao:\n";
        std::cout << "1 - Atacar\n";
        std::cout << "2 - Defender\n";
        std::cout << "3 - Beber pocao\n";
        std::cout << "Opcao: ";
        int acao;
        std::cin >> acao;

        switch (acao) {
            case 1:
                jogador.atacar(inimigo);
                inimigo.aoReceberDano(jogador.getVida());
                break;
            case 2:
                jogador.defender();
                break;
            case 3:
                jogador.usarPocao();
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
