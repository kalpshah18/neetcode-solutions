class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        visited[x][y] = true;
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!visited[nx][ny] && grid[nx][ny] == '1') dfs(grid, visited, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int components = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    components++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return components;
    }
};
