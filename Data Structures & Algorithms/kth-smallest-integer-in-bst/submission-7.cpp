/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Morris Traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        while(curr) {
            if (curr->left) {
                TreeNode* wayBack = curr->left; // Start making way back to the left's curr node
                while (wayBack->right && wayBack->right != curr) wayBack = wayBack->right;
                if (!wayBack->right) {
                    wayBack->right = curr;
                    curr = curr->left;
                } else {
                    wayBack->right = nullptr;
                    k--;
                    if (k == 0) return curr->val;
                    curr = curr->right;
                }
            } else { // Reach the kth smallest
                k--;
                if (k == 0) return curr->val;
                curr = curr->right;
            }
        }
        return -1;
    }
};