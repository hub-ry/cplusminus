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
        ListNode* curr = head;
        ListNode* mid = head;
        if (!head) {
            return NULL;
        }

        int nodes = 1;
        while (curr->next) {
            nodes++;
            curr = curr->next;
        }
        int middle = nodes / 2;

        curr = head;

        if (middle == 0) {
            return NULL;
        }


        for (int i = 0; i < middle; i++) {
            if (i == middle - 1) {
                if (curr->next) {
                    mid = curr->next;
                    curr->next = curr->next->next;
                    return head;
                }

            }
            curr = curr->next;

        }
        return head;
    }
};