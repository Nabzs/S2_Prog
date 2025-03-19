#ifndef NPI_TOKEN_HPP
#define NPI_TOKEN_HPP

#include <vector>
#include <string>

// Définition de l'énumération des opérateurs
enum class Operator { ADD, SUB, MUL, DIV };

// Définition de l'énumération du type de Token
enum class TokenType { OPERATOR, OPERAND };

// Structure représentant un Token
struct Token {
    TokenType type;
    float value;  // Utilisé si c'est un opérande
    Operator op;  // Utilisé si c'est un opérateur
};

// Fonctions pour créer des tokens
Token make_token(float value);
Token make_token(Operator op);

// Fonction pour transformer une chaîne de caractères en un vecteur de tokens
std::vector<Token> tokenize(const std::vector<std::string>& words);

#endif // NPI_TOKEN_HPP
