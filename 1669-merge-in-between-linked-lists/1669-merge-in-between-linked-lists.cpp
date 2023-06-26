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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre = NULL;
        ListNode* post = list1;
        
        ListNode* temp = list1;
        
        ListNode* temp1 = list1;
        
        while(a != 0){
            pre = temp;
            temp = temp -> next;
            a--;
        }
        
        while(b != 0){
            temp1 = temp1 -> next;
            post = temp1;
            b--;
        }
        
        post = post -> next;
        
        pre -> next = list2;
        
        while(list2 -> next != NULL){
            list2 = list2 -> next;
        }
        
        list2 -> next = post;
        
        cout<<pre-> val<<" "<<post->val<<"\n";
        
        return list1;
    }
};