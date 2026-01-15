/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        ListNode* cur = head;
        while (cur != nullptr){
            cur = cur->next;
            cnt++;
        }
        int mid = cnt / 2;
        ListNode* removed = head;
        ListNode* before = head;
        std::cout << mid;
        while (mid--){
            removed = removed->next;
            if (mid != 0)
                before = before->next;
        }
        before->next = removed->next;
        if (before == removed) head = nullptr;
        return head;
    }
};