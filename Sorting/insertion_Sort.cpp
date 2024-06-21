// inserting an element in an already sorted list

class Solution
{
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++){
            int curNum=arr[i], j=i-1;
            while(j>=0 && arr[j]>curNum){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j + 1] = curNum;
        }
    }
};