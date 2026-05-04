class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;
        for(int i = 0; i < n; i++){
            if(!reachable[i]) continue;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j >= n) break;
                reachable[i + j] = true;
            }
        }
        return reachable[n - 1];
    }
};
