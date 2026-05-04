class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<bool> visited(n, false);

        pq.push({0, 0});
        int res = 0;

        while(!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if(visited[u]) continue;

            visited[u] = true;
            res += cost;

            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int d = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);
                    pq.push({d, v});
                }
            }
        }
        return res;
    }
};
