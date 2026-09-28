// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4


 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the square size : ";
    cin>>n;
    int top , bottom , right , left ;
    for (int i = 0; i < 2*n - 1; i++){
        for (int j = 0; j < 2*n - 1; j++){
            top = i;
            bottom = 2*n -2-i;
            left = j;
            right = 2*n -2 - j;
           cout<< n-(min(min(top , bottom) , min (right , left)))<< " ";
        }
        
       cout << endl ;
    }
    return 0;
}