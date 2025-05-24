/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


public class Solution {
    public ListNode swapPairs(ListNode head) {
        // Dummy node to simplify edge cases
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;

        while (head != null && head.next != null) {
            // Nodes to be swapped
            ListNode first = head;
            ListNode second = head.next;

            // Swapping
            prev.next = second;
            first.next = second.next;
            second.next = first;

            // Reinitializing pointers for next swap
            prev = first;
            head = first.next;
        }

        return dummy.next;
    }
}
