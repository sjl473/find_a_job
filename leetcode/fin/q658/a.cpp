class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        while(true) {
            if(l < r) {
                int m = (l + r) / 2;
                if(arr[m] + arr[m + k] >= x + x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {
                break;
            }
        }
        vector<int> a;
        for(int i = l; i <= k + l - 1; i++) {
            a.push_back(arr[i]);
        }
        return a;
    }
};
