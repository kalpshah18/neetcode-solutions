class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++){
            int counter = 0;
            int j = i;
            while(j){
                if(j & 1) counter++;
                j >>= 1;
            }
            res[i] = counter;
        }
        return res;
    }
};
