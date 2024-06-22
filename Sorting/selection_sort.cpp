#include <bits/stdc++.h>
using namespace std;

/*
Just to be clear, there is scope
of further optimisation. Put on
thinking hats and figure it out.
*/
void selectionSort(int arr[], int n) {
    /*
        Will place the (i+1)th
        smallest element to the
        right place in ith iteration
    */
    for(int i = 0; i < n; ++i) {
        int min_id = i;
        for(int j = i + 1; j < n; ++j)
            if(arr[j] < arr[min_id])
                min_id = j;
        
        // Swap arr[i] and arr[min_id]
        swap(arr[i], arr[min_id]);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    selectionSort(arr, n);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';

	return 0;
}

