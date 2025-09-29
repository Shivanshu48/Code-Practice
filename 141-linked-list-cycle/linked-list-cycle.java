/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode one=head;
        ListNode jump=head;
        while(jump!=null && jump.next!=null)
        {
            one=one.next;
            jump=jump.next.next;
            if(one==jump)
            {
                return true;
            }
            
        }
        return false;
    }
}