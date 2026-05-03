class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxHeight = height[0];
        left[0] = 0;
        for(int i = 1; i < n; i++){
            left[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        maxHeight = height[n - 1];
        right[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            right[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        int res = 0;
        for(int i = 1; i < n - 1; i++){
            res += max(min(left[i], right[i]) - height[i], 0);
        }
        return res;
    }
};
