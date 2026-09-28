//GCD AND HCF

//METHOD 1 --> Brute force approach


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n1 , n2;
    int gcd = 1;
    cout<<"Enter the values of n1 and n2 : ";
    cin>>n1>>n2;

    for(int i = min(n1,n2) ; i>=1 ; i--){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
            break;
        }
    }
    

    cout<<"The greatest common divisor of these two numbers are :"<<gcd;

    return 0;
}

// TC --> O(min(n1,n2))