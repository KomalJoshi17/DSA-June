#include <bits/stdc++.h>
using namespace std;

int func(int k) {
	int ans = 0;
	while(k > 0) {
		ans += k;
		k /= 10;
	}
	return ans;
}

int main() {
	int n = 1370;
	// f(x) = n
	// f(x) = x + x/10 + x/100 + ....
	// n = x + x/10 + x/100+ .....
	// n > x
	int s = 0, e = n;
	int ans = -1;
	while(s <= e) {
		int mid = s + (e - s) / 2;
		int f_mid = func(mid);
		if(f_mid == n) {
			ans = mid;
			break;
		} else if(f_mid > n) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	cout<<ans;
	return 0;
}