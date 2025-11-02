#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int find(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unite(vector<int>& parent, int i, int j) {
    int root_i = find(parent, i);
    int root_j = find(parent, j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int main() {
    int n = 5; 

    vector<Edge> edges = {
        {0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    int count = 0;
    int mincost = 0;
    cout << "Edge : Weight" << endl;

    for (const auto& edge : edges) {
        int root_u = find(parent, edge.u);
        int root_v = find(parent, edge.v);

        if (root_u != root_v) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
            mincost += edge.w;
            count++;
            unite(parent, root_u, root_v);
        }

        if (count == n - 1)
            break;
    }

    cout << "Minimum cost = " << mincost << endl;
    return 0;
}