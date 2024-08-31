// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
void towerOfHanoi(int noOfT,char from_T,char to_T,char help_T){
    //base case
    if(noOfT==0){
        return;
    }
    towerOfHanoi(noOfT-1,from_T,help_T,to_T);
    cout<<"move disk "<<noOfT<<" from rod "<<from_T<<" to rod"<<to_T<<endl;
    towerOfHanoi(noOfT-1,help_T,to_T,from_T);

}
int main(){
    towerOfHanoi(3,'A','C','B');
    return 0;
}