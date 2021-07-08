class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int gsize = isConnected.size();
        if(gsize == 0) {
            return 0;
        }
        int result = 0;
        vector<bool> is_vis = vector<bool>(gsize, false);
        queue<int> q;
        for(int i = 0; i < gsize; i++) {
            if(is_vis[i] == true) {
                continue;
            } else {
                q.push(i);
                while(q.empty() == false) {
                    int curr = q.front();
                    for(int j = 0; j < isConnected[curr].size(); j++) {
                        if(is_vis[j] == false && isConnected[j][curr] == 1) {
                            q.push(j);
                        }
                    }
                    q.pop();
                    is_vis[curr] = true;
                }
            }
            ++result;
        }
        return result;
    }
};
