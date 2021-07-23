
class Solution {
public:
vector<vector<int>> permute(vector<int>& v) {
    if(v.size() == 0) {
        return vector<vector<int>>();
    }
    if(v.size() == 1) {
        return vector<vector<int>>(1, vector<int>(1, 1));
    }
    vector<vector<int>> temp;
    vector<vector<int>> result;
    vector<int> branch = vector<int>();
    branch.push_back(v[0]);
    temp.push_back(branch);
    for(int i = 1; i < v.size(); i++) {
        int tree_width = temp.size();
        for(int j = 0; j < tree_width; j++) {
            vector<int> temp_v = temp[j];
            int temp_v_size = temp_v.size() + 1;
            for(int k = 0; k < temp_v_size; k++) {
                auto iter = temp_v.begin();
                temp_v.insert(iter + k, v[i]);
                temp.push_back(temp_v);
                if(temp_v.size() == v.size()) {
                    result.push_back(temp_v);
                }
                temp_v = temp[j];
            }
        }
    }
    return result;
}
};


