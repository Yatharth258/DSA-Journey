//LINEAR SEARCH



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int s;
    cout<<"Enter the number to search: ";
    cin>>s;

    bool isPresent = false;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==s){
            cout<<"The given number is at the index: "<<i;
            isPresent = true;
            break;
        }
    }
    
    if(!isPresent){
        cout<<"The given elemnt is not present in an array";
    }


    return 0;
}