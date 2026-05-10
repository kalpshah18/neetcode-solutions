class Solution {
public:
    bool check(vector<int>& freq, int k, int n){
        auto m = *max_element(freq.begin(), freq.end());
        int replacements = n - m;
        if(replacements <= k) return true;
        else return false;
    }
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int res = 1;
        for(int right = 0; right < s.size(); right++){
            freq[s[right] - 'A']++;
            while(!check(freq, k, right - left + 1)){
                freq[s[left++] - 'A']--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
