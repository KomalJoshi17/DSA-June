#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// time space log n
int power(int n){
    if(n==1) return 1;

    if(n%3==0){
        return power(n/3);
    }
    if(n%3!=0 || n<=0){
        return 0;
    }
};

int main(){
    int n;
    cin>>n;
    bool ans=power(n);
    cout<<ans;
    return 0;
}