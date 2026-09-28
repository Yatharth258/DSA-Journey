//Armstorng number 
// ex - 153
// = 1³ + 5³ + 3³
// = 1  + 125 + 27
// = 153



#include<bits/stdc++.h>
using namespace std;

int main(){

    int sum = 0;
    int N ;
    cout << "Enter the value of N : ";
    cin>>N;

    int copy = N;
    int digits = to_string(N).size();

    while(N>0){
        int i = N%10;
       sum += pow(i, digits);
       N/=10;
    }

    if(copy == sum){
        cout<< "The given number is an Armstrong number ";
    }else{
        cout<< "The given number is not an Armstong number";
    }
    
    return 0;
}