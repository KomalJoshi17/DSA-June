#include <bits/stdc++.h>
using namespace std;

class Solution{
    long long int mergeAndCount(long long arr[], long long left[], long long right[], int n1, int n2) {
        int i = 0, j = 0, k = 0;
        
        long long ans = 0;
        
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
                ans += n1 - i;
            }
            k++;
        }
        
        while(i < n1) {
            arr[k] = left[i];
            i++, k++;
        }
        
        while(j < n2) {
            arr[k] = right[j];
            j++, k++;
        }
        
        return ans;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        if(N == 1)
            return 0;
            
        long long *left = new long long[N/2];
        
        for(int i = 0; i < N/2; ++i)
            left[i] = arr[i];
            
        long long *right = new long long[N - N/2];
        
        for(int i = 0, j = N/2; j < N; ++j, ++i)
            right[i] = arr[j];
            
        return inversionCount(left, N/2) + inversionCount(right, N - N/2) + mergeAndCount(arr, left, right, N/2, N - N/2);
    }

};

int main() {
	// your code goes here
	return 0;
}