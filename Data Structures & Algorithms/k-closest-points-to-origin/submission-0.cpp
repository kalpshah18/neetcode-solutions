class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> pq;
        for(auto point: points){
            double d = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push({d, {point[0], point[1]}});
        }
        vector<vector<int>> res(k);
        for(int i = 0; i < k; i++){
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
