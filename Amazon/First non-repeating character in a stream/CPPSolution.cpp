#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>dp(26,0);
		    queue<char>q;
		    string ans;
		    int n = A.size();
		    
		    for(int i=0;i<n;i++){
		        int index = A[i]-'a';
		        if(dp[index] == 0){
		            q.push(A[i]);
		        }
		        dp[index]++;
		        
		        while(!q.empty() && dp[q.front()-'a'] != 1){
		            q.pop();
		        }
		        if(q.empty()){
		            ans += '#';
		        }
		        else{
		            ans += q.front();
		        }
		    }
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
