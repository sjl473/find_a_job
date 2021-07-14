class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> dp_right = vector<int>(height.size(), 0);
        vector<int> dp_left = vector<int>(height.size(), 0);
        if(height.size() == 0 || height.size() == 1 || height.size() == 2) {
            return 0;
        }
        int sum = 0;
        for(int i = 1; i <= height.size() - 2; i++) {
            dp_left[i] = std::max(height[i - 1], dp_left[i-1]);
        }
        
        for(int i = height.size() - 2;i>=1;i--)
        {
        dp_right[i] = std::max(height[i+1],dp_right[i+1]);
        }

        for(int i=1;i<=height.size()-2;i++)
        {
            int my_min = std::min(dp_left[i],dp_right[i]);
            if(my_min<height[i]) {
                // 
            } else {
                sum += my_min-height[i];
            }
        }
        return sum;
    }
};
