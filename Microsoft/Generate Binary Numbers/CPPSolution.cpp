#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string decToBinary(int n){
    string s;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s.push_back('1');
        else
            s.push_back('0');
    }
    for(int i=0;i<32;i++){
        if(s[i] == '1') 
            return s.substr(i);
    }
}
vector<string> generate(int N){
    vector<string> ans;
	for(int i=1;i<=N;i++){
	    string temp = decToBinary(i);
	    ans.push_back(temp);
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
