#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"
#include "Efeitos.hpp"
#include <string>
#include <vector>
#include <memory>

class Jogador : public Personagem {
    public:
        Jogador (const std::string& nome, int vidaMax, int ataque, int defesa);
        void ganharOuro(int quantidade);
        void investirOuro(int quantidade);
        void retornarInvestimento();
        void visitarLoja();

        int getPocoes() const;
        void usarPocao();

        void aplicarEfeito(const Efeito& efeito);
        void processarEfeitos();
        Efeito getEfeito() const;

        void setVidaMax(int novaVidaMax);

        void reduzirAtaque(int valor) {
        ataque_ -= valor;
        if (ataque_ < 0) ataque_ = 0;
        }

        void setDefesa(int defesa) { defesa_ = defesa; }
        void adicionarMoral(int valor);
        int getMoral() const;
    private:
        Efeito efeito_;
        int ouro_;
        int pocoes_;
        double investimento_;
        int moral_;
};

#endif // JOGADOR_HPP
