
 // } Driver Code Ends
class Solution {
public:

    vector<unordered_set<int> > make_graph(int numTasks,vector<pair<int, int> >& prerequisites)
    {
        vector<unordered_set<int> > graph(numTasks);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
     
    bool dfs_cycle(vector<unordered_set<int> >& graph, int node,vector<bool>& onpath, vector<bool>& visited)
    {
        if (visited[node])
            return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
    
	bool isPossible(int N, vector<pair<int,int>>& prerequisites) {
	    // Code here
	    
	    vector<unordered_set<int> > graph = make_graph(N, prerequisites);
        vector<bool> onpath(N, false), visited(N, false);
        for (int i = 0; i < N; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
