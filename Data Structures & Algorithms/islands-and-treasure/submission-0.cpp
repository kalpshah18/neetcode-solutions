class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                if(grid[p.first][p.second] == INT_MAX) grid[p.first][p.second] = level;
                for(int j = 0; j < 4; j++){
                    int nx = p.first + dir[j][0];
                    int ny = p.second + dir[j][1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(grid[nx][ny] == INT_MAX) q.push({nx, ny});
                    }
                }
            }
            level++;
        }
    }
};
