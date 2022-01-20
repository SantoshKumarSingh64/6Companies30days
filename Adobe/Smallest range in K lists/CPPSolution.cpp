#include<bits/stdc++.h>
using namespace std;
#define N 1000
 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          set<pair<int, pair<int, int>>> s;
       
       pair<int, int> res{0, INT_MAX};
       
       for(size_t i = 0; i < k; ++i){
           s.insert( {KSortedArray[i][0], {i, 0}} );
       }
       
       while( !s.empty() ){
           // Get the min and max elements from ordered set now
           int minVal = s.begin()->first; 
           int maxVal = s.rbegin()->first;
           if( res.second - res.first > maxVal - minVal )
           {
               res.first = minVal;
               res.second = maxVal;
           }
           
           // Now we remove the minimum element from k-element ordered set
           int r = s.begin()->second.first;
           int c = s.begin()->second.second;
           s.erase(s.begin());
           if( c + 1 == n )
               break;
           s.insert( {KSortedArray[r][c+1], {r, c+1}} );
       }
       return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
