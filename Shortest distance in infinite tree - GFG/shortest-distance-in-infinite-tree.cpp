//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
      int distance(int x, int y)
      {
          
          int count =0;
          
          while( x != y){
              if(x > y){
                  x = x/2;
                  count++;
              }
              else if(y > x){
                  y = y/2;
                  count++;
              }
          }
          
          return count;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long X,Y;
        cin>>X>>Y;
        Solution ob;
        cout << ob.distance(X,Y) << endl;
    }
    return 0; 
}
// } Driver Code Ends