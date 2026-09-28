// check for prime numbers --> definition: a number which has only two factors (1 and itself)

#include<bits/stdc++.h>
using namespace std;

int main(){

   
    int N ;
    cout << "Enter the value of N : ";
    cin>>N;
    int cnt = 0 ;
  for (int i = 1 ; i*i<=N ; i++){ // we replace i <= sqrt(N) just for time , since sqrt function itself take some time
        if(N%i == 0){
            cnt++;
            if(i != N/i) {
                cnt++;
            }
        }

  }
 if(cnt == 2){
    cout<<"The given number is a Prime number";
 }else{
    cout<<"The given number is not a Prime number";
 }

   
    
    return 0;
}