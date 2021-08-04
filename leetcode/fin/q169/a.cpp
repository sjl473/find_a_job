class Solution {
public:
    int majorityElement(vector<int>& v) {
        int m = v[0];
        int counter = 1;
        for(int i = 1; i < v.size(); i++) {
            if(counter == 0) {
                ++counter;
                m = v[i];
            } else {
                if(m == v[i]) {
                    ++counter;
                } else {
                    --counter;
                }
            }
        }
        return m;
    }
};




