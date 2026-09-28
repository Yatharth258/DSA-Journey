//sum of n numbers

#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n == 0) return 0;
     
    return n + sum(n-1) ;
}



int main(){
    int n;
    cout<<"Enter the values of n :";
    cin>>n;

   int result = sum(n);
   cout<<result;

    return 0 ;
}


//similarly factorial of n could be much easier in the same way
// handle the case of 0 factorial sperately , i.e in case of 0 return 1 that n