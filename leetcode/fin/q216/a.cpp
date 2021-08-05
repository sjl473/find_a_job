class Solution {
public:
    int k;
    int sum;
    int n;
    vector<int> path;
    vector<vector<int>> result;
    void bt(int index) {
        if(this->path.size() == k) {
            if(std::accumulate(this->path.begin(), this->path.end(), 0) == this->sum) {
                this->result.push_back(this->path);
            }   
            return;
        }
        for(int i = index; i <= this->n; i++) {
            this->path.push_back(i);
            bt(i + 1);
            this->path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->sum = n;
        this->n = 9;
        bt(1);
        return this->result;
    }
};
