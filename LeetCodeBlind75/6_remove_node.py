# 19. Remove Nth Node From End of List
def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    # Find length of list
    listLen = 0
    curr = head
    while curr != None:
        curr = curr.next
        listLen += 1
    
    n = listLen - n + 1
    # Remove head
    if n == 1:
        head = head.next
    else:
        curr = head.next
        prev = head
        for _ in range(n - 2):
            prev = curr
            curr = curr.next
        print(n, prev, curr)
        prev.next = curr.next
    
    return head
