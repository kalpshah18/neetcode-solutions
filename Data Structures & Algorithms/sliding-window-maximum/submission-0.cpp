class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            ms.insert(nums[i]);
        }
        vector<int> res(n - k + 1);
        res[0] = *ms.rbegin();
        for(int i = k; i < n; i++){
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            res[i - k + 1] = *ms.rbegin();
        }
        return res;
    }
};
