#ifndef SLIME_HPP
#define SLIME_HPP

#include "Inimigo.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Slime : public Inimigo
{
public:
    // Construtor padrão para os slimes originais que aparecem no mapa.
    // Eles podem se dividir.
    Slime() : Inimigo("Slime", 40, 10, 2), podeDividir_(true) {}

    // Sobrescreve a função de spawn da classe base.
    std::vector<std::unique_ptr<Inimigo>> onDeathSpawn() override
    {
        // A divisão SÓ acontece se a flag 'podeDividir_' for verdadeira.
        if (podeDividir_)
        {
            battlePrint("Ao ser derrotado, o " + nome_ + " se divide em dois Slimes menores!\n");

            std::vector<std::unique_ptr<Inimigo>> novosSlimes;
            // Cria dois novos slimes usando o construtor privado, que os impede de se dividirem novamente.
            novosSlimes.push_back(std::make_unique<Slime>(false));
            novosSlimes.push_back(std::make_unique<Slime>(false));

            return novosSlimes;
        }

        // Se 'podeDividir_' for falso, ele simplesmente morre e não retorna nada.
        return {};
    }

    std::unique_ptr<Inimigo> clone() const override
    {

        return std::make_unique<Slime>();
    }

    Slime(bool podeDividir) : Inimigo("Slime Menor", 20, 8, 1), podeDividir_(podeDividir) {}

private:
    bool podeDividir_; // Flag que controla a habilidade de divisão.
};
#endif