//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num = 0;
        int n  = str.size();
        int i = 0;
        bool neg = false;
        if(str[i] == '-'){
            neg = true;
            i++;
        }
        for(;i<n;i++){
            if(str[i] >= '0' && str[i] <= '9'){
                num = num*10 + (str[i]-'0');
            }
            else{
                return -1;
            }
        }
        if(neg){
            num = -num;
        }
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
