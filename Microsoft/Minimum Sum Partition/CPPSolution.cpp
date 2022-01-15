#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
    int sum=0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
       }
       int temp=0;
       if(sum%2!=0) temp=1;
       sum=sum/2;
       int dp[n+1][sum+1];
       for(int i=0;i<n+1;i++){
           dp[i][0]=0;
       }
       for(int i=0;i<sum+1;i++){
           dp[0][i]=0;
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<sum+1;j++){
               if(arr[i-1]<=j)
                   dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
               else
                   dp[i][j]=dp[i-1][j];
           }
       }
       int ans =dp[n][sum];
       return (2*sum+temp-ans)-ans;
} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
