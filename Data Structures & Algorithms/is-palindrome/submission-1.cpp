class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t = "";
        for(int i = 0; i < n; i++){
            if(isalnum(s[i])) t += tolower(s[i]);
        }
        string k = t;
        reverse(k.begin(), k.end());
        for(int i = 0; i < t.size(); i++) if(t[i] != k[i]) return false;
        return true;
    }
};
