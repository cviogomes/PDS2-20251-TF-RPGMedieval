#ifndef ESQUELETO_HPP
#define ESQUELETO_HPP

#include "Inimigo.hpp"

class Esqueleto : public Inimigo {
    public:
        Esqueleto() : Inimigo("Esqueleto", 50, 15, 3) {}
};

#endif // ESQUELETO_HPP
