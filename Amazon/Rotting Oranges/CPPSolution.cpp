class Solution {
public:
    struct orange{
        int row;
        int col;
        int tm;
        
        orange(int r,int c,int t){
            row = r;
            col = c;
            tm = t;
        }
    };
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
      
        queue<orange*>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                {
                    q.push(new orange(i,j,0));
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            orange* temp = q.front();
            q.pop();
            
            int r = temp->row, c = temp->col, t = temp->tm;
            ans = t;
            if(r+1 < n && grid[r+1][c] == 1){
                grid[r+1][c] = 2;
                q.push(new orange(r+1,c,t+1));
            }
            
            if(r > 0 && grid[r-1][c] == 1){
                grid[r-1][c] = 2;
                q.push(new orange(r-1,c,t+1));
            }        
            
            if(c+1 < m && grid[r][c+1] == 1){
                grid[r][c+1] = 2;
                q.push(new orange(r,c+1,t+1));
            }
            
            if(c > 0 && grid[r][c-1] == 1){
                grid[r][c-1] = 2;
                q.push(new orange(r,c-1,t+1));
            }   
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
