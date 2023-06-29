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
    
    int count_node(ListNode* head){
        int count =0;;
        
        while(head != NULL){
            head = head -> next;
            count++;
        }
        
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }
        
        int count = count_node(head);
        
        ListNode* last = head;
        
        while(last -> next != NULL){
            last = last -> next;
        }
        
        last -> next = head;
        
        ListNode* start = head;
        
        k = k%count;
        
        for(int i=0;i<(count-k);i++){
            start = start -> next;
        }
        
        last = start;
        
        for(int i=0;i<count-1;i++){
            last = last -> next;
        }
        
        last -> next = NULL;
        
        return start;
    }
};