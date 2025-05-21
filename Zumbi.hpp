#ifndef ZUMBI_HPP
#define ZUMBI_HPP

#include "Inimigo.hpp"
#include <iostream>

class Zumbi : public Inimigo {
    public:
        Zumbi() : Inimigo("Zumbi", 100, 12, 5) {}

        void aoReceberDano(int danoRecebido) override {
            //apos levar dano, se a vida cair abaixo de 30%, recupera tudo
            if (vida_ < vidaMax_ * 0.3) {
                vida_ = vidaMax_;
                std::cout << nome_ << " se autocanibalizou e recuperou a vida para " << vida_ << "/" << vidaMax_ << " de vida!\n";
            }
        }
};

#endif // ZUMBI_HPP