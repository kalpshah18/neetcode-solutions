class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, bool& cycle){
        visited[node] = true;
        for(auto neighbour: adj[node]){
            if(neighbour != parent){
                if(visited[neighbour]){
                    cycle = true;
                    return;
                } else {
                    dfs(neighbour, node, adj, visited, cycle);
                }
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        bool cycle = false;
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                dfs(i, -1, adj, visited, cycle);
            }
        }
        if(components == 1 && !cycle) return true;
        else return false;
    }
};
