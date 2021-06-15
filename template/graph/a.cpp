#include "iostream"
#include "list"
#include "vector"
#include "stack"
using namespace std;
class Graph {
public:
    int num_of_vertex;
    vector<list<int>> adj;
public:
    Graph(int num_of_vertex) {
        this->num_of_vertex = num_of_vertex;
        adj = vector<list<int>>(num_of_vertex);
    }
    void AddEdge(int v, int index) {
        adj[v].push_back(index);
    }
    void DFSUtil(int v, vector<bool> &is_visited) {
        int cursor = v;
        stack<int> s;
        s.push(v);
        while(true) {
            if(s.empty()) {
                break;
            }
            cursor = s.top();
            s.pop();
            if(is_visited[cursor] == false) {
                is_visited[cursor] = true;
                // print dfs
            }
            for(auto i = adj[cursor].begin(); i != adj[cursor].end(); i++) {
                if(is_visited[*i] == false) {
                    s.push(*i);
                }
            }
        }
    }
    void DFS() {
        vector<bool> is_visited(this->num_of_vertex, false);
        for(int i = 0; i <= this->num_of_vertex - 1; i++) {
            if(is_visited[i] == false) {
                DFSUtil(i, is_visited);
            }
        }
    }
};
