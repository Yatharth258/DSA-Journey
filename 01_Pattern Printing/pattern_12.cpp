// Enter the number : 4
// 1             1 
// 1 2         2 1 
// 1 2 3     3 2 1 
// 1 2 3 4 4 3 2 1 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < n; i++){
       

       for (int j = 0 ; j<=i; j++){
        cout << j+1<<" ";
       }
       for (int j = 0 ; j<(2*(n-i-1)); j++){
        cout <<"  ";
       }
       for (int j = i+1; j>=1; j--){
        cout << j<<" ";
       }
       
       cout << endl ;
    }
    return 0;
}