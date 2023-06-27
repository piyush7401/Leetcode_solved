/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        queue<Node*> q;
        
        q.push(head);
        
        while(q.empty() != 1){
            
            int a = q.size();
            
            for(int i=0;i<a;i++){
                Node* temp = q.front();
                
                q.pop();
                
                if(i < a - 1){
                    temp -> next = q.front();
                }
                
                else if(i == a){
                    temp -> next = NULL;
                }
                
                if(temp -> left != NULL){
                    q.push(temp->left);
                }
                
                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
            }
        }
        
        return head;
    }
};