#include "node.hpp"
#include <stack>

// Crée un nœud avec une valeur donnée
Node* create_node(int value) {
    return new Node{value};
}

// Vérifie si le nœud est une feuille
bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

// Insère une valeur dans l'arbre binaire
void Node::insert(int value) {
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

// Calcule la hauteur de l'arbre
int Node::height() const {
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

// Supprime les fils d'un nœud
void Node::delete_children() {
    if (left) {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

// Affiche les valeurs des nœuds en ordre infixe
void Node::display_infix() const {
    if (left) {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right) {
        right->display_infix();
    }
}

// Parcours en préfixe
std::vector<Node const*> Node::prefix() const {
    std::vector<Node const*> nodes {this};
    if (left) {
        auto left_nodes = left->prefix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        auto right_nodes = right->prefix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

// Parcours en postfixe
std::vector<Node const*> Node::postfix() const {
    std::vector<Node const*> nodes {};
    if (left) {
        auto left_nodes = left->postfix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        auto right_nodes = right->postfix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    nodes.push_back(this);
    return nodes;
}

// Trouve le nœud le plus à gauche
Node*& most_left(Node*& node) {
    return node->left ? most_left(node->left) : node;
}

// Supprime une valeur de l'arbre
bool remove(Node*& node, int value) {
    if (!node) return false;

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
        } else if (node->left && !node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else if (!node->left && node->right) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else {
            Node*& successor = most_left(node->right);
            node->value = successor->value;
            remove(successor, successor->value);
        }
        return true;
    }
}

// Supprime tout l'arbre
void delete_tree(Node* node) {
    if (node) {
        node->delete_children();
        delete node;
    }
}

// Affiche l'arbre en ASCII
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}