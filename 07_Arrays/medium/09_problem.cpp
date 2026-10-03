//Longest consecutive sequence
//in this you will be given an array now you need to return length of longest consecutive sequence that can be obtained ex-1,2,3   45,46,47,48 .....

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    if(nums.size() == 0){
        cout<<"Longest consecutive sequence is: 0";
        return 0;
    }

    sort(nums.begin(), nums.end());

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = nums[i];
        }
        else if(lastSmaller != nums[i]){
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, cnt);
    }

    cout<<"Longest consecutive sequence is: "<<longest;

    return 0;
}

/*
Time Complexity: O(n log n)
- Sorting the array takes O(n log n).
- Traversing the array takes O(n).
- Overall TC = O(n log n).

Space Complexity: O(1) auxiliary space
- We only use a few extra variables.
- Sorting is done in-place.
- std::sort can use O(log n) recursion stack space.
*/