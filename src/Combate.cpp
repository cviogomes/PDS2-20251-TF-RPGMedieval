#include "Combate.hpp"
#include "Utils.hpp"
#include "AsciiArt.hpp"
#include <iostream>
#include <limits>
#include <vector>

// Esta é a nova e aprimorada função lutar.
// Ela usa um loop 'while' para poder adicionar novos inimigos (como os Slimes divididos) no meio do combate.
void lutar(Jogador &jogador, std::vector<std::unique_ptr<Inimigo>> &inimigos)
{

  // O loop continua enquanto houver inimigos na lista e o jogador estiver vivo.
  while (!inimigos.empty() && jogador.estaVivo())
  {

    // Pega o primeiro inimigo da fila para o combate atual.
    auto &inimigo = inimigos.front();

    // Mostra o nome e a arte ASCII do inimigo que apareceu.
    battlePrint("\n" + inimigo->getNome() + " apareceu!\n");
    mostrarArte(inimigo->getNome());

    // Loop de combate para o inimigo atual
    while (jogador.estaVivo() && inimigo->estaVivo())
    {
      std::cout << "\n";
      battlePrint("Vida: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + " | Pocoes: " + std::to_string(jogador.getPocoes()) + "\n");
      battlePrint("Inimigo: " + inimigo->getNome() + " | Vida: " + std::to_string(inimigo->getVida()) + "/" + std::to_string(inimigo->getVidaMax()) + "\n");

      jogador.processarEfeitos();
      if (!jogador.estaVivo())
        break;

      if (jogador.getEfeito().tipo != TipoEfeito::Paralisia)
      {
        typeText("Escolha uma acao:\n1 - Atacar\n2 - Defender\n3 - Usar Pocao\nOpcao: ", TextSpeed::NORMAL);
        int acao;
        std::cin >> acao;

        switch (acao)
        {
        case 1:
          jogador.atacar(*inimigo);
          inimigo->aoReceberDano(jogador.getAtaque());
          break;
        case 2:
          jogador.defender();
          break;
        case 3:
          jogador.usarPocao();
          break;
        default:
          battlePrint("Acao invalida. Voce perdeu o turno!\n");
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          break;
        }
      }

      // A lógica de ataque do inimigo é controlada por aoAtacar() para suportar a reflexão de dano.
      if (inimigo->estaVivo())
      {
        // 1. Executa a habilidade especial (ex: refletir dano, roubar ouro).
        inimigo->aoAtacar(jogador);

        // 2. Executa o ataque de dano normal, a menos que a habilidade já o tenha substituído.
        if (!inimigo->habilidadeSubstituiAtaque())
        {
          inimigo->atacar(jogador);
        }
      }
    }

    // Após o loop de combate, verifica se o inimigo morreu.
    if (!inimigo->estaVivo())
    {
      battlePrint(inimigo->getNome() + " foi derrotado!\n");

      // >>> AQUI ESTÁ A NOVA LÓGICA DE SPAWN <<<
      // Pede ao inimigo a lista de novos monstros que ele gera ao morrer.
      auto novosInimigos = inimigo->onDeathSpawn();

      // Remove o inimigo morto da frente da fila.
      inimigos.erase(inimigos.begin());

      // Se a lista de novos inimigos não estiver vazia, adiciona eles no início da fila de combate.
      if (!novosInimigos.empty())
      {
        inimigos.insert(inimigos.begin(), std::make_move_iterator(novosInimigos.begin()), std::make_move_iterator(novosInimigos.end()));
      }
    }

    if (!jogador.estaVivo())
    {
      break; // Sai do loop principal se o jogador morreu.
    }
  }
}
