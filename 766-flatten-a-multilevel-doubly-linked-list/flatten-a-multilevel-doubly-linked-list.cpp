/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        stack<Node*> st;
        Node* curr = head;

        while(curr){
            if(curr->child){
                if(curr->next) st.push(curr->next);

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            if(!curr->next && !st.empty()){
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};