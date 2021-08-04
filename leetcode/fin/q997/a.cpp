using namespace std;
class Graph {
public:
    int total;
    vector<pair<list<int>, int>> adj;
    explicit Graph(int total_size) {
        this->total = total_size;
        this->adj = vector<pair<list<int>, int>>(this->total, std::pair<list<int>, int>());
    }
    void addEdge(int src, int dst) {
        this->adj[src].first.push_back(dst);
        this->adj[dst].second++;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        Graph* g = new Graph(n);
        for(int i = 0; i < trust.size(); i++) {
            g->addEdge(trust[i][0] - 1, trust[i][1] - 1);
        }
        for(int i = 0; i < g->total; i++) {
            int in = (*g).adj[i].second;
            int out = (*g).adj[i].first.size();
            if(in == g->total - 1 && out == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};


