//move all  zeros in the array to the last

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

    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==0){
            swap(arr[i],arr[j]);
            j--;
        }
        else i++;
    }


        cout << "New array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//TC O(n)
//SC O(1)