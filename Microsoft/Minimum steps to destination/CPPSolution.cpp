// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int steps = 0, sum = 0;
        while(true){
            sum = sum + steps;
            steps++;
            if(sum == D){
                return steps-1;
                break;
            }
            if(sum > D and (sum-D)%2 == 0){
                return steps-1;
                break;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
