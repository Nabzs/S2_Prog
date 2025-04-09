#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

// Structure représentant un nœud d'un arbre binaire
struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    // Méthodes
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const*> prefix() const;
    std::vector<Node const*> postfix() const;
};

// Fonctions globales
Node* create_node(int value);
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);

#endif // NODE_HPP