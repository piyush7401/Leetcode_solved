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
    
    void root_leaf(TreeNode* root,string s,map<string,int> & m){
        if(root == NULL){
            return;
        }
        else{
            s = s + (char)(root-> val + 97);
            
            if(root -> left == NULL && root -> right == NULL){
                
                reverse(s.begin(),s.end());
                
                m[s]++;
            }
            
            else{
                root_leaf(root -> left,s,m);
                
                root_leaf(root -> right,s,m);
            }
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        string s;
        
        map<string,int> m;
        
        root_leaf(root,s,m);
        
        auto it = m.begin();
        
        return it -> first;
    }
};