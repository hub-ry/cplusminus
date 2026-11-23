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
    void travel(TreeNode* root, int targetSum, int &ret, std::unordered_map<long long, int> &prefix, long long running_sum) {
        if (!root) {
            return;
        }

        running_sum += root->val;
        long long need = running_sum - targetSum;
        if (prefix.count(need)) {
            ret += prefix[need];
        }

        prefix[running_sum]++;
        travel(root->left, targetSum, ret, prefix, running_sum); 
        travel(root->right, targetSum, ret, prefix, running_sum); 
        
        prefix[running_sum]--;
    }   
    int pathSum(TreeNode* root, int targetSum) {
        int ret = 0;
        long long running_sum = 0;
        std::unordered_map<long long, int> prefix;
        prefix[0] = 1;
        travel(root, targetSum, ret, prefix, 0);

        return ret;
    }
};