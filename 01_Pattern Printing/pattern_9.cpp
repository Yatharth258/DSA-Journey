// Enter the number : 5
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *

#include<bits/stdc++.h>
using namespace std;


void pattern7(int n ){
    for (int i = 0; i < n; i++){
       for (int j = 0 ; j<n-i-1 ; j++){
            cout << " ";
       }
       for(int k=0 ; k<(2*i)+1 ; k++){
        cout<<"*";
       }
       cout << endl ;
    }
    return;
}

void pattern8(int n){
     for (int i = 0; i < n; i++){
       for (int j = 0 ; j<i ; j++){
            cout << " ";
       }
       for(int k=0 ; k<(2*(n-i))-1 ; k++){
        cout<<"*";
       }
       cout << endl ;
    }
    return;
}


int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    pattern7(n);
    pattern8(n);

    return 0 ;
}