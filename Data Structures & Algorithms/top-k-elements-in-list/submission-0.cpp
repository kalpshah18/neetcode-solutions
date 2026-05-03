class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freq(2001);
        for(int i = 0; i < 2001; i++){
            freq[i].first = 0;
            freq[i].second = i - 1000;
        }
        for(auto& num: nums){
            freq[num + 1000].first++;
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        vector<int> res(k);
        for(int i = 0; i < k; i++) res[i] = freq[i].second;
        return res;
    }
};
