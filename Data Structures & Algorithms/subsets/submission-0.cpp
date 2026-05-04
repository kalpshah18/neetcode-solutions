class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(1 << n);
        for(int i = 0; i < (1 << n); i++){
            int j = i;
            int idx = 0;
            vector<int> subset;
            while(j){
                if(j & 1) subset.push_back(nums[idx]);
                idx++;
                j >>= 1;
            }
            res[i] = subset;
        }
        return res;
    }
};
