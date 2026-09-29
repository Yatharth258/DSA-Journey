//intersection of two array
//we will be storing duplicate arrays in this case if it occurs multiple times in both

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1;
    cout << "Enter the length of the first array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter the elements: ";
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

        int n2;
    cout << "Enter the length of the second array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter the elements: ";
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    vector<int>ans;
    int i=0;
    int j = 0;

    while (i<n1 && j<n2)
    {
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            ans.push_back(a[i]);
            j++;
            i++;
        }
    }
    
    

        cout<<"The intersection of both the array: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    

    return 0;
}

//TC --> O(n1+n2)
//SC --> O(1)