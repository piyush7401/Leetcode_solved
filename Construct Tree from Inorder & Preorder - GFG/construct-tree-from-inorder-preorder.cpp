//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int search(int start,int end,int x,int in[]){
        
        for(int i = start; i<= end;i++){
            if(in[i] == x){
                return i;
            }
        }
        
        return end;
    }
    
    
    Node* fun(int start,int end,int & index,int pre[],int in[]){
        if(start > end){
            return NULL;
        }
        else{
            Node* root = new Node(pre[index]);
            
            int mid = search(start,end,pre[index],in);
            
            index++;
            
            root -> left = fun(start,mid-1,index,pre,in);
            
            root -> right = fun(mid+1,end,index,pre,in);
            
            return root;

        }
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int start = 0;
        
        int end = n-1;
        
        int index = 0;
        
        
        return fun(start,end,index,pre,in);
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends