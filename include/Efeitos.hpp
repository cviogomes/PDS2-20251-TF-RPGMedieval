#ifndef EFEITOS_HPP
#define EFEITOS_HPP

#include <string>

enum class TipoEfeito {
    Nenhum,
    Veneno,
    Paralisia,
    Maldição
};

struct Efeito {
    TipoEfeito tipo = TipoEfeito::Nenhum;
    int duracao = 0;
};

#endif