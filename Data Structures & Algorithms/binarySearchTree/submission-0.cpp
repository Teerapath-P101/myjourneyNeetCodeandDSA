class TreeNode {
    public:
      int key;
      int value;
      TreeNode *left;
      TreeNode *right;

    TreeNode(int key, int val) 
      :key(key), value(val), left(nullptr), right(nullptr) {}
};

class TreeMap {

public:
private:
    TreeNode *root;

    void inorderTraversal(TreeNode *root, vector<int>&result) {
        if (root == nullptr) return;

        inorderTraversal(root->left, result);
        result.push_back(root->key);
        inorderTraversal(root->right, result);
    }

    TreeNode *findMin(TreeNode *node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode *removeHelper(TreeNode *curr, int key) {
        if (curr == nullptr) return nullptr;

        if (key > curr->key) curr->right = removeHelper(curr->right, key); //4 re 
        else if (key < curr->key) curr->left = removeHelper(curr->left, key); 
        else {
            if (curr->left == nullptr) return curr->right;
            else if (curr->right == nullptr) return curr->left;
            else { // 8
                // swap curr with inorder successor
                TreeNode *minNode = findMin(curr->right);
                curr->key = minNode->key;
                curr->value = minNode->value;
                curr->right = removeHelper(curr->right, minNode->key); // 10 re 11
            }
        }
        return curr;
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode *newNode = new TreeNode(key, val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode *curr = root;
        while (true) {
            if (key > curr->key) {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
            else if (key < curr->key) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else {
                curr->value = val;
                return;
            }
        }
    }

    int get(int key) {
        TreeNode *curr = root;
        while (curr) {
            if (key > curr->key) {
                curr = curr->right;
            } else if (key < curr->key) {
                curr = curr->left;
            } else {
                return curr->value;
            }
        }
        return -1;
    }

    int getMin() {
        TreeNode *curr = findMin(root);
        return (curr != nullptr) ? curr->value : -1; // two ways if else in C++
    }

    int getMax() {
        TreeNode *curr = root;
        while (curr != nullptr && curr->right != nullptr) { 
            curr = curr->right;
        }
        if (curr != nullptr) return curr->value;
        else return -1;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> result = {};
        inorderTraversal(root, result);
        return result;
    }
};
