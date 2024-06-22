#include <bits/stdc++.h>
using namespace std;

/*
    Just to be clear, there is scope
    of further optimisation. Put on
    thinking hats and figure it out.
*/
void bubbleSort(int arr[], int n) {
    // N - 1 steps
    for(int it = 1; it <= n - 1; ++it) {
        /*
            In each step, swap arr[i] &
            arr[i + 1] if required.
        */
        for(int i = 0; i + 1 < n; ++i)
            if(arr[i] > arr[i + 1])
                swap(arr[i], arr[i+1]);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    bubbleSort(arr, n);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';

	return 0;
}
