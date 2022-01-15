//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void helper(int a[],int index, int n,vector<vector<string>>pos,string&temp,vector<string>&ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        
        for(auto x: pos[a[index]]){
            temp += x;
            helper(a,index+1,n,pos,temp,ans);
            temp.pop_back();
        }
    
    }
    
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>ans;
        vector<vector<string>>pos = {{},{},{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        string temp;
        helper(a,0,N,pos,temp,ans);
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
