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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        // Step 1: Create dummy
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Move prev to node before 'left'
        ListNode* prev = dummy;
        for(int i=1; i<left; i++){
            prev = prev->next;
        }

        // Step 3: Reverse sublist
        ListNode* start = prev->next;
        ListNode* second = start->next;

        for(int i=0; i<right-left; i++){
            start->next = second->next;
            second->next = prev->next;
            prev->next = second;
            second = start->next;
        }

        return dummy->next;
    }
};