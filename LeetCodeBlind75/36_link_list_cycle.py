# 141. Linked List Cycle
def hasCycle(self, head: Optional[ListNode]) -> bool:
    if head == None:
        return False

    slow = head
    fast = head.next

    while slow and fast:
        if slow == fast:
            return True
        slow = slow.next
        fast = fast.next
        if fast:
            fast = fast.next

    return False
