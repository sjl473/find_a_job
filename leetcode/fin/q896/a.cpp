class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        int len = nums.size();
        if(len == 1) {
            return true;
        }   
        for(int i = 0; i <= len - 2; i++) {
            if(nums[i] < nums[i + 1]) {
                inc = false;
            }
            if(nums[i + 1] < nums[i]) {
                dec = false;        
            }
        }
        if(inc == false && dec == false) {
            return false;
        }
        return true;
    }
};
