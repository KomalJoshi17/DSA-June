#include <iostream>

using namespace std;

int main() {
    // Input for N (size of the array) and Q (number of queries)
    int N, Q;
    cin >> N >> Q;

    // Initialize an array of size N with all zeroes
    int* arr = new int[N](); // Use dynamic memory allocation

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;

        // Increment at index l
        arr[l] += 1;

        // Decrement at index r + 1 if it's within bounds
        if (r + 1 < N)
            arr[r + 1] -= 1;
    }

    // Convert the array to a prefix sum array
    for (int i = 1; i < N; ++i)
        arr[i] += arr[i - 1];

    // Print the final array
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";

    // Free the allocated memory
    delete[] arr;

    return 0;
}
