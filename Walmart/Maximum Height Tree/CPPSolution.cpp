//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
        // code here
        /*
        Triangle can be formed only when the number of points are equal to (h(h+1)/2) 
        where h is the height of the tree, therefore
        (h(h+1)/2) = n 
        h^2 + h -2n = 0
        
        and we have to find h using quadratic roots method.
        */
        int a = 1;
        int b = 1;
        int c = -2*N;
        
        int ans = (-b+sqrt(b*b-(4*a*c)))/2;
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends
