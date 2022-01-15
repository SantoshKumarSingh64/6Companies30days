#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    
    int bfs(vector<vector<int>>& grid, int row, int col,int n,int m){
        
        grid[row][col] = 0;
        int ans = 1;
        for(int i=0;i<8;i++)
        {
            if(row+dir[i][0] >= 0 && row+dir[i][0] < n && col+dir[i][1] >= 0 && col+dir[i][1] < m && grid[row+dir[i][0]][col+dir[i][1]] == 1){
                ans += bfs(grid,row+dir[i][0],col+dir[i][1],n,m);
            }
        }
        return ans;    
    }
    
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    ans = max(ans,bfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
