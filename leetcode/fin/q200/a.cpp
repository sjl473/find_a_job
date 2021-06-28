class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int nums_of_islands = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i <= grid.size() - 1; i++) {
            for(int j = 0; j <= grid[i].size() - 1; j++) {
                if(grid[i][j] == '1') {
                    ++nums_of_islands;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while(q.empty() == false) {
                        pair<int, int> node = q.front();
                        q.pop();
                        int row = node.first;
                        int col = node.second;
                        if(row + 1 < rows && grid[row + 1][col] == '1') {
                            q.push(make_pair(row + 1, col));
                            grid[row + 1][col] = '0'
                        }
                        if(col + 1 < cols && grid[row][col + 1] == '1') {
                            q.push(make_pair(row, col + 1));
                            grid[row][col + 1] ='0';
                        }
                        if(row - 1 >= 0 && grid[row - 1][col] == '1'){
                            q.push(make_pair(row - 1,col));
                            grid[row - 1][col] ='0';
                        }
                        if(col - 1 >= 0 && grid[row][col - 1] == '1'){
                            q.push(make_pair(row, col - 1));
                            grid[row][col - 1] ='0';
                        }
                    }
                }
            }
        }
        return nums_of_island;
    }
};

