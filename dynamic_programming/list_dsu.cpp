#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<vector<int> > nodes;
    int *rep;

    UnionFind(int n) {
        nodes.resize(n+1);
        rep = new int[n + 1];

        for (int i = 1; i <= n; ++i)
            rep[i] = i, nodes[i].push_back(i);
    }

    int find(int i, int j) {
        return rep[i] == rep[j];
    }

    int un(int i, int j) {
        int u = rep[i];
        int v = rep[j];

        if (u == v)
            return 0; // already in the same set

        if (nodes[u].size() < nodes[v].size()) // u should be the one with the larger size.
            swap(u, v);

        // Transfer all the elements in nodes[v] to nodes[u]
        while(!nodes[v].empty()) {
            int num = nodes[v].back();
            nodes[u].push_back(num);
            rep[num] = u;
            nodes[v].pop_back();
        }

        return 1;
    }
}; //default indexing is 1-based

int main() {
    int n; cin >> n;
	UnionFind dsu(n);
    dsu.un(1, 2);
    cout << dsu.find(1, 2) << '\n';
    cout << dsu.find(2, 3) << '\n';
    dsu.un(1, 3);
    cout << dsu.find(2, 3) << '\n';
	return 0;
}