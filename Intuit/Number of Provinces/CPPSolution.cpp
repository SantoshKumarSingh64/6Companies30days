class Solution {
public:
    
    void dfs(int i, vector<int>&vis, vector<int>graph[]){
        
        vis[i] = 1;
        for(auto adj : graph[i]){
            if(vis[adj] == 0){
                dfs(adj,vis,graph);
            }
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>graph[n];
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i != j && isConnected[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
          
        int count = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                dfs(i,vis,graph);
                count++;
            }
        }
        return count;
    }
};
