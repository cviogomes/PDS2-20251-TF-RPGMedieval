#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "Jogador.hpp"
#include "Personagem.hpp"

void lutar(Jogador& jogador, std::vector<std::unique_ptr<Inimigo>> inimigos);

#endif // COMBATE_HPP
