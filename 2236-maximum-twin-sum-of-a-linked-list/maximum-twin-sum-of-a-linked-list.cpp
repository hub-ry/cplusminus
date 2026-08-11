/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        
        if (!head || !head->next) {
            return -1;
        }

        

        // find the middle node (it will be even)
        ListNode* slow = head;
        ListNode* fast = head->next;

        vector<int> x; 
        while (fast && fast->next) {
            x.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        x.push_back(slow->val);

        // now slow hold the middle, we should also sum slow as we go
        // x holds the list up until the middle

        slow = slow->next;
        int k = x.size() - 1;
        int big = INT_MIN;
        while (slow) {
            x[k] += slow->val;
            if (x[k] > big) {
                big = x[k];
            }
            k--;

            slow = slow->next;
        }
        return big;
    }
};