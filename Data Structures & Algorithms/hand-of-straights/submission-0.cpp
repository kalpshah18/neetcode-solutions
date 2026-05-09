class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        multiset<int> ms;
        for(int i = 0; i < n; i++) ms.insert(hand[i]);
        for(int i = 0; i < n / groupSize; i++){
            int h = *ms.begin();
            for(int j = 0; j < groupSize; j++){
                auto p = ms.find(h);
                if(p != ms.end()) ms.erase(p);
                else return false;
                h++;
            }
        }
        return true;
    }
};
