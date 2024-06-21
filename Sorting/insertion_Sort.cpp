// inserting an element in an already sorted list

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;
    cin>>n;
    int arr[100];
    int k;
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=n;i>0;i--){
        if(arr[i]>k){
            arr[i]=arr[i-1];
        }
    }
    n++;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}