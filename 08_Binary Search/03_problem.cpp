//find the first and last occurence of x{target}
//in case x does not occur return [-1,-1]

#include <bits/stdc++.h>
using namespace std;

// Lower Bound: first index where arr[i] >= target
int lowerBound(vector<int>& arr, int target , int n) 
{

    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}


// Upper Bound: first index where arr[i] > target
int upperBound(vector<int>& arr, int target , int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in sorted order: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int lb = lowerBound(arr , target , n);
    if(lb==n || arr[lb] != target){ // it means that elemnt is either not present or grater than all other elemmts of array
        cout<<"First and last occurence : {-1,-1}";
    }else{
        cout<<"First occurence : "<<lb<<endl;
        cout<<"Last occurence : "<<(upperBound(arr , target , n)-1);
    }

    return 0;
}

//TC O(2*logn)
//SC O(1)