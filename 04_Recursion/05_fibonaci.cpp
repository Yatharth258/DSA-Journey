#include <bits/stdc++.h>
using namespace std;

int fibonaci(int n){
    if(n<=1) return n;
    

    return (fibonaci(n-1)+fibonaci(n-2));
}


int main() {

    int n;
    cout << "Enter number: ";
    cin >> n;

    int result = fibonaci(n);

    cout<<"Fibonacci no: "<<result;



    return 0;
}