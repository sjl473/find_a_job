#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int> >& isConnected) {
        if(isConnected.size() == 0) {
            return 0;
        }
        if(isConnected.size() == 1) {
            return 1;
        }
        int result = 0;
        int g_size = isConnected.size();
        vector<bool> vis = vector<bool>(g_size, false);
        queue<int> q;
        for(int i = 0; i < isConnected.size(); i++) {
            if(vis[i] == false) {
                q.push(i);
                while(q.empty() == false) {
                    int curr = q.front();
                    for(int j = 0; j < isConnected[i].size(); j++) {
                        if(isConnected[curr][j] == 1 && vis[curr] == false) {
                            q.push(j);
                        }
                    }
                    q.pop();
                    vis[curr] = true;
                }
            } else {
                continue;
            }
            ++result;
        }
        return result;
    }
};
