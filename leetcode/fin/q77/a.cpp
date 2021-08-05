class Solution {
public:
    int n;
    int k;
    vector<int> path;
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        bt(1);
        return this->result;
    }
    void bt(int index) {
        if(this->path.size() == this->k) {
            this->result.push_back(this->path);
            return;
        }
        for(int i = index; i <= this->n; i++) {
            this->path.push_back(i);
            bt(i + 1);
            this->path.pop_back();
        }
    }
};
