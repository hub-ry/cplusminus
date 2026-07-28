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
    void runner(TreeNode* root, int max, int* tally) {
        if (!root) {
            return;
        }

        if (root->val >= max) {
            (*tally)++;
            max = root->val;
        }

        runner(root->left, max, tally);
        runner(root->right, max, tally);

    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int max = root->val;
        int tally = 0;
        
        runner(root, max, &tally);

        return tally;
    }
};