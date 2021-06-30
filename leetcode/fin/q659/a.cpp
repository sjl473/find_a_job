#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_y = grid.size();
        if(max_y == 0) {
            return 0;
        }
        int max_x = grid[0].size();
        int nums_of_islands = 0;
        int curr_size = 0;
        int max_size = 0;
        for(int i = 0; i <= max_y - 1; i++) {
            for(int j = 0; j <= max_x - 1; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while(q.empty() == false) {
                        int counter = q.size();
                        while(counter != 0) {
                            int x = q.front().second;
                            int y = q.front().first;
                            if(x + 1 <= max_x - 1) {
                                if(grid[y][x + 1] == 1) {
                                    q.push(make_pair(y, x + 1));
                                    grid[y][x + 1] = 0;
                                }
                            }
                            if(y + 1 <= max_y - 1) {
                                if(grid[y + 1][x] == 1) {
                                    q.push(make_pair(y + 1, x));
                                    grid[y + 1][x] = 0;
                                }
                            }
                            if(x - 1 >= 0) {
                                if(grid[y][x - 1] == 1) {
                                    q.push(make_pair(y, x - 1));
                                    grid[y][x - 1] = 0;
                                }
                            }
                            if(y - 1 >= 0) {
                                if(grid[y - 1][x] == 1) {
                                    q.push(make_pair(y - 1, x));
                                    grid[y - 1][x] = 0;
                                }
                            }
                            counter--;
                            q.pop();
                            curr_size++;
                        }
                    }
                    max_size = std::max(curr_size, max_size);
                }
                curr_size = 0;
            }
        }
        return max_size;
    }
};
