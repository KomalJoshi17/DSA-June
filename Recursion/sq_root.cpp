#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int p[], int p2[]) {
	for(int i = 0; i < n; ++i)
		if(p2[i] != p[p[i]])
			return false;
	return true;
}

int* findSqRoot(int q[]) {
	vector<vector<vector<int> > > cycles(n+1);

	vector<bool> vis(n);
	for(int i = 0; i < n; ++i) {
		if(vis[i])
			continue;
		vector<int> curCycle;
		curCycle.push_back(i);
		vis[i] = true;
		int cur = q[i];

		// cout << i << ' ';
		
		while(cur != i) {
			// cout << cur << ' ';
			curCycle.push_back(cur), vis[cur] = true, cur = q[cur];
		}
		// cout << '\n';

		cycles[curCycle.size()].push_back(curCycle);
	}

	int *ans = new int[n];

	for(int l = 1; l <= n; ++l) {
		if(l%2 == 0 and cycles[l].size() % 2 == 1) {
			delete ans;
			ans = new int[1];
			ans[0] = -1;
			return ans;
		}

		if(l%2 == 0) {
			for(int i = 0; i + 1 < cycles[l].size(); i += 2) {  // Merge ith vec & i+1th vec
				for(int id = 0; id < l; ++id) {
					ans[cycles[l][i][id]] = cycles[l][i+1][id];
					if(id+1 < l)
						ans[cycles[l][i+1][id]] = cycles[l][i][id+1];
				}
			}
		}
		else { // odd length
			for(int i = 0; i < cycles[l].size(); ++i) {
				for(int id = 0; id < l; ++id) {
					ans[cycles[l][i][id]] = cycles[l][i][((id-l/2)%l + l)%l];
				}
			}
		}
	}

	return ans;
}

int main() {
	cin >> n;
	int *q = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> q[i];

	int *p = findSqRoot(q);

	for(int i = 0; i < n; ++i) {
		cout << p[i] << ' ';

		if(p[i] == -1)
			break;
	}
	
	cout << '\n' << check(p, q);
	return 0;
}