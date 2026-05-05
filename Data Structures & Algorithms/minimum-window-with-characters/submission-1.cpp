class Solution {
public:
    bool check(vector<int>& freqT, vector<int>& freqS){
        for(int i = 0; i < 52; i++){
            if(freqT[i] > freqS[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> freqT(52, 0);
        for(auto c: t){
            if(c >= 'a' && c <= 'z')
            freqT[c - 'a']++;
            else
            freqT[c - 'A' + 26]++;
        }
        vector<int> freqS(52, 0);
        int left = 0;
        string res = "";
        for(int right = 0; right < s.size(); right++){
            if(s[right] >= 'a' && s[right] <= 'z')
            freqS[s[right] - 'a']++;
            else
            freqS[s[right] - 'A' + 26]++;
            while(check(freqT, freqS)){
                if(res == "") res = s.substr(left, right - left + 1);
                if(right - left + 1 < res.length())
                res = s.substr(left, right - left + 1);
                if(s[left] >= 'a' && s[left] <= 'z')
                freqS[s[left++] - 'a']--;
                else
                freqS[s[left++] - 'A' + 26]--;
            }
        }
        return res;
    }
};
