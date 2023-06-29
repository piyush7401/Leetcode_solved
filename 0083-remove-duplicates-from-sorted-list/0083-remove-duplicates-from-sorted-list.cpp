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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }
        set<int> s;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            s.insert(temp -> val);
            temp = temp -> next;
        }
        
        ListNode* tempy = head;
        
        ListNode* start = NULL;
        
        for(auto it : s){
            start = tempy;
            tempy -> val = it;
            tempy = tempy -> next;
        }
        
        start -> next = NULL;
        
        return head;
    }
};