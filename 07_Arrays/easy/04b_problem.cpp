


#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout<<"Enter the length of the array :";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter the elemts of the array : ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }

    int i=0;
    for (int j = 0; j < n; j++)
    {
        if(arr[i]!=arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    

     cout << "New array: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

//TC O(n) both best and worst case
//SC O(n)