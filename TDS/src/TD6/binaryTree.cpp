#include "binaryTree.hpp"

void BinaryTree::insert(int value) {
    if (!root) {
        root = create_smart_node(value);
    } else {
        root->insert(value);
    }
}

bool BinaryTree::remove(int value) {
    return ::remove(root, value);
}

void BinaryTree::clear() {
    root.reset();
}

static bool contains_helper(const std::unique_ptr<SmartNode>& node, int value) {
    if (!node) return false;
    if (value == node->value) return true;
    if (value < node->value) return contains_helper(node->left, value);
    return contains_helper(node->right, value);
}

bool BinaryTree::contains(int value) const {
    return contains_helper(root, value);
}

size_t BinaryTree::height() const {
    return root ? root->height() : 0;
}
