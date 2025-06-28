//MAIN ATUALIZADA
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
