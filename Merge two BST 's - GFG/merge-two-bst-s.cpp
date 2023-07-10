//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
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



// } Driver Code Ends
/*
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
class Solution
{
    public:
    
    void fun(vector<int> & inorder,Node* root){
        if(root == NULL){
            return;
        }
        else{
            fun(inorder,root -> left);
            
            inorder.push_back(root -> data);
            
            fun(inorder,root -> right);
        }
    }
    
    
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> inorder1;
       
       vector<int> inorder2;
       
       fun(inorder1,root1);
       
       fun(inorder2,root2);
       
       vector<int> ans;
       
       int i =0;
       int j = 0;
       
       while(i != inorder1.size() && j != inorder2.size()){
           
           if(inorder1[i] == inorder2[j]){
               ans.push_back(inorder1[i]);
               ans.push_back(inorder1[i]);
               i++;
               j++;
           }
           
           else if(inorder1[i] > inorder2[j]){
               ans.push_back(inorder2[j]);
               j++;
           }
           
           else if(inorder1[i] < inorder2[j]){
               ans.push_back(inorder1[i]);
               i++;
           }
       }
       
       if(i == inorder1.size()){
           while(j != inorder2.size()){
               ans.push_back(inorder2[j]);
               j++;
           }
       }
       
       else if(j == inorder2.size()){
           while( i != inorder1.size()){
               ans.push_back(inorder1[i]);
               i++;
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends