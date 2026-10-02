class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head
        
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1
            
        tail.next = head
        k %= length
        steps_to_new_tail = length - k
        new_tail = tail
        while steps_to_new_tail > 0:
            new_tail = new_tail.next
            steps_to_new_tail -= 1
            
        new_head = new_tail.next
        new_tail.next = None
        return new_head