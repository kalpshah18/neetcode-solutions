class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0; i < n - 2; i++){
            int target = -1 * nums[i];
            map<int, bool> mp;
            for(int j = i + 1; j < n; j++){
                if(mp.find(target - nums[j]) != mp.end()){
                    vector<int> a = {nums[i], target - nums[j], nums[j]};
                    sort(a.begin(), a.end());
                    s.insert(a);
                }
                mp[nums[j]] = true;
            }
        }
        vector<vector<int>> res;
        for(auto v: s){
            res.push_back(v);
        }
        return res;
    }
};
