// GCD OR HCF
//Method 2 --> Euclidean algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n1 , n2;
    int gcd;
   
    cout<<"Enter the values of n1 and n2 : ";
    cin>>n1>>n2;

    while(n1 > 0 && n2 > 0){
        if(n1>n2){
            n1=n1%n2;
        }else{
            n2=n2%n1;
        }
    }
            if(n1 == 0){
            gcd = n2;
        }else{
            gcd = n1;
        }
    

    cout<<"The greatest common divisor of these two numbers are :"<<gcd;

    return 0;
}

// TC --> O(log(min(n1,n2)))​