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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> x;
        std::vector<int> lvls;

        if (!root) return {};
        x.push(root);
        while (x.size()) {
            int levelSize = x.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = x.front();
                x.pop();

                if (i == levelSize - 1) lvls.push_back(node->val);
                if (node->left) x.push(node->left);
                if (node->right) x.push(node->right);
            }
        }

        return lvls;
    }
};