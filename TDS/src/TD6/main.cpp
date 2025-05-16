#include "node.hpp"
#include "smartNode.hpp"
#include "binaryTree.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "Exercice 1 : Creation et affichage de l'arbre =====" << std::endl;
    Node *root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    std::cout << "Tree (ASCII):" << std::endl;
    pretty_print_left_right(*root);
    std::cout << std::endl;

    std::cout << "Exercice 2 : Affichages et operations =====" << std::endl;
    std::cout << "Infix order: ";
    root->display_infix();
    std::cout << std::endl;

    // BONUS : Affichage min et max
    Node *min_node = root;
    while (min_node && min_node->left)
        min_node = min_node->left;
    Node *max_node = root;
    while (max_node && max_node->right)
        max_node = max_node->right;
    std::cout << "Min value: " << (min_node ? min_node->value : -1) << std::endl;
    std::cout << "Max value: " << (max_node ? max_node->value : -1) << std::endl;

    // Somme des valeurs avec prefix
    auto nodes = root->prefix();
    int sum = 0;
    for (auto n : nodes)
        sum += n->value;
    std::cout << "Somme des valeurs (prefix): " << sum << std::endl;

    std::cout << "Hauteur de l'arbre: " << root->height() << std::endl;

    std::cout << "\nSuppression de 7..." << std::endl;
    remove(root, 7);
    pretty_print_left_right(*root);

    delete_tree(root);
    std::cout << std::endl;

    std::cout << "Exercice 3 : SmartNode (pointeurs intelligents)" << std::endl;
    auto smart_root = create_smart_node(5);
    smart_root->insert(3);
    smart_root->insert(7);
    smart_root->insert(2);
    smart_root->insert(4);
    smart_root->insert(6);
    smart_root->insert(8);
    smart_root->insert(1);
    smart_root->insert(9);
    smart_root->insert(0);
    std::cout << "Min value: " << smart_root->min() << std::endl;
    std::cout << "Max value: " << smart_root->max() << std::endl;
    std::cout << "Hauteur de l'arbre: " << smart_root->height() << std::endl;
    remove(smart_root, 7);
    std::cout << "Suppression de 7 (SmartNode)" << std::endl;
    std::cout << std::endl;

    std::cout << "Exercice 4 : BinaryTree (encapsulation)" << std::endl;
    BinaryTree tree;
    for (int v : {5, 3, 7, 2, 4, 6, 8, 1, 9, 0})
        tree.insert(v);
    std::cout << "Hauteur de l'arbre (BinaryTree): " << tree.height() << std::endl;
    std::cout << "Contient 6 ? " << (tree.contains(6) ? "Oui" : "Non") << std::endl;
    std::cout << "Suppression de 7 (BinaryTree)..." << std::endl;
    tree.remove(7);
    std::cout << "Suppression" << std::endl;
    tree.clear();
    std::cout << "Arbre vide" << std::endl;
    return 0;
}