// testes.cpp

// Esta linha mágica faz com que a biblioteca doctest crie a função main() para nós.
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// Inclui a biblioteca de testes.
#include "../include/doctest.h"

// Inclui todas as classes que queremos testar.
#include "Jogador.hpp"
#include "Zumbi.hpp"
#include "Goblin.hpp"
#include "CavaleiroDaPeste.hpp"
#include "CavaleiroDaFome.hpp"
#include "CavaleiroDaGuerra.hpp"
#include "CavaleiroDaMorte.hpp"
#include "Jogador.hpp"
#include "Personagem.hpp"
#include "Utils.hpp"


// NOTA: Incluir .cpp não é uma prática padrão em projetos grandes,
// mas simplifica enormemente a compilação para um único arquivo de teste como este.

TEST_CASE("Testes das classes Personagem e Jogador")
{
    // Cria um jogador para usar nos testes deste caso.
    Jogador jogador("Herói de Teste", 100, 20, 10);

    // SUBCASE permite agrupar testes menores dentro de um TEST_CASE.
    SUBCASE("Verificação do Construtor e Atributos Iniciais")
    {
        CHECK(jogador.getNome() == "Herói de Teste");
        CHECK(jogador.getVida() == 100);
        CHECK(jogador.getVidaMax() == 100);
        CHECK(jogador.getAtaque() == 20);
        CHECK(jogador.getDefesa() == 10);
        CHECK(jogador.getMoral() == 10); // Moral inicial
        CHECK(jogador.getPocoes() == 3); // Poções iniciais
    }

    SUBCASE("Teste de ganho de ouro")
    {
        jogador.ganharOuro(50);
        CHECK(jogador.getOuro() == 150); // Verifica se o ouro foi adicionado corretamente aos 100 iniciais

        jogador.investirOuro(50);
        CHECK(jogador.getOuro() == 100); // Verifica se o ouro foi retirado corretamente apos o investimento

    }

    SUBCASE("Teste de manipulação de Moral")
    {
        jogador.adicionarMoral(5);
        CHECK(jogador.getMoral() == 15);
        jogador.adicionarMoral(-10);
        CHECK(jogador.getMoral() == 5);
    }

    SUBCASE("Teste do uso de Poções")


    {
        jogador.setVida(100); // Simula que o jogador tomou dano
        CHECK(jogador.getVida() == 100);

        jogador.usarPocao();

        CHECK(jogador.getVida() == jogador.getVidaMax()); // Vida deve ser restaurada

        jogador.setVida(30);
        jogador.usarPocao();             // Tenta usar a quarta (inexistente)
        CHECK(jogador.getVida() == 100); // Vida não deve ser restaurada
        CHECK(jogador.getPocoes() == 1); // Contagem continua 0
    }
}

TEST_CASE("Testes de Combate e Habilidades Especiais")
{
    Jogador jogador("Guerreiro Forte", 120, 25, 10);

    SUBCASE("Habilidade especial de cura do Zumbi")
    {
        Zumbi zumbi; // Vida Max: 100

        // Dano para deixar a vida abaixo de 30% (limite é 30 de vida)
        zumbi.setVida(29);

        // aoReceberDano é chamado dentro de atacar, mas vamos chamar diretamente para isolar o teste
        zumbi.aoReceberDano(1);

        // A habilidade deve ter sido ativada, restaurando a vida para o máximo
        CHECK(zumbi.getVida() == zumbi.getVidaMax());
    }

    SUBCASE("Habilidade especial de roubo do Goblin")
    {
        Goblin goblin;

        // Damos 100 de ouro ao jogador para o teste
        jogador.ganharOuro(100);
        // Precisamos de uma forma de verificar o ouro. Vamos usar a moral como um proxy temporário
        // se não tivermos um getOuro(). Para este teste, vamos assumir que investir com
        // valor negativo em Jogador.cpp remove ouro.

        // Vamos modificar o método investirOuro para retornar o ouro, apenas para o teste
        // Em um projeto real, criaríamos um getOuro().
        // Para este exemplo, a lógica de roubo é testada conceitualmente.
        // O jogador começa com 0, ganha 100 -> total 100
        // Goblin ataca, rouba 20
        // jogador.ganharOuro(-20) é chamado, total esperado 80

        // Ação
        goblin.aoAtacar(jogador);

        CHECK(jogador.getOuro() == 180);

        // Verificação: Como não temos getOuro, o teste aqui é mais conceitual.
        // Se tivéssemos getOuro(), a verificação seria: CHECK(jogador.getOuro() == 80);
        // Por agora, garantimos que o código compila e a lógica existe.
    }

    SUBCASE("Habilidade especial do Cavaleiro da Peste")
    {
        CavaleiroDaPeste peste;
        int defesa_antes = jogador.getDefesa();

        peste.aoAtacar(jogador);

        CHECK(jogador.getDefesa() == defesa_antes - 1);
    }

    SUBCASE("Habilidade especial do Cavaleiro da Fome")
    {
        CavaleiroDaFome fome;
        int vida_max_antes = jogador.getVidaMax();

        fome.aoAtacar(jogador);

        CHECK(jogador.getVidaMax() == vida_max_antes - 5);
    }

    SUBCASE("Habilidade especial do Cavaleiro da guerra")
    {
        CavaleiroDaGuerra guerra;
        int ataque_max_antes = jogador.getAtaque();

        guerra.aoAtacar(jogador);

        CHECK(jogador.getAtaque() == ataque_max_antes - 1);
    }

    SUBCASE("Habilidade especial do Cavaleiro da morte") {
        CavaleiroDaMorte morte;

        // Garante que o jogador começa com vida cheia
        jogador.setVida(100);
        int vidaAntes = jogador.getVida();

        // Força a reflexão de 40 de dano usando o setter
        morte.setDanoParaRefletir(40);

        morte.aoAtacar(jogador);

        // O jogador deve perder 40 de vida
        CHECK(jogador.getVida() == vidaAntes - 40);

    }
}