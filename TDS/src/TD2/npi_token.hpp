#ifndef NPI_TOKEN_HPP
#define NPI_TOKEN_HPP

#include <vector>
#include <string>

// Définition de l'énumération des opérateurs
enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN };

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

// Fonction pour convertir une expression infixe en NPI
std::vector<Token> infix_to_npi_tokens(const std::string& expression);

// Fonction pour obtenir la priorité d'un opérateur
int operator_precedence(Operator const op);

#endif // NPI_TOKEN_HPP