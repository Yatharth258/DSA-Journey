// find the number who appears once in an array where all other element occurs twice

//method 1 --> use map to hash the array --> iterate through array and print that key whose value is 1--> TC O(n logn)  SC O(n)


//method 2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr^arr[i];
    }
    
    cout<<xorr;

    return 0;
}

//TC O(n)
//SC O(1)