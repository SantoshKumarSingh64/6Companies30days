//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    string nextPalindrome(string temp){
        
        int n = temp.size();
        int index1 = n-2;
        //find index1 such that it is smaller than it right adjacent
        while(index1 >= 0 && temp[index1] >= temp[index1+1]){
            index1--;
        }
        if(index1 == -1){
            return "-1";
        }
        
        int index2 = n-1;
        //find index2 such that it is greater than index1 element
        while(index2 >= 0 && temp[index2] <= temp[index1]){
            index2--;
        }
        swap(temp[index1],temp[index2]);
        //now reverse all after index1
        int low = index1+1, high = n-1;
        while(low < high){
            swap(temp[low],temp[high]);
            low++;
            high--;
        }
        return temp;
    }
  
    string nextPalin(string str) { 
        //complete the function here
        int n = str.size();
        string temp;
        for(int i=0;i<(n/2);i++){
            temp += str[i];
        }
        
        string next_str = nextPalindrome(temp);
        if(next_str == temp || next_str == "-1"){
            return "-1";
        }
        if(n%2 != 0){
            next_str += str[n/2];
        }
        n = temp.size();
        for(int i=n-1;i>=0;i--){
            next_str += next_str[i];
        }
        return next_str;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
