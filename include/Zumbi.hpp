#ifndef ZUMBI_HPP
#define ZUMBI_HPP

#include "Inimigo.hpp"
#include <iostream>
#include <memory>

class Zumbi : public Inimigo {
public:
    Zumbi() : Inimigo("Zumbi", 100, 12, 5), curou_(false) {}

    void aoReceberDano(int danoRecebido) override {
        if (!curou_ && vida_ < vidaMax_ * 0.3) {
            vida_ = vidaMax_;
            curou_ = true;
            std::cout << nome_ << " se autocanibalizou e recuperou a vida para "
                      << vida_ << "/" << vidaMax_ << " de vida!\n";
        }
    }

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Zumbi>(*this);
    }

private:
    bool curou_;
};

#endif // ZUMBI_HPP
