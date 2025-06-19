#ifndef LOBISOMEM_HPP
#define LOBISOMEM_HPP

#include "Inimigo.hpp"
#include <iostream>

class Lobisomem : public Inimigo {
    public:
    Lobisomem() : Inimigo("Lobisomem", 90, 20, 6), transformado_(false) {}

    void aoReceberDano(int) override {
        if (!transformado_ && vida_ < vidaMax_ * 0.3) {
            ataque_ *= 2;
            std::cout << nome_ << " se enfurece! Ataque dobrado para " << ataque_ << "!\n";
            transformado_ = true;
        }
    }

    private:
    bool transformado_;
};

#endif