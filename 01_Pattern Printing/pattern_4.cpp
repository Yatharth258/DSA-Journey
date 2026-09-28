// Enter the number : 5
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
        
            cout<<i+1<<" ";
        }
        
       cout << endl ;
    }
    return 0;
}