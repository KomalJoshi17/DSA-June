#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
    // if a should come before b
    // return true
    // otherwise false

    if(a > b)
        return true;

    return false;
}

int main() {
    int n = 4;
    int arr[] = {4, 1, 3, 2};
    sort(arr, arr + n, comp);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    vector<int> v = {3, 1, 2, 4, 5};

    sort(v.begin(), v.end());

    for(int num : v)
        cout << num << ' ';
    cout << '\n';
	return 0;
}
