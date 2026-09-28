// A 
// A B 
// A B C 
// A B C D 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for (char ch = 'A'; ch <= 'A' + i; ch++){
        
            cout<< ch<< " ";
        }
        
       cout << endl ;
    }
    return 0;
}