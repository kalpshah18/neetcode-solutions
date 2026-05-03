class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1(26, 0), f2(26, 0);
        for(int i = 0; i < s.size(); i++) f1[s[i] - 'a']++;
        for(int i = 0; i < t.size(); i++) f2[t[i] - 'a']++;
        if(f1 == f2) return true;
        else return false;
    }
};
