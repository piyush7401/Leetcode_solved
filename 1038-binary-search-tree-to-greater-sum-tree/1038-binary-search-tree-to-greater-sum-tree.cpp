/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void fun(vector<int> & inorder,TreeNode* root){
        if(root == NULL){
            return;
        }
        else{
            fun(inorder,root -> left);
            
            inorder.push_back(root -> val);
            
            fun(inorder,root -> right);
        }
    }
    
    void funny(vector<int> inorder,TreeNode* root,int& i){
        if(root == NULL){
            return;
        }
        else{
            funny(inorder,root -> left,i);
            
            root -> val = inorder[i];
            
            i = i + 1;
            
            funny(inorder,root -> right,i);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root ==NULL){
            return NULL;
        }
        vector<int> inorder;
        
        fun(inorder,root);
        
        int n = inorder.size();
        
        for(int i = n-2;i>=0;i--){
            inorder[i] = inorder[i+1] + inorder[i];
        }
        
        int i =0;
        
        funny(inorder,root,i);
        
        return root;
    }
};