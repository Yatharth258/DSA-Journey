//  Print name 5 times 
//  print linearly from 1 to n 
//  print from n to 1 




#include<bits/stdc++.h>
using namespace std;

void printName(int n){
    if(n==0) {
        cout<<endl;
        return ;
    }
    cout<<"Yatharth"<<" ";
    printName(n-1);
}

void printNum(int n){
    if(n==0) {
        cout<<endl;
        return ;
    }
    cout<<n<<" ";
    printNum(n-1);
}


void printRev(int n){
    if(n==0) {
        cout<<endl;
        return ;
    }
    int rev=1;
    printRev(n-1);
    cout<<n<<" ";
}


int main(){
    int n;
    cout<<"Enter the values of n :";
    cin>>n;

    printName(n);
    printNum(n);
    printRev(n);


    return 0 ;
}