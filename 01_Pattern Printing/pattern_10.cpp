// Enter the number : 5
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < (2*n)-1; i++){
       if(i<n){
        for (int j = 0 ; j<=i ; j++){
            cout << "* ";
       }
       }else{
        for(int j=0 ; j<(2*n)-i-1; j++){
            cout << "* ";
        }
       }
       
       cout << endl ;
    }
    return 0;
}


