#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "Jogador.hpp"
#include "Inimigo.hpp"
#include <vector>
#include <memory>

void lutar(Jogador &jogador, std::vector<std::unique_ptr<Inimigo>> &inimigos);

#endif // COMBATE_HPP