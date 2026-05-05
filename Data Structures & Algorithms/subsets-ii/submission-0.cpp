class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> subsetSet;
        for(int i = 0; i < (1 << n); i++){
            int j = i;
            int idx = 0;
            vector<int> subset;
            while(j){
                if(j & 1) subset.push_back(nums[idx]);
                j >>= 1;
                idx++;
            }
            sort(subset.begin(), subset.end());
            if(subsetSet.find(subset) == subsetSet.end()){
                res.push_back(subset);
                subsetSet.insert(subset);
            }
        }
        return res;
    }
};
