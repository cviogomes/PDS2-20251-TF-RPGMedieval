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

    narrativePrint("Narrador", "Um vampiro degenerado, um lorde caído, bloqueia seu caminho.");
    std::vector<std::unique_ptr<Inimigo>> miniboss_c1 = {std::make_unique<Vampiro>()};
    lutar(*jogador, miniboss_c1);

    if (!jogador->estaVivo()) { 
        narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); 
        return 0; }

    narrativePrint("Seraphina", "Pobrezinho... Ainda acredita em esperança? Eu sou a cura para este mundo podre.");
    std::vector<std::unique_ptr<Inimigo>> boss_c1 = {std::make_unique<CavaleiroDaPeste>()};
    lutar(*jogador, boss_c1);
    
    if (!jogador->estaVivo()) {
         narrativePrint("Roland", "Levante-se, herói. Ainda não é sua hora.");
         jogador->setVida(jogador->getVidaMax() * 0.5);
         std::vector<std::unique_ptr<Inimigo>> boss_c1_retry = {std::make_unique<CavaleiroDaPeste>()};
         lutar(*jogador, boss_c1_retry);
    }
    if (!jogador->estaVivo()) { 
        narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida.");
      return 0;
    }
    
    narrativePrint("Seraphina", "Não é o fim... Eles virão... todos virão... HAHAHA!");
    jogador->ganharOuro(50);
    jogador->visitarLoja(1);

    // CAPÍTULO 2: O BANQUETE DA FOME
    narrativePrint("Narrador", "Capítulo 2: O Banquete da Fome.");
    narrativePrint("Narrador", "Com a Peste derrotada, a fome rasteja pelas terras, e sua sombra engole tudo.");
    
    int caminho_c2 = fazerEscolha("Dois caminhos se abrem. Qual você seguirá?", {"A Floresta Sombria", "As Montanhas Rochosas"});
    if (caminho_c2 == 1) {
        narrativePrint("Narrador", "Você adentra a Floresta Sombria, lar de aranhas e lobisomens.");

        std::vector<std::unique_ptr<Inimigo>> inimigos_c2 = {std::make_unique<Aranha>(), std::make_unique<Lobisomem>()};
        lutar(*jogador, inimigos_c2);

    } else {
        narrativePrint("Narrador", "Você escala as Montanhas Rochosas, infestadas de slimes e goblins.");
        std::vector<std::unique_ptr<Inimigo>> inimigos_c2 = {std::make_unique<Slime>(), std::make_unique<Goblin>()};
        lutar(*jogador, inimigos_c2);
    }
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }

    narrativePrint("Narrador", "Um goblin devoto, fanático por seu mestre, tenta impedi-lo.");
    std::vector<std::unique_ptr<Inimigo>> miniboss_c2 = {std::make_unique<Goblin>()};
    lutar(*jogador, miniboss_c2);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }
    
    narrativePrint("Vorstag", "Comam... ou sejam comidos. Não há outro caminho.");
    std::vector<std::unique_ptr<Inimigo>> boss_c2 = {std::make_unique<CavaleiroDaFome>()};
    lutar(*jogador, boss_c2);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }

    narrativePrint("Vorstag", "A fome... nunca acaba... ela apenas espera...");
    jogador->ganharOuro(75);
    jogador->visitarLoja(2);

    // CAPÍTULO 3: A FORJA DA GUERRA
    narrativePrint("Narrador", "Capítulo 3: A Forja da Guerra.");
    narrativePrint("Narrador", "O trovão da Guerra ecoa nas planícies. Thargon marcha com seu exército.");
 
    int escolha_c3 = fazerEscolha("Você encontra uma fortaleza rebelde. O que você faz?", {"Ajudar os Rebeldes", "Invadir o acampamento sozinho"});
    if (escolha_c3 == 1) {
        narrativePrint("Narrador", "Você ajuda os rebeldes a fortificar a defesa, ganhando aliados para a batalha.");
        jogador->adicionarMoral(5);
    } else {
        narrativePrint("Narrador", "Você decide agir sozinho, um caminho mais arriscado, porém com maiores recompensas.");
        jogador->adicionarMoral(-5);
        jogador->ganharOuro(50);
    }

    narrativePrint("Narrador", "As máquinas de guerra de Thargon avançam: Slimes Corrosivos e Goblins Guerreiros.");
    std::vector<std::unique_ptr<Inimigo>> inimigos_c3 = {std::make_unique<Slime>(), std::make_unique<Goblin>()};
    lutar(*jogador, inimigos_c3);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }

    narrativePrint("Thargon", "Vocês chamam isso de luta? Eu sou a guerra encarnada!");
    std::vector<std::unique_ptr<Inimigo>> boss_c3 = {std::make_unique<CavaleiroDaGuerra>()};
    lutar(*jogador, boss_c3);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }

    narrativePrint("Thargon", "A guerra... nunca termina... apenas muda de rosto...");
    jogador->ganharOuro(100);
    jogador->visitarLoja(3);

    // CAPÍTULO 4: O VÉU DA MORTE
    narrativePrint("Narrador", "Capítulo 4: O Véu da Morte.");
    narrativePrint("Narrador", "Três Cavaleiros caíram. A Morte aguarda no coração da fenda. E ao seu lado... Nyx.");
    narrativePrint("Nyx", "Você chegou longe, herói. Junte-se a mim... ou pereça.");
    
    int escolha_c4_nyx = fazerEscolha("Nyx oferece poder, mas a um custo. Qual seu caminho?", {"Aliar-se a Nyx", "Combater Nyx"});

    if (escolha_c4_nyx == 1) {
        narrativePrint("Narrador", "Você aceita a oferta de Nyx, sentindo um poder sombrio fluir em você.");
        jogador->setAliadoNyx(true);
        jogador->adicionarMoral(-10);
    } else {
        narrativePrint("Narrador", "Você recusa a oferta e se prepara para lutar. Sua honra permanece intacta.");
        jogador->adicionarMoral(10);
        std::vector<std::unique_ptr<Inimigo>> miniboss_nyx = {std::make_unique<Bruxa>()};
        lutar(*jogador, miniboss_nyx);
        if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }
    }

    narrativePrint("Moros", "...");
    std::vector<std::unique_ptr<Inimigo>> boss_c4 = {std::make_unique<CavaleiroDaMorte>()};
    lutar(*jogador, boss_c4);
    if (!jogador->estaVivo()) { narrativePrint("Narrador", "Sua jornada termina aqui. Thyria está perdida."); return 0; }
