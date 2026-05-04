class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1;
        int maxVol = (right - left) * min(heights[0], heights[n - 1]);
        while(left < right){
            int l = right - left;
            int h;
            if(heights[left] <= heights[right]){
                h = heights[left++];
            } else h = heights[right--];
            int volume = l * h;
            maxVol = max(maxVol, volume);
        }
        return maxVol;
    }
};
