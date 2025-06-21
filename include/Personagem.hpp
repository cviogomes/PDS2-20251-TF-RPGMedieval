#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <vector>
#include <memory>

class Personagem {
public:
    Personagem(const std::string& nome, int vidaMax, int ataque, int defesa);
    virtual ~Personagem() = default;
    virtual void atacar(Personagem& alvo);
    virtual void defender();
    void restaurarVida();

    bool estaVivo() const;

    const std::string& getNome() const;
    int getVida() const;
    int getVidaMax() const;

    int getAtaque() const;
    int getDefesa() const;

protected:
    std::string nome_;
    int vida_;
    int vidaMax_;
    int ataque_;
    int defesa_;
    
};



#endif // PERSONAGEM_HPP
