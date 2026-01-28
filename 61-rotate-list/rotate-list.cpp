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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next!=NULL) {
            n++;
            temp = temp->next;
        }
        k = k%n;
        ListNode* temp1 = head;
        for(int i = 1; i<n-k; i++) {
            temp1 = temp1->next;
        }
        temp->next = head;
        temp = temp1->next;
        temp1->next = NULL;
        return temp;
    }
};