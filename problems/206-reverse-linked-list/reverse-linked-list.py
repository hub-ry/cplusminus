# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        curr = head
        if not head:
            return head
        if not head.next:
            return head

        node1 = None
        while(curr):
            next = curr.next
            curr.next = node1
            node1 = curr
            curr = next

        return node1

        
        