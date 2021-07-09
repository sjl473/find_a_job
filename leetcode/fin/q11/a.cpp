class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while(left < right){
            int area = std::min(height[left], height[right]) * (right - left);
            res = std::max(res, area);
            if(height[right] <= height[left]) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};

