class Solution {
public:
    
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>>graph[n];
        int e = edges.size();
        
        for(int i=0;i<e;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            double w = succProb[i];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        vector<double>p(n,0);
        
        priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>> >pq;
        pq.push({-1,start});
        p[start] = -1;
        
        while(!pq.empty()){
            
            pair<double,int>temp = pq.top();
            pq.pop();
            
            int curr = temp.second;
            double pro = temp.first;
            //cout<<curr<<"  "<<pro<<"->"<<endl;
            if(curr == end){
                return -pro;
            }
            
            for(auto ad : graph[curr]){
                int adj = ad.first;
                double pr = ad.second*pro;
                //cout<<adj<<"  "<<pr<<endl;
                if(pro < p[adj]){
                    p[adj] = pr;
                    pq.push({pr,adj});
                }
            }
        }
        return p[end];
    }
};
