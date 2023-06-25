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
    
    int node_count(ListNode* head){
        int count = 0;
        
        while(head != NULL){
            count++;
            head = head -> next;
        }
        
        return count;
    }
    
    
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* temp = head;
        
        ListNode* temp2 = head;
        
        int count = node_count(head);
        
        map<int,int> m;
        
        for(int i=0;i<count;i++){
            m[temp2 -> val]++;
            temp2 = temp2 -> next;
        }
        
        for(auto it : m){
            while(it.second != 0){
                temp -> val = it.first;
                
                temp = temp -> next;
                
                it.second--;
            }
            
        }
        
        return head;
    }
};