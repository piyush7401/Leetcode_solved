/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        int temp = node -> next -> val;
        node -> val = temp;
        
        ListNode* post = node -> next;
        
        node -> next = post -> next;
        delete(post);
        
    }
};