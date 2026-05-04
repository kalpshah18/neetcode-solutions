class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto p = lower_bound(nums.begin(), nums.end(), target);
        if(*p == target) return distance(nums.begin(), p);
        else return -1;
    }
};
