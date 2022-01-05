#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        long long sum = 0;
        if(N==1) return 1;
        while(N!=0){
            sum += N*N;
            N--;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
