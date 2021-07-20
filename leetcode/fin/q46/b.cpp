// class Solution {
// public:
//     vector<int> path;
//     void bt(vector<vector<int>>* result, vector<bool>* is_used, const vector<int>* nums) {
//         for(int i = 0 ; i < nums->size(); i++) {
//             if((*is_used)[i] == false) {
//                 (*is_used)[i] = true;
//                 path.push_back((*nums)[i]);
//                 bt(result, is_used, nums);
//                 path.pop_back();
//                 (*is_used)[i] = false;
//             } else {
//                 continue;
//             }
//         }
//         if(path.size() == is_used->size()) {
//             result->emplace_back(path);
//             return;    
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> result;
//         vector<bool> is_used(nums.size(), false);
//         bt(&result, &is_used, &nums);
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();
        vector<int> initVec = {nums[0]};
        vector<vector<int>> output;
        output.push_back(initVec);
        for(int i = 1; i < nums.size(); i++){
            int size = output.size();
            for(int j = 0; j < size; j++) {
                output[j].push_back(nums[i]);
                vector<int> tmpVector = output[j];
                for(int k = tmpVector.size() - 1; k > 0; k--){
                    tmpVector[k] = tmpVector[k - 1];
                    tmpVector[k - 1] = nums[i];
                    output.push_back(tmpVector);
                }
            }
        }
        return output;
    }
};

      


