//slection sort 
//find the smallest and swap it with the first element and contnue with second min and so on 


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

        for (int i = 0; i < n-1; i++){   //n-1 beacuse last element jo ham swap karege outer loop mei wo n-2 hoga 
            int minn = i;
            for (int j = i+1; j < n; j++) {
                if(arr[minn]>arr[j]){
                    minn=j;
                }
            }
            if (i != minn) {
              swap(arr[i], arr[minn]);
            }

        }
        
        cout<<"Sorted array :";
        for (int i = 0; i < n; i++)
        {
           cout<<arr[i]<<" ";
        }
        
    


    return 0;
}