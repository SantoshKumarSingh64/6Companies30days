#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        
        int i = 0,j,left,right;
        
        while(i < n){
            j = i+1;
            while(j < n){
                left = j+1;
                right = n-1;
                int sum = k - (arr[i]+arr[j]);
                while(left < right){
                    if(arr[left]+arr[right] == sum){
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        while(arr[left] == arr[left-1]){
                            left++;
                        }
                        right--;
                        while(arr[right] == arr[right+1]){
                            right--;
                        }
                    }
                    else if(arr[left]+arr[right] < sum){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                j++;
                while(arr[j] == arr[j-1]){
                    j++;
                }
            }
            i++;
            while(arr[i] == arr[i-1]){
                i++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
