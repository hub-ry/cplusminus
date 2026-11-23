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
    void collect(TreeNode* node, std::vector<int>& result) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            result.push_back(node->val);
            return;
        }
        collect(node->left, result);
        collect(node->right, result);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> one, two;
        collect(root1, one);
        collect(root2, two);
        return one == two;
       


    }
};