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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head){
            return nullptr;
        } 
        
        ListNode* copy = new ListNode(0,head);
        ListNode* prv = copy;
        ListNode* cur = head;

        unordered_set<int> s(nums.begin(),nums.end());

        while(cur){
            if(s.count(cur->val)){
                prv->next = cur->next;
                cur = prv;
            }
            else{
                prv = cur;
                cur = cur->next;
            }
        }
        return copy->next;
    }
};