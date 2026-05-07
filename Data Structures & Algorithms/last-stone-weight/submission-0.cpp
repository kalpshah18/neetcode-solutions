class Solution {
private:
    priority_queue<int, vector<int>> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(auto stone: stones) pq.push(stone);
        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if(stone1 != stone2) pq.push(stone1 - stone2);
        }
        if(pq.size() == 1) return pq.top();
        else return 0;
    }
};
