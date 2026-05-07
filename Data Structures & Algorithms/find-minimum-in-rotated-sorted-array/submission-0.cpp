class Solution {
public:
    int findMin(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while(left <= right){
            if(left == right) return arr[left];
            if(arr[left] < arr[right]){
                return arr[left];
            } else {
                int mid = left + (right - left) / 2;
                if(arr[mid] > arr[right]){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
    }
};
