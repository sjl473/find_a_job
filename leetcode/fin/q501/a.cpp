class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> temp = vector<int>();
        traverse(root, &temp);
        unordered_map<int, int> my_map;
        for(int i = 0; i < temp.size(); i++) {
            if(my_map.find(temp[i]) == my_map.end()) {
                my_map.insert(make_pair(temp[i], 1));
            } else {
                my_map[temp[i]] = my_map[temp[i]] + 1;
            }
        }
        int max_counter = INT_MIN;
        for(auto iter = my_map.begin(); iter != my_map.end(); iter++) {
            if(iter->second >= max_counter) {
                max_counter = iter->second;
            } 
        }
        vector<int> result;
        for(auto iter = my_map.begin(); iter != my_map.end(); iter++) {
            if(iter->second == max_counter) {
                result.push_back(iter->first);
            }
        }
        return result;   
    }
    void traverse(TreeNode* root, vector<int>* temp) {
        if(root != nullptr) {
            traverse(root->left, temp);
            (*temp).push_back(root->val);
            traverse(root->right, temp);
        }
    }
};
