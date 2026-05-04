class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) != mp.end()){
            int left = 0, right = mp[key].size() - 1;
            if(mp[key][left].first > timestamp) return "";
            string res = mp[key][left].second;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(mp[key][mid].first <= timestamp){
                    res = mp[key][mid].second;
                    left = mid + 1;
                } else right = mid - 1;
            }
            return res;
        } else return "";
    }
};
