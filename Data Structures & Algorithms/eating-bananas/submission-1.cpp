class Solution {
public:
    bool check(vector<int>& piles, int k, int h){
        if (k == 0) return false;
        long long hours = 0;
        for(auto& pile: piles){
            int t = pile / k;
            if(pile % k) t++;
            hours += t;
            if(hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = 1;
        while(!check(piles, upper, h)) upper *= 2;
        int lower = upper >> 1;
        if (lower == 0) lower = 1;
        int res = upper;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            if(mid == 0) {
                lower = 1;
                continue;
            }
            if(check(piles, mid, h)){
                res = mid;
                upper = mid - 1;
            } else lower = mid + 1;
        }
        return res;
    }
};