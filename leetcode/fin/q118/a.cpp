class Solution {
public:
    void genLine(int line, vector<int>* dst, vector<int>* src) {
        if(line == 1) {
            (*dst).push_back(1);
            return;
        }
        if(line == 2) {
            (*dst).push_back(1);
            return;
        }
        vector<int> a(line, 0);
        a[0] = 1;
        a[line - 1] = 1;
        vector<int> temp;
        for(int i = 0; i <= (*src).size() - 2; i++)  {
            temp.push_back((*src)[i] + (*src)[i + 1]);
        }
        for(int i = 1; i <= line - 2; i++) {
            a[i] = temp[i - 1];
        }
        *dst = a;
    }   
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        vector<int> src;
        vector<int> dst;
        for(int i = 1; i <= numRows; i++) {
            genLine(i, &dst, &src);
            a.push_back(dst);
            src = dst;
        }
        return a;
    }
};
