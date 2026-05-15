class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& res, int dirIdx){
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        res.push_back(matrix[x][y]);
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[dirIdx][0];
            int ny = y + dir[dirIdx][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(!visited[nx][ny]){
                    dfs(nx, ny, matrix, visited, res, dirIdx);
                    break;
                }
            }
            dirIdx = (dirIdx + 1) % 4;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(0, 0, matrix, visited, res, 0);
        return res;
    }
};
