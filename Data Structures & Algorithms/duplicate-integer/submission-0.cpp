class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        for(auto& num: nums){
            if(mp.find(num) != mp.end()) return true;
            else mp[num] = true;
        }
        return false;
    }
};