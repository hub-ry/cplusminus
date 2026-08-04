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
    int travel(TreeNode* root, char dir, int curr, int &max) {
        if (!root) {
            return max;
        }

        if (curr > max) max = curr;

        travel(root->right, 'r', (dir == 'l') ? curr + 1 : 1 ,max);
        travel(root->left, 'l', (dir == 'r') ? curr + 1 : 1, max);

        return max;
    }
    int longestZigZag(TreeNode* root) {
        char dir = 'm';
        int max = 0;
        int curr = 0;
        int ret = travel(root, dir, curr, max);

        return ret;
    }
};