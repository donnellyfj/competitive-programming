# 23. Merge k Sorted Lists
def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head = curr = ListNode()

        def cleanList():
            i = 0
            while i < len(lists):
                if lists[i] == None:
                    lists.pop(i)
                else:
                    i += 1
        
        cleanList()

        while len(lists) >= 2:
            vals = [node.val for node in lists]
            nodeIdx = vals.index(min(vals))
            curr.next = lists[nodeIdx]
            lists[nodeIdx] = lists[nodeIdx].next
            curr = curr.next
            cleanList()
        
        if lists:
            curr.next = lists[0]
        
        return head.next
