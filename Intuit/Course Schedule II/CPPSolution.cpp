class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        vector<int>ans;
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            cnt++;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(cnt != n){
            vector<int>dummy;
            return dummy;
        }
        return ans;
    }
};
