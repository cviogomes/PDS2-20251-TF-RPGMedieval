#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"
#include <string>

class Jogador : public Personagem {
    public:
        Jogador (const std::string& nome, int vidaMax, int ataque, int defesa);
        void mostrarOuro() const;
        void ganharOuro(int quantidade);
        void investirOuro(int quantidade);
        void retornarInvestimento();
        void visitarLoja();

        int getPocoes() const;
        void usarPocao();


    private:
        int ouro_;
        int pocoes_;
        double investimento_;
};

#endif // JOGADOR_HPP
