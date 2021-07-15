class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int max_y = matrix.size();
        int max_x = matrix[0].size();
        vector<vector<int>> m = vector<vector<int>>(max_x, vector<int>(max_y, 0));
        for(int i = 0; i < max_x; i++) {
            for(int j = 0; j < max_y; j++) {
                m[i][j] = matrix[j][i];
            }
        }
        return m;
    }
};
