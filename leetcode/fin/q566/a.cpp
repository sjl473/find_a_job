class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int oy = 0;
        int ox = 0;
        oy = mat.size();
        ox = mat[0].size();
        int temp =  oy * ox;
        if(temp !=  r * c) {
            return mat;
        } 
        vector<vector<int>> res = vector<vector<int>>(r, vector<int>(c, INT_MAX));
        queue<int> q;
        for(int i = 0; i < oy; i++) {
            for(int j = 0; j < ox; j++) {
                cout << "fuck" << endl;
                q.push(mat[i][j]);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = q.front();
                q.pop();
            }
        }
        return res;
    }
};
