class Solution {
public:
    bool check(vector<int>& f1, vector<int>& f2){
        for(int i = 0; i < 26; i++){
            if(f2[i] > f1[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for(auto& c: s1) f1[c - 'a']++;

        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            f2[s2[right] - 'a']++;
            while(!check(f1, f2)){
                f2[s2[left++] - 'a']--;
            }
            if(f1 == f2) return true;
        }
        return false;
    }
};
