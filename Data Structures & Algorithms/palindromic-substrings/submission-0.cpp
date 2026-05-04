class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int counter = 0;
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
                    counter++;
                }
            }
        }
        return counter;
    }
};
