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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,nullptr);
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        int part = len/k;
        int extra = len%k;
        curr=head;
        for(int i=0; i<k && curr; i++){
            res[i] = curr;
            int size = part+(extra>0);
            extra--;
            for(int j=1; j<size; j++){
                curr = curr->next;
            }
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return res;
    }
};