class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        
        queue<pair<int,int>>q;
        int water = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
                else{
                    water++;
                }
            }
        }
        if(q.size() == 0 || water == 0){
            return -1;
        }
        
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = -1;
        while(!q.empty()){
            
            int sz = q.size();
            //cout<<sz<<endl;
            for(int i=0;i<sz;i++){
                
                pair<int,int>temp = q.front();
                q.pop();
                
                int r = temp.first;
                int c = temp.second;
                
                for(int j=0;j<4;j++){
                    
                    int n_r = r + dir[j][0];
                    int n_c = c + dir[j][1];
                    
                    if(n_r >= 0 && n_r < n && n_c >= 0 && n_c < n && vis[n_r][n_c] == 0){
                        q.push({n_r,n_c});
                        vis[n_r][n_c] = 1;
                    }
                }
                
            }
            ans++;
        }
        return ans;
    }
};
