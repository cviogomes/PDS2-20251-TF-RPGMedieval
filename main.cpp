#include <iostream>
#include <ctime>
#include "Jogador.hpp"
#include "Combate.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 1) Seleção de classe
    std::cout << "Escolha sua classe:\n"
              << "1 - Arqueiro\n"
              << "2 - Guerreiro\n"
              << "3 - Mago\n"
              << "Opção: ";
    int opcao;
    std::cin >> opcao;

    Jogador* jogador = nullptr;
    switch (opcao) {
        case 1: jogador = new Jogador("Arqueiro", 80, 25, 5); break;
        case 2: jogador = new Jogador("Guerreiro", 100, 20, 10); break;
        default: jogador = new Jogador("Mago", 70, 30, 3); break;
    }

    // 2) Ciclo de 4 etapas: 2 inimigos fracos → loja → 1 boss
    Personagem fracos[] = {
        Personagem("Esqueleto", 50, 15, 3),
        Personagem("Goblin",   60, 18, 4),
        Personagem("Anão",     65, 17, 6),
        Personagem("Orc",      70, 20, 5)
    };
    Personagem bosses[] = {
        Personagem("Cavaleiro Branco", 90, 22, 5),
        Personagem("Cavaleiro Vermelho", 120, 25, 10),
        Personagem("Cavaleiro Preto", 80, 28, 3),
        Personagem("Cavaleiro da Morte", 150, 30, 15)
    };

    for (int etapa = 0; etapa < 4; ++etapa) {
        // dois inimigos fracos aleatórios
        for (int i = 0; i < 2; ++i) {
            int idx = std::rand() % 4;
            Personagem inimigo = fracos[idx];
            lutar(*jogador, inimigo);
            if (!jogador->estaVivo()) {
                std::cout << "\nGame Over!\n";
                delete jogador;
                return 0;
            }
            jogador->ganharOuro(100);
            jogador->visitarLoja();
        }
        
        // boss
        Personagem chefe = bosses[etapa];
        lutar(*jogador, chefe);
        if (!jogador->estaVivo()) {
            std::cout << "\nGame Over!\n";
            delete jogador;
            return 0;
        }
        jogador->ganharOuro(1000);
        jogador->visitarLoja();
    }

    std::cout << "\nParabéns! Você derrotou os Quatro Cavaleiros do Apocalipse!\n";
    delete jogador;
    return 0;
}
