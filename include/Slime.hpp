#ifndef SLIME_HPP
#define SLIME_HPP

#include "Inimigo.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Slime : public Inimigo {
public:
    Slime() : Inimigo("Slime", 40, 10, 2) {}

    // A lógica de divisão é complexa de implementar no loop de combate atual.
    // Esta mensagem serve como um efeito narrativo.
    void aoReceberDano(int) override {
        if (vida_ <= 0) {
            battlePrint("Ao ser derrotado, o Slime se dissolve em uma poca gosmenta.\n");
        }
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Slime>(*this);
    }
};
#endif