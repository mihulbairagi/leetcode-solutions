class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        ListNode tail = head;
        int n = 1;
        while (tail.next != null) {
            tail = tail.next;
            n++;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        ListNode newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail.next;
        }
        ListNode newHead = newTail.next;
        newTail.next = null;
        tail.next = head;
        return newHead;
    }
}