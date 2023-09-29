# 206. Reverse Linked List
def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    while head:
        nxt = head.next
        head.next = prev
        prev = head
        head = nxt
    
    return prev
