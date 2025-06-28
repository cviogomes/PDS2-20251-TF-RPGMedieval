#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>

#include "Utils.hpp"
#include "Jogador.hpp"
#include "Combate.hpp"

#include "Zumbi.hpp"
#include "Esqueleto.hpp"
#include "Vampiro.hpp"
#include "Goblin.hpp"
#include "Slime.hpp"
#include "Aranha.hpp"
#include "Lobisomem.hpp"
#include "Bruxa.hpp"

#include "CavaleiroDaPeste.hpp"
#include "CavaleiroDaFome.hpp"
#include "CavaleiroDaGuerra.hpp"
#include "CavaleiroDaMorte.hpp"

#include "Musica.hpp"

int fazerEscolha(const std::string& pergunta, const std::vector<std::string>& opcoes) {
    typeText("\n--- DECISAO ---\n", TextSpeed::NORMAL);
    typeText(pergunta + "\n", TextSpeed::NORMAL);
    for (size_t i = 0; i < opcoes.size(); ++i) {
        typeText(std::to_string(i + 1) + " - " + opcoes[i] + "\n", TextSpeed::NORMAL);
    }

    int escolha = 0;
    while (true) {
        std::cout << "Opcao: ";
        std::cin >> escolha;
        if (std::cin.good() && escolha > 0 && escolha <= opcoes.size()
            ) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        typeText("Opcao invalida. Tente novamente.\n", TextSpeed::NORMAL);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return escolha;
}

int main() {

    Musica musica;
    musica.PlayMusic("musicas/minecraft.wav");
    setupTerminal();
    std::srand(static_cast<unsigned>(std::time(nullptr)
        )
    );

    narrativePrint("Narrador", "Thyria... outrora um reino prospero de cavaleiros, florestas verdejantes e vilarejos cheios de vida. Agora... um eco.");
    
    //imagem castelo
    
    narrativePrint("Narrador", "Duas figuras encapuzadas ajoelham-se em um circulo profano. As sombras rasgam o ceu. A fenda foi aberta.");
    narrativePrint("Nyx", "Por suas perdas... por sua dor... eu vos trago aquilo que mais desejam... mas todo preco deve ser pago.");

    int classe = fazerEscolha("O mundo precisa de um heroi. Quem voce sera?", {"Guerreiro", "Arqueiro", "Mago"});
    
// imagem guerreiro, mago ou arqueiro dependendo da decisão
    
    std::unique_ptr<Jogador> jogador;
    if (classe == 1) jogador = std::make_unique<Jogador>("Guerreiro", 120, 20, 10);
    else if (classe == 2) jogador = std::make_unique<Jogador>("Arqueiro", 100, 25, 5);
    else jogador = std::make_unique<Jogador>("Mago", 80, 30, 3);

    narrativePrint("Narrador", "E assim comecou o fim... ou o inicio de sua redencao.");

    narrativePrint("Narrador", "Capitulo 1: O Suspiro da Peste.");
    narrativePrint("Narrador", "Voce desperta. Sua vila, Aldhaven, nao e' mais lar... mas um tumulo esperando ser preenchido.");

//imagem vila

    narrativePrint("Seraphina", "A morte nao e' fim... e' libertacao.");

    int escolha_cap1 = fazerEscolha("Os gritos dos inocentes cortam o ar, mas os suprimentos em sua mao podem garantir sua sobrevivencia. O que voce prioriza?", 
    {"Salvar os Civis", 
    "Proteger Recursos"});
    if (escolha_cap1 == 1) {
        narrativePrint("Narrador", "Voce guia os sobreviventes para um celeiro, ganhando sua lealdade, mas perde recursos valiosos.");
        jogador->adicionarMoral(5);
    } else {
        narrativePrint("Narrador", "Voce guarda os suprimentos, mas os gritos dos abandonados ecoarao em sua mente.");
        jogador->ganharOuro(20);
        jogador->adicionarMoral(-5);
    }

    narrativePrint("Narrador", "Os infectados pela peste se arrastam em sua direcao!");
    std::vector<std::unique_ptr<Inimigo>> inimigos_c1;
    inimigos_c1.emplace_back(std::make_unique<Zumbi>()

        // arte zumbi
        
        );
    inimigos_c1.emplace_back(std::make_unique<Esqueleto>()

        // arte esqueleto
        
        );
    lutar(*jogador, inimigos_c1);

    // arte batalha
    
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Narrador", "Um vampiro degenerado, um lorde caido, bloqueia seu caminho.");
    std::vector<std::unique_ptr<Inimigo>> miniboss_c1;
    miniboss_c1.emplace_back(std::make_unique<Vampiro>()

        // arte vampiro
        
        );
    lutar(*jogador, miniboss_c1);

    // arte batalha
    
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Seraphina", "Pobrezinho... Ainda acredita em esperanca? Eu sou a cura para este mundo podre.");
    std::vector<std::unique_ptr<Inimigo>> boss_c1;
    boss_c1.emplace_back(std::make_unique<CavaleiroDaPeste>());
    lutar(*jogador, boss_c1);

    // arte batalha
    
    if (!jogador->estaVivo()) {
        narrativePrint("Roland", 
            "Levante-se, heroi. Ainda nao e' sua hora.");
        jogador->setVida(jogador->getVidaMax() * 0.5);
        std::vector<std::unique_ptr<Inimigo>> retry;
        retry.emplace_back(std::make_unique<CavaleiroDaPeste>()
            );
        lutar(*jogador, retry);
        if (!jogador->estaVivo()
            ) 
            return 0;
    }

    narrativePrint("Seraphina", "Nao e' o fim... Eles virao... todos virao... HAHAHA!");
    jogador->ganharOuro(50);
    jogador->visitarLoja(1);

    narrativePrint("Narrador", "Capitulo 2: O Banquete da Fome.");
    narrativePrint("Narrador", "Com a Peste derrotada, a fome rasteja pelas terras, e sua sombra engole tudo.");

    int caminho_c2 = fazerEscolha("Dois caminhos se abrem. Qual você seguira?", {"A Floresta Sombria", "As Montanhas Rochosas"});
    std::vector<std::unique_ptr<Inimigo>> inimigos_c2;
    if (caminho_c2 == 1) {
        narrativePrint("Narrador", "Voce adentra a Floresta Sombria, lar de aranhas e lobisomens.");
        inimigos_c2.emplace_back(std::make_unique<Aranha>()
            );

        // arte aranha
        
        inimigos_c2.emplace_back(std::make_unique<Lobisomem>()
            );

        // arte lobisomen
        
    } else {
        narrativePrint("Narrador", "Voce escala as Montanhas Rochosas, infestadas de slimes e goblins.");

        // arte montanhas
        
        inimigos_c2.emplace_back(std::make_unique<Slime>()

            // arte slime
            );
        inimigos_c2.emplace_back(std::make_unique<Goblin>()
            );

        // arte goblin
    }
    lutar(*jogador, inimigos_c2);
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Narrador", "Um goblin devoto, fanatico por seu mestre, tenta impedi-lo.");
    std::vector<std::unique_ptr<Inimigo>> miniboss_c2;
    miniboss_c2.emplace_back(std::make_unique<Goblin>()

        // arte goblin
        
        );
    lutar(*jogador, miniboss_c2);

    // arte batalha 
    
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Vorstag", "Comam... ou sejam comidos. Nao ha outro caminho.");
    std::vector<std::unique_ptr<Inimigo>> boss_c2;
    boss_c2.emplace_back(std::make_unique<CavaleiroDaFome>()
        );
    lutar(*jogador, boss_c2);

    // arte batalha 
    
    if (!jogador->estaVivo()
        
        ) 
        return 0;

    narrativePrint("Vorstag", "A fome... nunca acaba... ela apenas espera...");
    jogador->ganharOuro(75);
    jogador->visitarLoja(2);

    narrativePrint("Narrador", "Capitulo 3: A Forja da Guerra.");
    narrativePrint("Narrador", "O trovao da Guerra ecoa nas planícies. Thargon marcha com seu exercito.");

    int escolha_c3 = fazerEscolha("Voce encontra uma fortaleza rebelde. O que voce faz?", 
    {"Ajudar os Rebeldes", 
    "Invadir o acampamento sozinho"});
    if (escolha_c3 == 1) jogador->adicionarMoral(5);
    else { jogador->adicionarMoral(-5); jogador->ganharOuro(50); }

    narrativePrint("Narrador", "As maquinas de guerra de Thargon avancam: Slimes Corrosivos e Goblins Guerreiros.");
    std::vector<std::unique_ptr<Inimigo>> inimigos_c3;
    inimigos_c3.emplace_back(std::make_unique<Slime>()
        );

    // arte slime
    
    inimigos_c3.emplace_back(std::make_unique<Goblin>()
        );

    //arte goblin
    
    lutar(*jogador, inimigos_c3);

    // arte batalha
    
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Thargon", "Voces chamam isso de luta? Eu sou a guerra encarnada!");
    std::vector<std::unique_ptr<Inimigo>> boss_c3;
    boss_c3.emplace_back(std::make_unique<CavaleiroDaGuerra>()
        );
    lutar(*jogador, boss_c3);

    // arte batalha
    
    if (!jogador->estaVivo()
        ) 
        return 0;

    narrativePrint("Thargon", "A guerra... nunca termina... apenas muda de rosto...");
    jogador->ganharOuro(100);
    jogador->visitarLoja(3);

    narrativePrint("Narrador", "Capitulo 4: O Veu da Morte.");
    narrativePrint("Narrador", "Tres Cavaleiros cairam. A Morte aguarda no coracao da fenda. E ao seu lado... Nyx.");
    narrativePrint("Nyx", "Voce chegou longe, heroi. Junte-se a mim... ou pereça.");

    int escolha_c4_nyx = fazerEscolha("Nyx oferece poder, mas a um custo. Qual seu caminho?", 
    {"Aliar-se a Nyx", 
    "Combater Nyx"});
    if (escolha_c4_nyx == 1) {
        jogador->setAliadoNyx(true);
        jogador->adicionarMoral(-10);
    } else {
        jogador->adicionarMoral(10);
        std::vector<std::unique_ptr<Inimigo>> miniboss_nyx;
        miniboss_nyx.emplace_back(std::make_unique<Bruxa>()
            );
        
        // arte bruxa
        
        lutar(*jogador, miniboss_nyx);

        // arte batalha
        
        if (!jogador->estaVivo()
            ) 
            return 0;
    }

    narrativePrint("Moros", "...");
    std::vector<std::unique_ptr<Inimigo>> boss_c4;
    boss_c4.emplace_back(std::make_unique<CavaleiroDaMorte>()
        );
    lutar(*jogador, boss_c4);
    if (!jogador->estaVivo()
        ) 
        return 0;

    int moralFinal = jogador->getMoral();
    bool aliadoNyx = jogador->temAliadoNyx();

    if (aliadoNyx) {
        narrativePrint("Narrador", "--- FINAL SOMBRIO ---");
        narrativePrint("Narrador", "Voce se torna o novo arauto do apocalipse...");
    } else if (moralFinal > 10) {
        narrativePrint("Narrador", "--- FINAL HEROICO ---");
        narrativePrint("Narrador", "Voce fecha a fenda com um ultimo golpe...");
    } else {
        narrativePrint("Narrador", "--- FINAL TRAGICO ---");
        narrativePrint("Narrador", "Voce derrota Moros, mas a um custo terrivel...");
    }

    narrativePrint("Narrador", "\n\nFIM DE JOGO.");
    return 0;
}
