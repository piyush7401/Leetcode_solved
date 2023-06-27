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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        else{
            queue<TreeNode*> q;
            
            q.push(root);
            
            q.push(NULL);
            
            while(q.empty() != 1){
                TreeNode* temp = q.front();
                
                q.pop();
                
                if(temp != NULL){
                    
                    if(q.front() == NULL){
                        ans.push_back(temp -> val);
                    }
                    
                    if(temp -> left != NULL){
                        q.push(temp ->left);
                    }
                    
                    if(temp -> right != NULL){
                        q.push(temp -> right);
                    }
                }
                
                if(temp == NULL){
                    
                    //ans.push_back(-1);
                    
                    if(q.size() == 0){
                        return ans;
                    }
                    
                    q.push(NULL);
                }
            }
            
            return ans;
        }
    }
};