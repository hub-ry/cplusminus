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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first_sum = 0;
        int second_sum = 0;
        int carry = 0;
        int sum = 0;
        ListNode *result = new ListNode();
        ListNode *head = result;
        while (true) {

            if (l1 == NULL && l2 == NULL) {
                if (carry != 0) {
                    result->next = new ListNode();
                    result = result->next;
                    result->val = carry;

                }
                return head;
            }
            
            if (l1 != NULL) {
                first_sum += l1->val;
                l1 = l1->next;
 
            }
            if (l2 != NULL) {
                second_sum += l2->val;
                l2 = l2->next;

            }

            
            sum = first_sum + second_sum + carry;
            carry = sum / 10; // everything but 1's place
            
            int v = sum % 10; // get the 1s place only 
            result->val = v; // send the value to a node
            first_sum = 0;
            second_sum = 0;
            if (l1 != NULL || l2 != NULL) {
                result->next = new ListNode();
                result = result->next;
            }
                       
        }
    }
};