#include <iostream>

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class Tree {
public:
    Tree() : root(nullptr) {}

    ~Tree() {
        clear(root);
    }

    void insert(T value) {
        if (root == nullptr) {
            root = new TreeNode<T>(value);
        }
        else {
            insertRecursive(root, value);
        }
    }

    void printInOrder() {
        printInOrderRecursive(root);
        std::cout << std::endl;
    }

private:
    TreeNode<T>* root;

    void insertRecursive(TreeNode<T>*& node, T value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
        }
        else {
            if (value < node->data) {
                insertRecursive(node->left, value);
            }
            else {
                insertRecursive(node->right, value);
            }
        }
    }

    void printInOrderRecursive(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        printInOrderRecursive(node->left);
        std::cout << node->data << " ";
        printInOrderRecursive(node->right);
    }

    void clear(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

int main() {
    Tree<double> tree;
    tree.insert(3.14);
    tree.insert(1.618);
    tree.insert(2.718);
    tree.insert(4.669);

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();

    return 0;
}

