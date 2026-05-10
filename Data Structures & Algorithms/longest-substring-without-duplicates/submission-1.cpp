class Solution {
public:
    bool check(unordered_map<char, int>& mp){
        for(auto& p: mp){
            if(p.second > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int left = 0;
        int res = 0;
        for(int right = 0; right < n; right++){
            mp[s[right]]++;
            while(!check(mp)){
                mp[s[left++]]--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
