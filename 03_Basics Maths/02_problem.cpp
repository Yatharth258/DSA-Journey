//reverse of a number 

#include<bits/stdc++.h>
using namespace std;

int main(){

    int rev = 0;
    int N ;
    cout << "Enter the value of N : ";
    cin>>N;

    while(N>0){
       rev = rev*10 + N%10;
       N/=10;
    }
    cout<< "The reverse of the  N"<<" is :"<<rev<<endl;
    return 0;
}