//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* lowest(Node* root,int a,int b){
        if(root == NULL){
            return NULL;
        }
        else{
            if(root -> data == a || root -> data == b){
                return root;
            }
            
            Node* l = lowest(root -> left,a,b);
            
            Node* r = lowest(root -> right,a,b);
            
            if(l != NULL && r != NULL){
                return root;
            }
            
            else if(l == NULL && r != NULL){
                return r;
            }
            
            else if(r == NULL && l != NULL){
                return l;
            }
            return NULL;
        }
    }
    
    
    int dist(Node* root,int x){
        if(root == NULL){
            return 0;
        }
        else{
            if(root -> data == x){
                return 1;
            }
            
            int l = dist(root -> left,x);
            
            int r = dist(root -> right,x);
            
            if(l == 0 && r == 0){
                return 0;
            }
            else{
                return l+r+1;
            }
            
            
        }
    }
    
    int findDist(Node* root, int a, int b) {
        
        Node* lca = lowest(root,a,b); 
        
        int first = dist(lca,a);
        
        int second = dist(lca,b);
        
        return first + second - 2;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends