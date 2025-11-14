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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverseHead = reverseList(slow);

        ListNode* first = head;
        ListNode* second = reverseHead;

        while(second != NULL){
            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;
        }
        return true;
    }
};