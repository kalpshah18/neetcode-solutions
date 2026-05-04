class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            components++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int tp = q.front();
                q.pop();
                if(visited[tp]) continue;
                visited[tp] = true;
                for(auto node: adj[tp]){
                    if(!visited[node]) q.push(node);
                }
            }
        }
        return components;
    }
};
