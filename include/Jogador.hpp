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
        void mostrarOuro() const;
        void ganharOuro(int quantidade);
        void investirOuro(int quantidade);
        void retornarInvestimento();
        void visitarLoja();

        int getPocoes() const;
        void usarPocao();

        void adicionarMoral(int valor);
        int getMoral() const;
        void setAliadoNyx(bool valor);
        bool temAliadoNyx() const;

        void aplicarEfeito(const Efeito& efeito);
        void processarEfeitos();
        Efeito getEfeito() const;

        void setVidaMax(int novaVidaMax);
        void setVida(int novaVida);

        int getAtaque() const;
        void reduzirAtaque(int valor) {
        ataque_ -= valor;
        if (ataque_ < 0) ataque_ = 0;
        }

        int getDefesa() const;
        void setDefesa(int defesa) { defesa_ = defesa; }

    private:
        Efeito efeito_;
        int ouro_;
        int pocoes_ = 3;
        double investimento_;
        int moral_ = 0;
        bool aliadoNyx_;
};

#endif // JOGADOR_HPP
