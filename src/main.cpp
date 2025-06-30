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
#include "Finais.hpp"

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

int fazerEscolha(const std::string &pergunta, const std::vector<std::string> &opcoes)
{
  typeText("\n--- DECISAO ---\n", TextSpeed::NORMAL);
  typeText(pergunta + "\n", TextSpeed::NORMAL);
  for (size_t i = 0; i < opcoes.size(); ++i)
  {
    typeText(std::to_string(i + 1) + " - " + opcoes[i] + "\n", TextSpeed::NORMAL);
  }

  int escolha = 0;
  while (true)
  {
    std::cout << "Opcao: ";
    std::cin >> escolha;
    if (std::cin.good() && escolha > 0 && escolha <= static_cast<int>(opcoes.size()))
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    typeText("Opcao invalida. Tente novamente.\n", TextSpeed::NORMAL);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return escolha;
}

int main()
{

  setupTerminal();
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  Musica musica;
  musica.PlayMusic("musicas/CAP1.wav");
  narrativePrint("Narrador", "Thyria... outrora um reino prospero de cavaleiros, florestas verdejantes e vilarejos cheios de vida. Agora... um eco.");
  // imagem castelo

  std::string castelo = R"(
                                                        
                                o                                         
                            .-'"|                                         
                            |-'"|                                         
                                |   _.-'`.                                
                               _|-"'_.-'|.`.                              
                              |:^.-'_.-'`.;.`.                            
                              | `.'.   ,-'_.-'|                           
                              |   + '-'.-'   J                            
           __.            .d88|    `.-'      |                            
      _.--'_..`.    .d88888888|     |       J'b.                          
   +:" ,--'_.|`.`.d88888888888|-.   |    _-.|888b.                        
   | \ \-'_.--'_.-+888888888+'  _&gt;F F +:'   `88888bo.                     
    L \ +'_.--'   |88888+"'  _.' J J J  `.    +8888888b.                  
    |  `+'        |8+"'  _.-'    | | |    +    `+8888888._-'.             
  .d8L  L         J  _.-'        | | |     `.    `+888+^'.-|.`.           
 d888|  |         J-'            F F F       `.  _.-"_.-'_.+.`.`.         
d88888L  L     _.  L            J J J          `|. +'_.-'    `_+ `;       
888888J  |  +-'  \ L         _.-+.|.+.          F `.`.     .-'_.-"J       
8888888|  L L\    \|     _.-'     '   `.       J    `.`.,-'.-"    |       
8888888PL | | \    `._.-'               `.     |      `..-"      J.b      
8888888 |  L L `.    \     _.-+.          `.   L+`.     |        F88b     
8888888  L | |   \   _..--'_.-|.`.          &gt;-'    `., J        |8888b    
8888888  |  L L   +:" _.--'_.-'.`.`.    _.-'     .-' | |       JY88888b   
8888888   L | |   J \ \_.-'     `.`.`.-'     _.-'   J J        F Y88888b  
Y888888    \ L L   L \ `.      _.-'_.-+  _.-'       | |       |   Y88888b 
`888888b    \| |   |  `. \ _.-'_.-'   |-'          J J       J     Y88888b
 Y888888     +'\   J    \ '_.-'       F    ,-T"\   | |    .-'      )888888
  Y88888b.      \   L    +'          J    /  | J  J J  .-'        .d888888
   Y888888b      \  |    |           |    F  '.|.-'+|-'         .d88888888
    Y888888b      \ J    |           F   J    -.              .od88888888P
     Y888888b      \ L   |          J    | .' ` \d8888888888888888888888P 
      Y888888b      \|   |          |  .-'`.  `\ `.88888888888888888888P  
       Y888888b.     J   |          F-'     \\ ` \ \88888888888888888P'   
        Y8888888b     L  |         J       d8`.`\  \`.8888888888888P'     
         Y8888888b    |  |        .+      d8888\  ` .'  `Y888888P'        
         `88888888b   J  |     .-'     .od888888\.-'                      
          Y88888888b   \ |  .-'     d888888888P'                          
          `888888888b   \|-'       d888888888P                            
           `Y88888888b            d8888888P'                              
             Y88888888bo.      .od88888888                                
             `8888888888888888888888888888                                
              Y88888888888888888888888888P                                
               `Y8888888888888888888888P'                                 
                 `Y8888888888888P'                                        
                      `Y88888P'                                           
    )";

  std::cout << castelo;

  narrativePrint("Narrador", "Duas figuras encapuzadas ajoelham-se em um circulo profano. As sombras rasgam o ceu. A fenda foi aberta.");
  narrativePrint("Nyx", "Por suas perdas... por sua dor... eu vos trago aquilo que mais desejam... mas todo preco deve ser pago.");

  int classe = fazerEscolha("O mundo precisa de um heroi. Quem voce sera?", {"Guerreiro", "Arqueiro", "Mago"});

  std::string classeJogador;

  // imagem guerreiro, mago ou arqueiro dependendo da decisão

  std::unique_ptr<Jogador> jogador;
  if (classe == 1)
  {
    classeJogador = "Guerreiro";
    jogador = std::make_unique<Jogador>("Guerreiro", 120, 20, 30);
    std::string guerreiro = R"(
                                                                        ##MM    ##                          
                                                          ####mmmm####  MM    ####                  
                                                        ##  mmmm##mmmmmmmmmmmmmm  ##                
                                                        ..mmmmmmmmmmmmmmmmmmmmmmmm  ##              
                                                      ##mmmmmmmmmmmmmmmmmmmm  mmmmmm                
                                                      ##mmmmmmmmmmmmmmmmmmmmmmmmmmmmmm##            
                                                        mm##mmmmmmmmmmmmmmmmmmmmmmmmmm##            
                                                        ######mm######mmmmmm  mmmmmmmmmm##          
                                                        ########      ##mmmmmmmmmmmmmmmmmm########  
                                                    ####      ++##      ####mmmmmmmmmmmm##mm@@##    
                                                  ##          ++++++##  ##mmmmmmmmmmmmmm##          
                                              ##              ++++++mm##  ####mmmmmmmmmm##          
  ####                                      ##                ++++++++##    ##mmmmmmmmmm##          
##      --                                ##                  ++++++++++##  ##mmmm##mmmmmm##        
        ##                            ####################################    ##mm##mmmmmmmmmm######
  ##      ##                          ##                        ##  ##++##      ##MMmmmmmm##mmmm##  
    ##      ##                        ##                      ..##  ++++##        ####mmmmmm##MM    
      ##      ##                      ##      ##  MM##  ##    ..##++##mm##                          
        ::      ##                    ##--##  ##..  ##  ##    ..##MM++++##                          
        ##..                          ##  ##  ##  ..##  ##      ##++++++##                          
          ##      ##                  ##  ##  ##  ..##  ##..    ##++++++##                          
            ##  ..  ##                    ##  ##..  ##  ##      ##++++++##                          
              ##      ##                  ##  ##..  ##  ##--    ####::######                        
                ##      ##              --##  ##    ##  ##MM    ##++##....####                      
                  ++      ##            ####  ++MM  ##        ..##############  ####                
                  ##      ##            ##                ++++####++######    ..++++mm####          
                    ##      ##        ####    ++++################      ..####  mm##++++++++########
                      ##      ##  ##MM##    ##    ######++  ....  ########      ++++++######mm++++++
                        ##      ##    ##        mm      ##  --                  ++++++++++++++++##++
                          ##..##..##          ####          ##                  ++++++++++++++++##++
                          ##  ..######  --####mm..++        ##                  ++++++++++++++++##++
                        ##    ##++####  ##    ++@@++        ##                  ++++++++++++++++##++
                      ##  ##  ##  --##  ##    ..##++        ..                  ++++++++++++++++##++
                        ##    ######++####++++::##++++    ::..                  ++++++++++++++++##++
                                ####++######mm++++++++..  ##  --                ++++++++++++++++MMmm
                                  ##########      ##++++++##  ##                ++++++++++++++++++##
                                      ##  ++MM    ##  ######  ##                ++++++++++++++##++##
                                        ####    ####          mm                ++++++++++++++##++##
                                              mm      MM######  ##              ++++++++++++++++++  
                                              ######++--    ##  ##              ++++++++++++##++##  
                                            ##    ++++##########  ##            ++++++++++++++mm    
                                          ########++++++++++++##  ##..          ++++++++++##++##    
                                          ##  ##++++##############  ##          ++++++++##++##      
                                                ########mm++++++++##  ##        ++++++##++++##      
                                        ##    ++++##++##            MM  ##      ++++##++mm##        
                                        ##    ++++++####              ##  ##..  ++##++++##          
                                    ######  ++++++####                ####....####++####            
                                  ##..  mm##++++##                  ##    ##..  ++##++              
                                  ++++++++++######                  ##++++++++########              
        )";

    std::cout << guerreiro;
  }
  else if (classe == 2)
  {
    classeJogador = "Arqueiro";
    jogador = std::make_unique<Jogador>("Arqueiro", 100, 25, 10);
    std::string arqueiro = R"(
                                                                                 
                                                                        ..##--                                                              
                                                                      ::      ##mm                                                          
                                                            --::@@##            ..##::                                                      
                                                      ++##mm--    MM++              ++##..                                                  
                                                  ..##--            ##                  ##MM                                                
                                                  mm--            ..  MM                  @@##                                              
                                                  ##                  MM                    MM##                                            
                                                  ##            ..MM    @@++                  MM##                                          
                            ++########mm          mm            ##..##++++##                    mm##                                        
                        @@mm            mm##::    mm        mm####    @@####                      @@@@                                      
                      ##        ####..    mm--    --..      ##--    ######--                        ##--                                    
                      @@      ##    ::##    ##      ++      ##    ..MM####                          ..##                                    
                      ##    ##          mm++        ::      @@    --####++@@##..                      ##MM                                  
                        ##    ##..          ::mm          ++mmmm  ++##        ####--                    ##                                  
                        mmmm    ##          --++  --------##  ..@@..::      @@    @@@@                  ##                                  
                          ##      ##        ##              @@    mm      @@    ##########              ##@@                                
                            ##########MM::..::            MM++++mm@@@@######++......  ::@@@@##++          ##                                
                                  ::##@@@@##++MM    ..  mm::              MM        ##..::mmmmMM######mm++##::--@@mm::                      
                                    ##  --##    mm##  MM@@::                @@      @@            mm##--::####  ########++                  
                                    ##  ##mm        ....  mm                ..        @@          ##  ++  ##::                              
                                    ##  ##                                    ##########@@        @@  MM  @@  ..                            
                                    ##  MM                  ++                @@  --##    @@####--@@  MM    ++                              
                                    ####                            ::        ..mm  ##            ##  @@  ++--                              
                                    ##++                      --      ##        ##  ##              ####..mm++                              
                                  mm####mm                              ##      ##  ##                ####++MM                              
                                ####  --####                    --        ##    ::  @@              ####                                    
                            --##..          mm::                          --##--  ::++            MM##                                      
                          ::MM                                              MM##MM##++          MM##..                                      
                        ::++                                      ..          ##@@##mm        ####                                          
                      ..mm                                                    ..##  ##    --####                                            
                      ##                                            ..          ##::    ####..                                              
                    ##                      --::########################::..      ######::                                                  
                    ##            ..++######MM++..                    ++++####@@####..                                                      
                  ####MMMMMM######@@--                                  ##::..--######                                                      
                                                                                    ##                                                      
                                                                                       
        )";

    std::cout << arqueiro;
  }
  else
  {
    classeJogador = "Mago";
    jogador = std::make_unique<Jogador>("Mago", 80, 30, 15);
    std::string mago = R"(
                                                                ##                                          
                                                    ##########..                                    
                                                  ####++##########                                  
                                                ####  ######MM######                                
                                              ####  @@######++######++                              
                                            ####::  ######++    ######                              
                                            ####  ##########  ######..                              
                                          ####    ##########@@##MM                                  
                                        ++##::  ##############                                      
                                        ####    ##############                                      
                                      MM####      ++##########                                      
                                      ############    ########::                                    
                                    @@############@@    ..######                                    
                                    ######################..@@##MM                                  
                                  ######::            --##########                                  
                                  ####MM    MM##########MM  ########                                
                                ####@@    ::##################@@####::                              
                              --####  @@##############################                              
                              ################--      --################                            
                            ############--MMMM##########MMMM++##########MM                          
                          mm##############################################..                        
                      ++##############@@----..          ..--++################                      
                  ##########mm..                                      ::##########MM                
            ++########::                --++mmmmmmmmmmmmmm::..                ++########            
        ++######++    ..mm################################################@@mm      @@######        
      ######++mm############################  --##  ##  @@##@@########################mmMM####@@    
  mm##################################mm                      @@##################################  
  ########################################mm      ##      ##########################################
############################..##########################################  ##########################
  ##########################  ########  ##  ####--  @@##mm::mmMM########  ##########################
    ######################MM  ######mm##--MM####      ####::++##++######  ########################  
      ::##################mm::####            ##      ##            ####  ####################      
            MM############..######            ##      @@            ####::MM############++          
                  MM######  ######@@        ##      ++..##        ########..######++                
                      @@##..##########    ++            @@..    ##########  ##..                    
                      ##++####::######  ..######      ######    ######MM##mm@@##                    
                    @@##..####  ####MM..####..MM######mm++####  ######++####  ##++                  
                ######..######  ####  ####    ++######::    ####@@##@@--######::####@@              
                  ############  ########    ##############    ######++  ############                
                    mmmm####mm  ######  --##################  ++####++  ######mmmm                  
                        ####    ######  ######          ######  ####++  ++####                      
                      ::####    ####  ##########################MM##MM    ####                      
                      ####      ########MM####          ########@@####    @@##mm                    
                      ####    mm########  ##::          ##MM++########      ####                    
                    ####..    ##########  ##            MM##  ##########    ####::                  
                    ####  ++MM########  ::##              ##  ..########..MM  ####                  
                  mm##::--  ########mm  ####              ####  ##########--  ####                  
                  ####  ############  ::##                @@##    ########MMMM--##MM                
                  ####  ##########MM  ####                --####  ############  ####                
                  ####mm##########::..####    ##      --    ####  MM##########  ####                
                  ################::MM####    ##      ##    ####  MM##########MM####                
                  ############MM##MM######  ..##      ##    ####..####..######MM##MM                
                  ##########--  ####@@####  ####      ##..  ####  ####  ##########..                
                  ::########    ####..####  ####      ##..mm####++##::    ########                  
                    ######mm      ########mm####    ####..##########      ########                  
                    ++####..      --########mm####  ####  ########        @@####                    
                      ####          ########  ####  ####@@######..        ::####                    
                        ##            ########################--          ::##                      
                        MM              ######################            ::                        
                                          ##################                                        
                                          ##@@########++##..                                        
                                            ++  ######  ##                                          
                                                ####                                                
                                                  ##                                                
        )";

    std::cout << mago;
  };

  narrativePrint("Narrador", "E assim comecou o fim... ou o inicio de sua redencao.");

  narrativePrint("Narrador", "Capitulo 1: O Suspiro da Peste.");
  narrativePrint("Narrador", "Voce desperta. Sua vila, Aldhaven, nao e' mais lar... mas um tumulo esperando ser preenchido.");

  // imagem vila

  std::string vila = R"(
    ~         ~~          __        
       _T      .,,.    ~--~ ^^  
 ^^   // \                    ~ 
      ][O]    ^^      ,-~ ~     
   /''-I_I         _II____      
__/_  /   \ ______/ ''   /'\_,__
  | II--'''' \,--:--..,_/,.-{ },
; '/__\,.--';|   |[] .-.| O{ _ }
:' |  | []  -|   ''--:.;[,.'\,/ 
'  |[]|,.--'' '',   ''-,.    |  
  ..    ..-''    ;       ''. '  
    )";

  std::cout << vila;

  narrativePrint("Vorstag", "A morte nao e' fim... e' libertacao.");

  int escolha_cap1 = fazerEscolha("Os gritos dos inocentes cortam o ar, mas os suprimentos em sua mao podem garantir sua sobrevivencia. O que voce prioriza?",
                                  {"Salvar os Civis",
                                   "Proteger Recursos"});
  if (escolha_cap1 == 1)
  {
    narrativePrint("Narrador", "Voce guia os sobreviventes para um celeiro, ganhando sua lealdade, mas perde recursos valiosos.");
    jogador->adicionarMoral(5);
  }
  else
  {
    narrativePrint("Narrador", "Voce guarda os suprimentos, mas os gritos dos abandonados ecoarao em sua mente.");
    jogador->ganharOuro(20);
    jogador->adicionarMoral(-5);
  }

  narrativePrint("Narrador", "Os infectados pela peste se arrastam em sua direcao!");
  std::vector<std::unique_ptr<Inimigo>> inimigos_c1;
  inimigos_c1.emplace_back(std::make_unique<Zumbi>());

  inimigos_c1.emplace_back(std::make_unique<Esqueleto>());

  lutar(*jogador, inimigos_c1);

  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Narrador", "Um vampiro degenerado, um lorde caido, bloqueia seu caminho.");
  std::vector<std::unique_ptr<Inimigo>> miniboss_c1;
  miniboss_c1.emplace_back(std::make_unique<Vampiro>());

  lutar(*jogador, miniboss_c1);

  // arte batalha

  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Vorstag", "Pobrezinho... Ainda acredita em esperanca? Eu sou a cura para este mundo podre.");
  std::vector<std::unique_ptr<Inimigo>> boss_c1;
  boss_c1.emplace_back(std::make_unique<CavaleiroDaPeste>());
  lutar(*jogador, boss_c1);

  if (!jogador->estaVivo())
  {
    narrativePrint("Roland",
                   "Levante-se, heroi. Ainda nao e' sua hora.");
    jogador->setVida(jogador->getVidaMax() * 0.8);
    std::vector<std::unique_ptr<Inimigo>> retry;
    retry.emplace_back(std::make_unique<CavaleiroDaPeste>());
    lutar(*jogador, retry);
    if (!jogador->estaVivo())
      return 0;
  }

  narrativePrint("Vorstag", "Nao e' o fim... Eles virao... todos virao... HAHAHA!");
  musica.StopMusic();

  jogador->ganharOuro(500);
  jogador->visitarLoja(1);

  narrativePrint("Narrador", "Capitulo 2: O Banquete da Fome.");

  musica.PlayMusic("musicas/CAP2.wav");
  narrativePrint("Narrador", "Com a Peste derrotada, a fome rasteja pelas terras, e sua sombra engole tudo.");

  int caminho_c2 = fazerEscolha("Dois caminhos se abrem. Qual voce seguira?", {"A Floresta Sombria", "As Montanhas Rochosas"});
  std::vector<std::unique_ptr<Inimigo>> inimigos_c2;
  if (caminho_c2 == 1)
  {
    narrativePrint("Narrador", "Voce adentra a Floresta Sombria, lar de aranhas e lobisomens.");
    inimigos_c2.emplace_back(std::make_unique<Aranha>());

    // arte aranha

    inimigos_c2.emplace_back(std::make_unique<Lobisomem>());

    // arte lobisomen
  }
  else
  {
    narrativePrint("Narrador", "Voce escala as Montanhas Rochosas, infestadas de slimes e goblins.");

    // arte montanhas
    std::string montanhas = R"(
            .                  .-.    .  _   *     _   .
           *          /   \     ((       _/ \       *    .
         _    .   .--'\/\_ \     `      /    \  *    ___
     *  / \_    _/ ^      \/\'__        /\/\  /\  __/   \ *
       /    \  /    .'   _/  /  \  *' /    \/  \/ .`'\_/\   .
  .   /\/\  /\/ :' __  ^/  ^/    `--./.'  ^  `-.\ _    _:\ _
     /    \/  \  _/  \-' __/.' ^ _   \_   .'\   _/ \ .  __/ \
   /\  .-   `. \/     \ / -.   _/ \ -. `_/   \ /    `._/  ^  \
  /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.
@/        `.  / /      `-.   /  .-'   / .   .'   \    \  \  .-  \%
@&8jgs@@%% @)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&8(8%@%8)(8@%8 8%@)%
@88:::&(&8&&8:::::%&`.~-_~~-~~_~-~_~-~~=.'@(&%::::%@8&8)::&#@8::::
`::::::8%@@%:::::@%&8:`.=~~-.~~-.~~=..~'8::::::::&@8:::::&8:::::'
 `::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.
        )";

    std::cout << montanhas;

    inimigos_c2.emplace_back(std::make_unique<Slime>());

    // arte slime

    inimigos_c2.emplace_back(std::make_unique<Goblin>());

    // arte goblin
  };
  lutar(*jogador, inimigos_c2);
  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Narrador", "Um goblin devoto, fanatico por seu mestre, tenta impedi-lo.");
  std::vector<std::unique_ptr<Inimigo>> miniboss_c2;
  miniboss_c2.emplace_back(std::make_unique<Goblin>());

  // arte goblin

  lutar(*jogador, miniboss_c2);

  // arte batalha

  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Seraphina", "Comam... ou sejam comidos. Nao ha outro caminho.");
  std::vector<std::unique_ptr<Inimigo>> boss_c2;
  boss_c2.emplace_back(std::make_unique<CavaleiroDaFome>());
  lutar(*jogador, boss_c2);

  // arte batalha

  if (!jogador->estaVivo()

  )
    return 0;

  narrativePrint("Seraphina", "A fome... nunca acaba... ela apenas espera...");
  musica.StopMusic();
  jogador->ganharOuro(750);
  jogador->visitarLoja(2);

  narrativePrint("Narrador", "Capitulo 3: A Forja da Guerra.");
  musica.PlayMusic("musicas/CAP3.wav");
  narrativePrint("Narrador", "O trovao da Guerra ecoa nas planicies. Thargon marcha com seu exercito.");

  int escolha_c3 = fazerEscolha("Voce encontra uma fortaleza rebelde. O que voce faz?",
                                {"Ajudar os Rebeldes",
                                 "Invadir o acampamento sozinho"});
  if (escolha_c3 == 1)
    jogador->adicionarMoral(5);
  else
  {
    jogador->adicionarMoral(-5);
    jogador->ganharOuro(50);
  }

  narrativePrint("Narrador", "As maquinas de guerra de Thargon avancam: Slimes Corrosivos e Goblins Guerreiros.");
  std::vector<std::unique_ptr<Inimigo>> inimigos_c3;
  inimigos_c3.emplace_back(std::make_unique<Slime>());

  // arte slime

  inimigos_c3.emplace_back(std::make_unique<Goblin>());

  // arte goblin

  lutar(*jogador, inimigos_c3);

  // arte batalha

  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Thargon", "Voces chamam isso de luta? Eu sou a guerra encarnada!");
  std::vector<std::unique_ptr<Inimigo>> boss_c3;
  boss_c3.emplace_back(std::make_unique<CavaleiroDaGuerra>());
  lutar(*jogador, boss_c3);

  // arte batalha

  if (!jogador->estaVivo())
    return 0;

  narrativePrint("Thargon", "A guerra... nunca termina... apenas muda de rosto...");
  musica.StopMusic();
  jogador->ganharOuro(1000);
  jogador->visitarLoja(3);

  narrativePrint("Narrador", "Capitulo 4: O Veu da Morte.");
  musica.PlayMusic("musicas/CAP4.wav");

  narrativePrint("Narrador", "Tres Cavaleiros cairam. A Morte aguarda no coracao da fenda. E ao seu lado... Nyx.");
  narrativePrint("Nyx", "Voce chegou longe, heroi. Junte-se a mim... ou pereca.");

  int escolha_c4_nyx = fazerEscolha("Nyx oferece poder, mas a um custo. Qual seu caminho?",
                                    {"Aliar-se a Nyx",
                                     "Combater Nyx"});
  if (escolha_c4_nyx == 1)
  {
    jogador->setAliadoNyx(true);
    jogador->adicionarMoral(-10);
  }
  else
  {
    jogador->adicionarMoral(10);
    std::vector<std::unique_ptr<Inimigo>> miniboss_nyx;
    miniboss_nyx.emplace_back(std::make_unique<Bruxa>());

    lutar(*jogador, miniboss_nyx);

    if (!jogador->estaVivo())
      return 0;
  }

  narrativePrint("Moros", "...");
  std::vector<std::unique_ptr<Inimigo>> boss_c4;
  boss_c4.emplace_back(std::make_unique<CavaleiroDaMorte>());
  lutar(*jogador, boss_c4);
  if (!jogador->estaVivo())
    return 0;

  int moralFinal = jogador->getMoral();
  bool aliadoNyx = jogador->temAliadoNyx();

  musica.StopMusic();
  std::string final;

  if (aliadoNyx)
    final = "sombrio";
  else if (moralFinal > 10)
    final = "heroico";
  else
    final = "tragico";

  mostrarFinal(classeJogador, final);

  narrativePrint("Narrador", "OBRIGADO POR JOGAR!");
  return 0;
}
