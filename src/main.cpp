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

    // ESCOLHA DA CLASSE
    int classe = fazerEscolha("O mundo precisa de um herói. Quem você será?", {"Guerreiro", "Arqueiro", "Mago"});
    std::unique_ptr<Jogador> jogador;
    if (classe == 1) jogador = std::make_unique<Jogador>("Guerreiro", 120, 20, 10);
    else if (classe == 2) jogador = std::make_unique<Jogador>("Arqueiro", 100, 25, 5);
    else jogador = std::make_unique<Jogador>("Mago", 80, 30, 3);
    narrativePrint("Narrador", "E assim começou o fim... ou o início de sua redenção.");

    // CAPÍTULO 1: O SUSPIRO DA PESTE
    narrativePrint("Narrador", "Capítulo 1: O Suspiro da Peste.");
    narrativePrint("Narrador", "Você desperta. Sua vila, Aldhaven, não é mais lar... mas um túmulo esperando ser preenchido.");
    narrativePrint("Seraphina", "A morte não é fim... é libertação.");

    int escolha_cap1 = fazerEscolha("Os gritos dos inocentes cortam o ar, mas os suprimentos em sua mão podem garantir sua sobrevivência. O que você prioriza?", {"Salvar os Civis", "Proteger Recursos"});
    if (escolha_cap1 == 1) {
        narrativePrint("Narrador", "Você guia os sobreviventes para um celeiro, ganhando sua lealdade, mas perde recursos valiosos.");
        jogador->adicionarMoral(5);
    } else {
        narrativePrint("Narrador", "Você guarda os suprimentos, mas os gritos dos abandonados ecoarão em sua mente.");
        jogador->ganharOuro(20);
        jogador->adicionarMoral(-5);
    }

    narrativePrint("Narrador", "Os infectados pela peste se arrastam em sua direção!");
    std::vector<std::unique_ptr<Inimigo>> inimigos_c1 = {std::make_unique<Zumbi>(), std::make_unique<Esqueleto>()};
    lutar(*jogador, inimigos_c1);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }
