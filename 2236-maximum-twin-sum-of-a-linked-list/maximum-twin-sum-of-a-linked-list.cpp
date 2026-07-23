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

        // get end node and half node

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        // now slow holds the middle and fast hold the end


        //reverse the 2nd half of the linkedlist
        ListNode* prev = NULL;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // prev holds the head of the 2nd list;

        int max = 0;
        while (prev) {
            int curr = prev->val + head->val;
            if (curr > max) {
                max = curr;
            }
            prev = prev->next;
            head = head->next;
        }

    return max;

  
    }
};