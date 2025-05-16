#include "smartNode.hpp"
#include <algorithm>

std::unique_ptr<SmartNode> create_smart_node(int value) {
    return std::make_unique<SmartNode>(SmartNode{value});
}

bool SmartNode::is_leaf() const {
    return !left && !right;
}

void SmartNode::insert(int value) {
    if (value < this->value) {
        if (!left) {
            left = create_smart_node(value);
        } else {
            left->insert(value);
        }
    } else {
        if (!right) {
            right = create_smart_node(value);
        } else {
            right->insert(value);
        }
    }
}

size_t SmartNode::height() const {
    size_t left_height = left ? left->height() : 0;
    size_t right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

int SmartNode::min() const {
    return left ? left->min() : value;
}

int SmartNode::max() const {
    return right ? right->max() : value;
}

std::unique_ptr<SmartNode>& SmartNode::most_left(std::unique_ptr<SmartNode>& node) {
    return node->left ? most_left(node->left) : node;
}

bool remove(std::unique_ptr<SmartNode>& node, int value) {
    if (!node) return false;
    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        if (node->is_leaf()) {
            node.reset();
        } else if (node->left && !node->right) {
            node = std::move(node->left);
        } else if (!node->left && node->right) {
            node = std::move(node->right);
        } else {
            std::unique_ptr<SmartNode>& successor = SmartNode::most_left(node->right);
            node->value = successor->value;
            remove(successor, successor->value);
        }
        return true;
    }
}
