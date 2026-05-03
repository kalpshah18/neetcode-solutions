class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto& str: strs) res += to_string(str.size()) + 'x' + str;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] != 'x') j++;
            int len = stoi(s.substr(i, j - i));
            j++;
            res.push_back(s.substr(j, len));
            i = j + len;
        }
        return res;
    }
};
