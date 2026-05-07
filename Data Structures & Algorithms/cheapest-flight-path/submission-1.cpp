class Solution {
public:
    int dfs(vector<vector<pair<int, int>>>& adj, int src, int dst, int level, int k, int cost, vector<int>& currentCost){
        int minCost = INT_MAX;
        if(src == dst) return cost;
        if(level > k) return minCost;
        if(cost > currentCost[src]) return INT_MAX;
        else currentCost[src] = cost;
        for(auto p: adj[src]){
            int c = dfs(adj, p.first, dst, level + 1, k, cost + p.second, currentCost);
            if(c != INT_MAX) minCost = min(minCost, c);
        }
        return minCost;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> currentCost(n, INT_MAX);
        currentCost[src] = 0;
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int c = dfs(adj, src, dst, 0, k, 0, currentCost);
        if(c == INT_MAX) return -1;
        else return c;
    }
};
