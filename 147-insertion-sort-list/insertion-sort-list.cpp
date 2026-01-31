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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur=head;
        while(cur){
            ListNode* nxt=cur->next;
            ListNode* p=&dummy;
            while(p->next && p->next->val < cur->val){
                p=p->next;
            }
            cur->next=p->next;
            p->next=cur;
            cur=nxt;
        }
        return dummy.next;
    }
};