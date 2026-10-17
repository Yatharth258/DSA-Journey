// count the total number of subarray with the xor as k

//M1 --> generate all the subarray and take xor of each (Brute force approach)

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

    int k;
    cout << "Enter k: ";
    cin >> k;

    int xr=0;
    map<int , int>mpp;
    mpp[xr]++;  // added (0,1) to the map
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        xr = xr^arr[i];

        int x = xr^k; // formula dervied just remember

       cnt+= mpp[x]; // inmp concept of map
       //if the x doesnt appear then cnt takes 0 otherwise the value of that key x is considered
        mpp[xr]++;
    }


    cout<<"The number of times the target k xor occured: " << cnt;
    
    


    return 0;
}


//TC O(nlogn) or O(n) depending on map search complexity
//SC O(n) in worst case