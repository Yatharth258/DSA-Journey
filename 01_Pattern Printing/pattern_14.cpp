//       A
//     A B A 
//   A B C B A 
// A B C D C B A

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for(int j = 0 ; j<n-i; j++){
            cout<<"  ";
        }
        for (char ch = 'A'; ch <= 'A' + i; ch++){
        
            cout<< ch<< " ";
        }
        for (char ch = 'A' + i - 1; ch >= 'A'; ch--) {
        cout << ch << " ";
    }

        
       cout << endl ;
    }
    return 0;
}