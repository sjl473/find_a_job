class Solution {
public:
    void solve(vector<vector<char>>& board) {
        edgeTraversal(board);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '?') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    void edgeTraversal(vector<vector<char>>& g) {
        for(int i = 0; i < g.size(); i++) {
            bfs(0, i, g);
            bfs(g[0].size() - 1, i, g);
        }
        for(int i = 0; i < g[0].size(); i++) {
            bfs(i, 0, g);
            bfs(i, g.size() - 1, g);
        }
    }
    void bfs(int m, int n, vector<vector<char>>& g) {
        int max_x = g[0].size();
        int max_y = g.size();
        if(g[n][m] == 'O') {
            g[n][m] = '?';
            queue<pair<int, int>> q;
            q.push(std::make_pair(m, n)); // x, y
            while(q.empty() == false) {
                int counter = q.size();
                while(counter != 0) {
                    int x = q.front().first;
                    int y = q.front().second;
                    if(x + 1 <= max_x - 1 && g[y][x + 1] == 'O') {
                        q.push(make_pair(x + 1, y));
                        g[y][x + 1] = '?';
                    }
                    if(y + 1 <= max_y - 1 && g[y + 1][x] == 'O') {
                        q.push(make_pair(x, y + 1));
                        g[y + 1][x] = '?';
                    }
                    if(x - 1 >= 0 && g[y][x - 1] == 'O') {
                        q.push(make_pair(x - 1, y));
                        g[y][x - 1] = '?';
                    }
                    if(y - 1 >= 0 && g[y - 1][x] == 'O') {
                        q.push(make_pair(x, y - 1));
                        g[y - 1][x] = '?';
                    }
                    --counter;
                    q.pop();
                }
            }
        }
    }
};


