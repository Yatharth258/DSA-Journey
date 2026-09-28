// E
// E D 
// E D C 
// E D C B 
// E D C B A

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
        
            cout<<char('A' + n - j - 1)<<" ";
        }
        
       cout << endl ;
    }
    return 0;
}