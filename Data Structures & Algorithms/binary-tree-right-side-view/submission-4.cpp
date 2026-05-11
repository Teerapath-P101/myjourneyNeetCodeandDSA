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

// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int qsize = q.size();
            for (int i=0; i<qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) res.push_back(node->val);
                if (node->right) q.emplace(node->right);
                if (node->left) q.emplace(node->left);
            }
        }
        return res;
    }
};
