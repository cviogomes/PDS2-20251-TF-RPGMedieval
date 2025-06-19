#include "Combate.hpp"
#include <iostream>

void lutar(Jogador &jogador, Personagem &inimigo) {
    std::cout << "\n--- " << inimigo.getNome() << " apareceu! ---\n";
    while (jogador.estaVivo() && inimigo.estaVivo()){
        std::cout << "\nEscolha uma acao:\n";
        std::cout << "1 - Atacar\n";
        std::cout << "2 - Defender\n";
        std::cout << "3 - Beber pocao\n";
        std::cout << "Opcao: ";
        int acao;
        std::cin >> acao;

        switch (acao) {
            case 1:
                jogador.atacar(inimigo);
                break;

            case 2:
                jogador.defender();
                break;

            case 3:
                jogador.usarPocao();
                break;

            
        }
        if (inimigo.estaVivo()) {
            inimigo.atacar(jogador);
        }
    }
}
