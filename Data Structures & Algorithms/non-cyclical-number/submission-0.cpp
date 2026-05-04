class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;
        while(n != 1){
            int res = 0;
            int k = n;
            while(k){
                res += (k % 10) * (k % 10);
                k /= 10;
            }
            n = res;
            if(mp.find(res) != mp.end()) return false;
            mp[res] = true;
        }
        return true;
    }
};
