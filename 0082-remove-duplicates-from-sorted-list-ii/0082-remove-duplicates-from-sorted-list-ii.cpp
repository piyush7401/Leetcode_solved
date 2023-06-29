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
        
        map<int,int> m;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            m[temp->val]++;
            temp = temp -> next;
        }
        
        ListNode* tempy = head;
        
        ListNode* start = NULL;
        
        for(auto it : m){
            if(it.second == 1){
                start = tempy;
                tempy -> val = it.first;
                tempy = tempy -> next;   
            }
        }
        
        if(start == NULL){
            return NULL;
        }
        
        start -> next = NULL;
        
        return head;
    }
};