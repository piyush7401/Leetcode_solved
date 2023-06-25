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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2;
        }
        
        else if(list2 == NULL){
            return list1;
        }
        
        ListNode* temp1 = list1;
        
        ListNode* temp2 = list2;
        
        ListNode* temp = NULL;
        
        if(list1 -> val <= list2 -> val){
            temp = list1;
            list1 = list1 -> next;
            temp -> next = NULL;
        }
        
        else{
            temp = list2;
            list2 = list2 -> next;
            temp -> next = NULL;
        }
        
        ListNode* new_head = temp;
        
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val <= list2 -> val){
                
                while(list1 != NULL && list1 -> val <= list2 -> val){
                    
                    temp -> next = list1;
                
                    list1 = list1 -> next;
                    
                    temp = temp -> next;
                    
                    temp -> next = NULL;
                }
                
                if(list1 == NULL){
                    temp -> next = list2;
                    
                    return new_head;
                }
                
            }
            
            if(list1 -> val > list2 -> val){
                
                while(list2 != NULL && list1 -> val > list2 -> val){
                    
                    temp -> next = list2;
                
                    list2 = list2 -> next;
                    
                    temp = temp -> next;
                    
                    temp -> next = NULL;
                }
                
                if(list2 == NULL){
                    temp -> next = list1;
                    
                    return new_head;
                }
                
            }
            
        }
        
        if(list1 == NULL){
            temp -> next = list2;
        }
        
        else if(list2 == NULL){
            temp -> next = list1;
        }
        
        return new_head;
        
    }
};