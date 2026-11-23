/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* travel(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (root == p || root == q) return root;

        TreeNode* right = travel(root->right, p, q);
        TreeNode* left = travel(root->left, p, q);
        
        if (left && right) return root;

        if (!right) {
            return left;
        }
        
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = travel(root, p, q);
        return ret;
    }
};