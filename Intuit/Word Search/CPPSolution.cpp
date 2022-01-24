#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(int row,int col,int n, int m, int index, int len, vector<vector<int>>&vis,vector<vector<char>>& board, string word)
    {
        if(index == len){
            return true;
        }
        
        vis[row][col] = 1;
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<4;i++){
            int new_row = row+dir[i][0];
            int new_col = col+dir[i][1];
            
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && vis[new_row][new_col] == 0 && board[new_row][new_col] == word[index]){
                bool ans = dfs(new_row,new_col,n,m,index+1,len,vis,board,word);
                if(ans){
                    return ans;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        int n = board.size();
        int m = board[0].size();
    
        int l = word.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j] == word[0]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    bool ans = dfs(i,j,n,m,1,l,vis,board,word);
                    if(ans){
                        return ans;
                    }
                }
                
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
