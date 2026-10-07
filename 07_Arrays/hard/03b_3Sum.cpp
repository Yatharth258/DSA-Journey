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

    int target;
    cout << "Enter target: ";
    cin >> target;

    sort(arr.begin() , arr.end());

    vector<vector<int>> ans;

for (int i = 0; i < n; i++)
{
    if(i > 0 && arr[i] == arr[i-1])
        continue;

    int j = i + 1;
    int k = n - 1;

    while(j < k)
    {
        int sum = arr[i] + arr[j] + arr[k];

        if(sum < target)
        {
            j++;
        }
        else if(sum > target)
        {
            k--;
        }
        else
        {
            vector<int> temp = {arr[i], arr[j], arr[k]};
            ans.push_back(temp);

            j++;
            k--;

            while(j < k && arr[j] == arr[j-1])
                j++;

            while(j < k && arr[k] == arr[k+1])
                k--;
        }
    }
}
    
    for(auto it: ans){
        for(auto x: it){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)   // excluding the output vector