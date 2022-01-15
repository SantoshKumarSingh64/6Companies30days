// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(vector<vector<int>>g, vector<int>&vis, int i, string& ans){
        
        vis[i] = 1;
        for(auto adj : g[i]){
            if(vis[adj] == 0){
                dfs(g,vis,adj,ans);
            }
        }
        //cout<<char('a'+i)<<endl;
        char ch = i + 'a';
        ans = ch + ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>>g(k);
        for(int i=0;i<n-1;i++){
            for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j] != dict[i+1][j]){
                    g[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        /*for(int i=0;i<k;i++){
            cout<<char('a'+i)<<" --> ";
            for(auto adj : g[i]){
                cout<<char(adj+'a')<<"  ";
            }
            cout<<endl;
        }*/
        
        vector<int>vis(k,0);
        string ans = "";
        for(int i=0;i<k;i++){
            if(vis[i] == 0){
                dfs(g,vis,i,ans);
            }
        }
        //cout<<ans<<endl;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
