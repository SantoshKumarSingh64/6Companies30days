#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    if(n==1)
            return 1;
        vector<long long> ans;
        ans.push_back(1);
        int x2=0,x3=0,x5=0;
        for(int i=1;i<n;i++)
        {
            long long next=min(min(2*ans[x2],3*ans[x3]),5*ans[x5]);
            ans.push_back(next);
            if(next==2*ans[x2])
                x2++;
             if(next==3*ans[x3])
                x3++;
            if(next==5*ans[x5])
                x5++;
        }
        
        return ans.back();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
