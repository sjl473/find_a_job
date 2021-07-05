class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int max_y = matrix.size();
        if (max_y == 0)
        {
            vector<vector<int>> res;
            return res;
        }
        int max_x = matrix[0].size();
        vector<vector<int>> dst(max_y, vector<int>(max_x, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < max_y; i++)
        {
            for (int j = 0; j < max_x; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dst[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (q.empty() == false)
        {
            auto f = q.front();
            // up down left right
            // x, y
            int x = f.second;
            int y = f.first;
            pair<int, int> up = make_pair(y - 1, x);
            pair<int, int> down = make_pair(y + 1, x);
            pair<int, int> left = make_pair(y, x - 1);
            pair<int, int> right = make_pair(y, x + 1);
            if (up.first >= 0)
            {
                if (dst[y][x] + 1 < dst[y - 1][x])
                {
                    dst[y - 1][x] = dst[y][x] + 1;
                    q.push(up);
                }
            }
            if (down.first < max_y)
            {
                if (dst[y][x] + 1 < dst[y + 1][x])
                {
                    dst[y + 1][x] = dst[y][x] + 1;
                    q.push(down);
                }
            }
            if (left.second >= 0)
            {
                if (dst[y][x] + 1 < dst[y][x - 1])
                {
                    dst[y][x - 1] = dst[y][x] + 1;
                    q.push(left);
                }
            }
            if (right.second < max_x)
            {
                if (dst[y][x] + 1 < dst[y][x + 1])
                {
                    dst[y][x + 1] = dst[y][x] + 1;
                    q.push(right);
                }
            }
            q.pop();
        }
        return dst;
    }
};
