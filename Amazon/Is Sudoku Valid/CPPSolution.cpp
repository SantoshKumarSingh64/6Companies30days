// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        map<string,int>m;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j] == 0){
                    continue;
                }
                
                string row = to_string(mat[i][j])+"row"+to_string(i);
                string col = to_string(mat[i][j])+"col"+to_string(j);
                string box = to_string(mat[i][j])+"box"+to_string(i/3)+","+to_string(j/3);
                //cout<<row<<"->"<<m[row]<<","<<col<<"->"<<m[col]<<","<<box<<"->"<<m[box]<<endl;
                if(m[row] == 1 || m[col] == 1 || m[box] == 1){
                    return 0;
                }
                m[row] = 1;
                m[col] = 1;
                m[box] = 1;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
