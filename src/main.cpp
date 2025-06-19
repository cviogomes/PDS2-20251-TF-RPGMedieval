// ======================= main.cpp (reescrito com múltiplos inimigos e clone) =======================
#include <iostream>
#include <ctime>
#include <vector>
#include <memory>
#include "Jogador.hpp"
#include "Combate.hpp"
#include "Zumbi.hpp"
#include "Bruxa.hpp"
#include "Lobisomem.hpp"
#include "Slime.hpp"
#include "Vampiro.hpp"
#include "Goblin.hpp"
#include "Aranha.hpp"
#include "CavaleiroDaPeste.hpp"
#include "CavaleiroDaGuerra.hpp"
#include "CavaleiroDaFome.hpp"
#include "CavaleiroDaMorte.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Escolha sua classe:\n1 - Arqueiro\n2 - Guerreiro\n3 - Mago\nOpção: ";
    int opcao;
    std::cin >> opcao;

    std::unique_ptr<Jogador> jogador;
    switch (opcao) {
        case 1: jogador = std::make_unique<Jogador>("Arqueiro", 80, 25, 5); break;
        case 2: jogador = std::make_unique<Jogador>("Guerreiro", 100, 20, 10); break;
        default: jogador = std::make_unique<Jogador>("Mago", 70, 30, 3); break;
    }

    std::vector<std::unique_ptr<Inimigo>> fracosPrototype;
    fracosPrototype.push_back(std::make_unique<Zumbi>());
    fracosPrototype.push_back(std::make_unique<Bruxa>());
    fracosPrototype.push_back(std::make_unique<Lobisomem>());
    fracosPrototype.push_back(std::make_unique<Slime>());
    fracosPrototype.push_back(std::make_unique<Vampiro>());
    fracosPrototype.push_back(std::make_unique<Goblin>());
    fracosPrototype.push_back(std::make_unique<Aranha>());

    std::vector<std::unique_ptr<Inimigo>> bossesPrototype;
    bossesPrototype.push_back(std::make_unique<CavaleiroDaPeste>());
    bossesPrototype.push_back(std::make_unique<CavaleiroDaGuerra>());
    bossesPrototype.push_back(std::make_unique<CavaleiroDaFome>());
    bossesPrototype.push_back(std::make_unique<CavaleiroDaMorte>());

    for (int etapa = 0; etapa < 4; ++etapa) {
        for (int i = 0; i < 2; ++i) {
            int idx = std::rand() % fracosPrototype.size();
            std::vector<std::unique_ptr<Inimigo>> inimigos;
            inimigos.push_back(fracosPrototype[idx]->clone());
            lutar(*jogador, std::move(inimigos));

            if (!jogador->estaVivo()) {
                std::cout << "\nGame Over!\n";
                return 0;
            }
            jogador->ganharOuro(100);
            jogador->visitarLoja();
        }

        std::vector<std::unique_ptr<Inimigo>> boss;
        boss.push_back(bossesPrototype[etapa]->clone());
        lutar(*jogador, std::move(boss));

        if (!jogador->estaVivo()) {
            std::cout << "\nGame Over!\n";
            return 0;
        }
        jogador->ganharOuro(1000);
        jogador->visitarLoja();
    }

    std::cout << "\nParabéns! Você derrotou os Quatro Cavaleiros do Apocalipse!\n";
    return 0;
}
