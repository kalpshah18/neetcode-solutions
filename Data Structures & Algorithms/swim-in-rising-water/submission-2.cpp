class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()){
            auto [d, cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;

            if(d > dist[x][y]) continue;
            for(auto& dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int newDist = max(d, grid[nx][ny]);
                    if(newDist < dist[nx][ny]){
                        dist[nx][ny] = newDist;
                        pq.push({newDist, {nx, ny}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
