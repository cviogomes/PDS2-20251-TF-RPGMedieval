// MAIN ATUALIZADA
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>

// Funções de utilidade
#include "Utils.hpp"

// Classes de Personagens
#include "Jogador.hpp"
#include "Combate.hpp"

// Classes de Inimigos
#include "Zumbi.hpp"
#include "Esqueleto.hpp"
#include "Vampiro.hpp"
#include "Goblin.hpp"
#include "Slime.hpp"
#include "Aranha.hpp"
#include "Lobisomem.hpp"
#include "Bruxa.hpp"

// Classes de Chefes
#include "CavaleiroDaPeste.hpp"
#include "CavaleiroDaFome.hpp"
#include "CavaleiroDaGuerra.hpp"
#include "CavaleiroDaMorte.hpp"

// Função Auxiliar para Decisões 
int fazerEscolha(const std::string& pergunta, const std::vector<std::string>& opcoes) {
    typeText("\n--- DECISÃO ---\n", TextSpeed::NORMAL);
    typeText(pergunta + "\n", TextSpeed::NORMAL);
    for (size_t i = 0; i < opcoes.size(); ++i) {
        typeText(std::to_string(i + 1) + " - " + opcoes[i] + "\n", TextSpeed::NORMAL);
    }
  
    int escolha = 0;
    while (true) {
        std::cout << "Opção: ";
        std::cin >> escolha;
        if (std::cin.good() && escolha > 0 && escolha <= opcoes.size()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            break;
        }
        typeText("Opção inválida. Tente novamente.\n", TextSpeed::NORMAL);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return escolha;
}

// Função Principal
int main() {
    setupTerminal();
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // PRÓLOGO
    narrativePrint("Narrador", "Thyria... outrora um reino próspero de cavaleiros, florestas verdejantes e vilarejos cheios de vida. Agora... um eco.");
    narrativePrint("Narrador", "Duas figuras encapuzadas ajoelham-se em um círculo profano. As sombras rasgam o céu. A fenda foi aberta.");
    narrativePrint("Nyx", "Por suas perdas... por sua dor... eu vos trago aquilo que mais desejam... mas todo preço deve ser pago.");
