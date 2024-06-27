#include<bits/stdc++.h>
using namespace std;
 
int32_t main() {
	int n; cin >> n;
	vector<long long> arr(n+1);
	vector<long long> pre(n + 2, 0), suf(n + 2, 0);
 
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
 
	sort(arr.begin() + 1, arr.end());
 
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + arr[i];
 
	for (int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + arr[i];
 
	long long ans = LLONG_MAX;
 
	for (int i = 1; i <= n; ++i)
		ans = min(ans, (i - 1) * arr[i] - pre[i - 1] + suf[i + 1] - (n - i) * arr[i]);
 
	cout << ans << '\n';
 
	return 0;
}