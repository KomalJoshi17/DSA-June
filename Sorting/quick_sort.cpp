#include <bits/stdc++.h>
using namespace std;

// Something to do good random selection
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int l, int r) {
        if(l >= r)
            return;

        int id = partition(arr, l, r);

        quickSort(arr, l, id - 1);
        quickSort(arr, id + 1, r);
    }
    
    public:
    int partition (int arr[], int l, int r) {
        int pivotId = rng() % (r - l + 1) + l;
	    swap(arr[r], arr[pivotId]);
	    
	    vector<int> smaller, larger;
	    int pivotElement = arr[r];
	    
	    for(int i = l; i < r; ++i)
	        if(arr[i] <= pivotElement) {
	            smaller.push_back(arr[i]);
	        }
	        else {
	            larger.push_back(arr[i]);
	        }
	        
	   // Put back the elements correctly to the `arr`
        int id = l;
        for(int i = 0; i < smaller.size(); ++i) {
            arr[id++] = smaller[i];
        }
        
        arr[id] = pivotElement;
        int pivotIndex = id;
        id++;
        
        for(int i = 0; i < larger.size(); ++i) {
            arr[id++] = larger[i];
        }
        
        return pivotIndex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}