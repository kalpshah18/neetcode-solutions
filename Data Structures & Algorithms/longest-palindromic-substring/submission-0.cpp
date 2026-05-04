class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            for(int len = n - i; len >= 1; len--){
                string k = s.substr(i, len);
                string kC = k;
                reverse(kC.begin(), kC.end());
                bool pali = true;
                for(int j = 0; j < len; j++){
                    if(k[j] != kC[j]){
                        pali = false;
                        break;
                    }
                }
                if(pali){
                    if(len > maxLen){
                        maxLen = len;
                        res = k;
                    }
                }
            }
        }
        return res;
    }
};
