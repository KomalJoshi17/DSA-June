#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    int *pr;
    int *sz;
    int numComps;

    UnionFind(int n) {
        pr = new int[n + 1];
        sz = new int[n + 1];
        numComps = n;

        for (int i = 1; i <= n; ++i)
            pr[i] = i, sz[i] = 1;
    }

    int root(int i) {
        if (pr[i] == i)
            return i;

        return pr[i] = root(pr[pr[i]]);
    }

    int find(int i, int j) {
        return (root(i) == root(j));
    }

    int un(int i, int j) {
        int u = root(i);
        int v = root(j);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        pr[v] = u;
        sz[u] += sz[v];

        numComps -= 1;
        return 1;
    }
}; //default indexing is 1-based

int main() {
    int n, m; cin >> n >> m;
	set<pair<int,int> > edges;
    while(m--) {
        int i, j; cin >> i >> j;
        edges.insert({i, j});
    }
    int d; cin >> d;
    int cut[d][2];
    for(int i = 0; i < d; ++i) {
        cin >> cut[i][0] >> cut[i][1];
        edges.erase({cut[i][0], cut[i][1]});
        edges.erase({cut[i][1], cut[i][0]});
    } // After this, edges will only have the
    // finally uncut wires.
    
    UnionFind dsu(n);
    for(pair<int,int> e : edges)
        dsu.un(e.first, e.second);
    
    vector<int> ans;
    for(int i = d - 1; i >= 0; --i) {
        ans.push_back(dsu.numComps);
        dsu.un(cut[i][0], cut[i][1]);
    }

    reverse(ans.begin(), ans.end());
    for(int num : ans)
        cout << num << '\n';
	return 0;
}
