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
        int count = 0;
        
        while(head != NULL){
            count++;
            head = head -> next;
        }
        
        return count;
    }
    
    ListNode* fun(ListNode* head,int k){
            if(head == NULL){
                return NULL;
            }

            if(count_node(head) < k && count_node(head)%2 == 1){
                return head;
            }
        
            else if(count_node(head) < k && count_node(head)%2 == 0){
                //cout<<"hello"<<"\n";
                ListNode* pre = NULL;
                ListNode* inter = head;
                
                int i =0;
                
                while(head != NULL){
                    ListNode* after = head -> next;
                    
                    head -> next = pre;
                    
                    pre = head;
                    
                    head = after;
                    
                    i++;
                }
                
                inter -> next = NULL;
                
                return pre;
            }
        
            else if(k%2 == 1){
                ListNode* pre = NULL;
                
                ListNode* start = head;
                
                int i =0;
                
                while(i < k){
                    pre = head;
                    
                    head = head -> next;
                    
                    i++;
                }
                
                pre -> next = fun(head,k+1);
                
                return start;
            }

            else{
                ListNode* pre = NULL;
                ListNode* inter = head;
                
                int i =0;
                
                while(i < k){
                    ListNode* after = head -> next;
                    
                    head -> next = pre;
                    
                    pre = head;
                    
                    head = after;
                    
                    i++;
                }
                
                inter -> next = fun(head,k+1);
                
                return pre;
            }
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        int k = 1;
        
        return fun(head,k);
    }
};