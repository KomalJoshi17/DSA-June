#include<bits/stdc++.h>
using namespace std;
 
int32_t main() {
	int n, k; cin >> n >> k;
 
	vector<int> arr(n);
 
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
 
	sort(arr.begin(), arr.end());
 
	int i = 0, j = n - 1;
	int ans = 0;
 
	while (i <= j)
	{
		if (arr[i] + arr[j] > k)
			j--;
		else
			i++, j--;
		ans++;
	}
 
	cout << ans << '\n';
 
	return 0;
}