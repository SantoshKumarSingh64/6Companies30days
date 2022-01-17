//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void helper(int n, string temp, vector<string>&ans, int open, int close){
        
        if(temp.size() == 2*n && open == close){
            ans.push_back(temp);
            return;
        }
        
        if(open < n){
            temp += "(";
            helper(n,temp,ans,open+1,close);
            temp.pop_back();
        }
        if(close < open){
            temp += ")";
            helper(n,temp,ans,open,close+1);
            temp.pop_back();
        }
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = 0;
        int close = 0;
        
        vector<string>ans;
        string temp;
        
        helper(n,temp,ans,open,close);
        
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
