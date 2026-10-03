//a leader in an array is basically a element in which elemnts on its right are smaller tha that , there can be multiple leader


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector<int> ans;
    int maxi=INT_MIN;
    for (int i = n-1; i >=0; i--)
    {
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }   
        maxi = max(arr[i],maxi);
    }
    

    sort(ans.begin(),ans.end());

    cout<<"Leaders elements are :";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}

// Time Complexity: O(n log n)
// 1. Traversing the array from right to left takes O(n).
// 2. In the worst case, all elements are leaders, so ans stores n elements.
// 3. Sorting ans takes O(n log n).
// Overall TC: O(n) + O(n log n) = O(n log n).

// Space Complexity: O(n)
// 1. The input array arr takes O(n) space.
// 2. The ans vector can store up to n elements, taking O(n) space.
// 3. The sorting algorithm may use O(log n) auxiliary stack space.
// Overall SC: O(n) (including the input array).