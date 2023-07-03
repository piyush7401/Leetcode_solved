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
    
    void root_leaf(TreeNode* root,string s,int & sum){
        if(root == NULL){
            return;
        }
        else{
            s = s + (to_string(root -> val));
            
            if(root -> left == NULL  && root -> right == NULL){
                
                sum = sum + stoi(s);
            }
            
            else{
                root_leaf(root -> left,s,sum);
                
                root_leaf(root -> right,s,sum);
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        
        string s;
        
        int sum =0;
        
        root_leaf(root,s,sum);
        
        return sum;
    }
};