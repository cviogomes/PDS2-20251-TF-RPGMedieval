#pragma once
#include <stdexcept>
#include <string>

/// Exceção para parâmetros inválidos em construtores ou funções.
class InvalidParameter : public std::invalid_argument {
public:
    InvalidParameter(const std::string& param, const std::string& reason)
        : std::invalid_argument("Parâmetro inválido [" + param + "]: " + reason) {}
};

/// Exceção para erros de entrada do usuário (ex: menu, escolha numérica inválida).
class InputError : public std::runtime_error {
public:
    explicit InputError(const std::string& mensagem)
        : std::runtime_error("Entrada inválida: " + mensagem) {}
};
