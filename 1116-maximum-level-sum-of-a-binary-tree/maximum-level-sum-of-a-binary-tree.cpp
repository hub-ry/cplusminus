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
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::queue<TreeNode*> x;

        x.push(root);
        int maxlvl = 1;
        int maxSum = root->val;
        int lvl = 1;
        while (x.size())  {
            int lvlSum = 0;
            int lvlSize = x.size();
            for (int i = 0; i < lvlSize; ++i) {
                TreeNode* node = x.front();
                x.pop();
                lvlSum += node->val;
                if (node->left) x.push(node->left);
                if (node->right) x.push(node->right);
            }
            if (lvlSum > maxSum) {
                maxSum = lvlSum;
                maxlvl = lvl;
            }
            lvl++;

            
        }
        return maxlvl;
    }
};