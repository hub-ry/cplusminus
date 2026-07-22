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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* zero = NULL;
        ListNode* one = head;
        ListNode* two = head->next;
        ListNode* three = head->next;

        while (two) {
          three = two->next;
          two->next = one;
          one->next = zero;
          zero = one;
          one = two;
          two = three;
        }

        head = one;

        return head;
    }
};