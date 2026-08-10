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
    ListNode* deleteMiddle(ListNode* head) {
        // find the middle node

        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return NULL;
        }
        ListNode* temp = head;

        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        temp = head;
        
        // count holds the number of nodes
        int mid = count / 2;
        int prev = mid - 1;
        for (int i = 0; i < mid; i++) {
            if (i == prev) {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};