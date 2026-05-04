class Solution {
public:
    bool valid(string s1, string s2, int l){
        int counter = 0;
        for(int i = 0; i < l; i++){
            if(s1[i] != s2[i]) counter++;
            if(counter > 1) return false;
        }
        return (counter == 1) ? true: false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        int l = beginWord.size();
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        map<string, vector<string>> mp;
        int n = wordList.size();
        for(int i = 0; i < n; i++){
            if(valid(beginWord, wordList[i], l) && wordList[i] != beginWord){
                mp[beginWord].push_back(wordList[i]);
                mp[wordList[i]].push_back(beginWord);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(wordList[i] != beginWord && wordList[j] != beginWord){
                    if(valid(wordList[i], wordList[j], l)){
                        mp[wordList[i]].push_back(wordList[j]);
                        mp[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
        }

        map<string, bool> visited;
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string node = q.front();
                cout << node << endl;
                visited[node] = true;
                q.pop();
                if(node == endWord) return level;
                for(auto& neighbour: mp[node]){
                    if(!visited[neighbour]) q.push(neighbour);
                }
            }
        }
        return 0;
    }
};
