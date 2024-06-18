#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// last called first out
void printN(int n){
    if(n==0) return;
    cout<<n<<endl;
    printN(n-1);
};

int main(){
    int n;
    cin>>n;
  
    printN(n);
    return 0;
}