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
        ListNode cur = head;
        while (cur != null && cur.next != null){
            head = head.next;
            cur = cur.next.next;
            if (head == cur)
                return true;
        }
        return false;
    }
}