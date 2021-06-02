class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set;
        for(int & num : nums) {
            if(my_set.count(num) == 1) {
                return true;
            }
            my_set.insert(num);
        }
        return false;
    }
};