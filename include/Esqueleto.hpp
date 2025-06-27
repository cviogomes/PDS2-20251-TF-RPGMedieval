#ifndef ESQUELETO_HPP
#define ESQUELETO_HPP

#include "Inimigo.hpp"
#include <memory>

class Esqueleto : public Inimigo {
public:
    Esqueleto() : Inimigo("Esqueleto", 50, 15, 3) {}

    std::unique_ptr<Inimigo> clone() const override {
        return std::make_unique<Esqueleto>(*this);
    }
};
#endif