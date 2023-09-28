# 143. Reorder List
from math import ceil
def reorderList(self, head: Optional[ListNode]) -> None:
    """
    Do not return anything, modify head in-place instead.
    """

    nodes = []
    node = head
    while node:
        nodes.append(node)
        node = node.next
    
    if len(nodes) <= 2:
        return

    l = 0
    r = len(nodes) - 1
    while l < r:
        nodes[l].next = nodes[r]
        if l + 1 < r:
            nodes[r].next = nodes[l + 1]
        else:
            nodes[r].next = None
        l += 1
        r -= 1

    # Check if odd # of nodes
    if l == r:
        nodes[ceil(len(nodes) / 2)].next = nodes[len(nodes) // 2]
        nodes[len(nodes) // 2].next = None
