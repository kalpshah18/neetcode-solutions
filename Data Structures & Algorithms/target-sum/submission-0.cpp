class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        int limit = 1 << n;
        for(int i = 0; i < limit; i++){
            int j = i;
            int s = 0;
            for(int k = 0; k < n; k++){
                if(j & 1) s += nums[k];
                else s -= nums[k];
                j >>= 1;
            }
            if(s == target) res++;
        }
        return res;
    }
};
