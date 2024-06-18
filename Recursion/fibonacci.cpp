#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    int a=fibo(n-1);
    int b=fibo(n-2);
    return a+b;
}

int main(){
    int n;
    cin>>n;

    cout<<fibo(n);
    return 0;
}