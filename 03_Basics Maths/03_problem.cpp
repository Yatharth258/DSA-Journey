//check palindrome

#include<bits/stdc++.h>
using namespace std;

int main(){

    int rev = 0;
    int N ;
    cout << "Enter the value of N : ";
    cin>>N;

    int copy = N;

    while(N>0){
       rev = rev*10 + N%10;
       N/=10;
    }

    if(copy == rev){
        cout<< "The given number is palindrome";
    }else{
        cout<< "The given number is not palindrome";
    }
    
    return 0;
}