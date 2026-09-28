// Enter the number : 5
// 0 
// 1 0 
// 0 1 0 
// 1 0 1 0 
// 0 1 0 1 0 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : ";
    cin>>n;


    int flip;
    for (int i = 0; i < n; i++){
        if(i%2==0) flip = 0;
        else flip = 1;

       for (int j = 0 ; j<=i; j++){
            cout<<flip<< " ";
            flip= 1-flip;
       }
       cout << endl ;
    }
    return 0;
}