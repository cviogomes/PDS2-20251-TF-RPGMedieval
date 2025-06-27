#ifndef LOBISOMEM_HPP
#define LOBISOMEM_HPP

#include "Inimigo.hpp"
#include "Utils.hpp"
#include <iostream>
#include <memory>

class Lobisomem : public Inimigo {
public:
    Lobisomem() : Inimigo("Lobisomem", 90, 20, 6), transformado_(false) {}

    void aoReceberDano(int) override {
        if (!transformado_ && vida_ < vidaMax_ * 0.3) {
            ataque_ *= 2;
            battlePrint(nome_ + " se enfurece! Ataque dobrado para " + std::to_string(ataque_) + "!\n");
            transformado_ = true;
        }
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Lobisomem>(*this);
    }
private:
    bool transformado_;
};
#endif