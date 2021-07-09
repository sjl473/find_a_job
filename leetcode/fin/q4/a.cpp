class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<int> v = vector<int>(s1 + s2, 0);
        for(int i = 0; i < s1; i++) {
            v[i] = nums1[i];
        }
        int counter = 0;
        for(int j = s1; j < s1 + s2; j++) {
            v[j] = nums2[counter];
            ++counter;
        }
        std::sort(v.begin(), v.end());
        int mid = (s1 + s2) / 2;
        if(((s1 + s2) % 2) == 0) {
            return  ((double)(v[mid]) + (double)(v[mid - 1])) / 2;
        } else {
            return (v[mid]);
        }
        return 0;
    }
};
