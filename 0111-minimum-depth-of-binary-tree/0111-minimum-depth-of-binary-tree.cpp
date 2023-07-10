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

    void root_leaf(TreeNode* root,int count,int &ans){
        if(root == NULL){
            return; 
        }
        else{
            count++;

            if(root -> right == NULL && root -> left == NULL){
                ans = min(ans,count);
            }
            
            else{
                root_leaf(root -> left,count,ans);

                root_leaf(root -> right,count,ans);
            }
        }
    }

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int count =0;
        int ans = INT_MAX;
        root_leaf(root,count,ans);

        return ans;
    }
};