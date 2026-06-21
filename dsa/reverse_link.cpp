struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  ListNode* next = nullptr;

  while (curr != nullptr) {
    next = curr->next; // save the next node
    curr->next = prev; // set curr next to prev
    prev = curr; // now move prev
    curr = next; // move curr
  }
}