#include "node.hpp"

int main() {
    Node* root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);

    std::cout << "Tree (ASCII):" << std::endl;
    pretty_print_left_right(*root);

    std::cout << "\nInfix order: ";
    root->display_infix();
    std::cout << std::endl;

    std::cout << "\nHeight: " << root->height() << std::endl;

    std::cout << "\nRemoving 7..." << std::endl;
    remove(root, 7);
    pretty_print_left_right(*root);

    delete_tree(root);
    return 0;
}