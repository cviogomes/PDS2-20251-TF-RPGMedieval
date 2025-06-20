#ifndef SLIME_HPP
#define SLIME_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Slime : public Inimigo {
    public:
    Slime() : Inimigo("Slime", 40, 10, 2), dividido_(false) {}

    void aoReceberDano(int) override {
        if (!dividido_ && vida_ <= 0) {
            dividido_ = true;
            std::cout << "O Slime se divide em dois!\n";
            std::cout << "Prepare-se! Eles atacam mais forte e você só pode atingir um de cada vez.\n";

        }
    }

    std::unique_ptr<Inimigo> clone() const override {
    return std::make_unique<Slime>(*this);
    }


    private:
    bool dividido_;
};

#endif