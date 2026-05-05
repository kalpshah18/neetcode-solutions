class Solution {
public:
    void dfs(map<string, vector<string>>& mp, string node, vector<string>& res){
        while(!mp[node].empty()){
            string next = mp[node].back();
            mp[node].pop_back();
            dfs(mp, next, res);
        }
        res.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> mp;

        for(auto& t : tickets){
            mp[t[0]].push_back(t[1]);
        }

        for(auto& p : mp){
            sort(p.second.begin(), p.second.end(), greater<string>());
        }

        vector<string> res;
        dfs(mp, "JFK", res);

        reverse(res.begin(), res.end());
        return res;
    }
};