class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 1; i <= n; i++){
            x ^= nums[i - 1];
            x ^= i;
        }
        return x;
    }
};
