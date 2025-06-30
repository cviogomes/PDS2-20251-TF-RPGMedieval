#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"
#include "Efeitos.hpp"
#include <string>
#include <vector>
#include <memory>
#include <sstream>

class Jogador : public Personagem {
    public:
        Jogador (const std::string& nome, int vidaMax, int ataque, int defesa);
        void ganharOuro(int quantidade);
        void investirOuro(int quantidade);
        void retornarInvestimento();
        void visitarLoja(int capitulo);

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
        void reduzirAtaque(int valor);
        void setDefesa(int defesa);

        std::string getClasse() const;

    private:
        int ouro_;
        std::string classe_;
        double investimento_;
        int pocoes_;
        int moral_;
        bool aliadoNyx_;
        Efeito efeito_;

};

#endif // JOGADOR_HPP
