#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > adj;
int n;

//0 -> red
//1 -> green

vector<int> bfs(int src, int col)
{
	queue<int> q;
	vector<int> dis(n + 1, -1);

	q.push(src);
	dis[src] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		//cout << i << ' ';

		for (pair<int,int>  nb : adj[i])
		{
			if (dis[nb.first] != -1 or nb.second != col)
				continue;

			q.push(nb.first);
			dis[nb.first] = dis[i] + 1;
		}
	}

	return dis;
}

int main()
{
	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j, col; cin >> i >> j >> col;
		adj[i].push_back({j, col});
		adj[j].push_back({i, col});
	}

	int src, dest; cin >> src >> dest;

	vector<int> ds = bfs(src, 0);
	vector<int> dd = bfs(dest, 1);

	int ans = INT_MAX;

	for (int i = 1; i <= n; ++i)
	{
		if (i == src or i == dest or ds[i] == -1 or dd[i] == -1)
			continue;

		ans = min(ans, ds[i] + dd[i]);
	}

	if (ans == INT_MAX)
		ans = -1;

	cout << ans << '\n';

	return 0;
}