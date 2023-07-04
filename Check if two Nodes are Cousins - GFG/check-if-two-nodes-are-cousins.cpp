//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

    void root_leaf(Node* root,int a,int b,vector<int> s,vector<vector<int>> & ans){
        if(root == NULL){
            return;
        }
        else{
            s.push_back(root -> data);
            
            if(root -> data == a){
                ans.push_back(s);
            }
            
            else if(root -> data == b){
                ans.push_back(s);
            }
            
            root_leaf(root -> left,a,b,s,ans);
            
            root_leaf(root -> right,a,b,s,ans);
        }
    }



// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   
   vector<int> s;
   
   vector<vector<int>> ans;
   
    root_leaf(root,a,b,s,ans);
    
    if(ans.size() == 0 || ans.size() == 1){
        return 0;
    }
    
    else{
        vector<int> f = ans[0];
        
        vector<int> sec = ans[1];
        
        if(f.size() == sec.size() && f[f.size() - 2] != sec[sec.size() - 2]){
            return 1;
        }
        
        
        
        return 0;
    }
}