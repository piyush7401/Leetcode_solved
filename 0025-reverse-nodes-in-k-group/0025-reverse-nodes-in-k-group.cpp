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

    int count_part(ListNode* head){
        int count =0;
        while(head != NULL){
            head = head -> next;
            count++;
        }
        return count;
    }

    ListNode* fun(ListNode* head,int k){
            if(head == NULL){
                return NULL;
            }

            if(count_part(head) < k){
                return head;
            }

            else{
                ListNode* pre = NULL;
                ListNode* inter = head;
                
                int i = 0;
                
                while(i < k){
                    ListNode* after = head -> next;
                    
                    head -> next = pre;
                    
                    pre = head;
                    
                    head = after;
                    
                    i++;
                }
                
                
                
                inter -> next = fun(head,k);
                
                return pre;
            }
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        return fun(head,k);
    }
};