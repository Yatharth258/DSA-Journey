//maximum consecutive ones in an arrya of 0 and 1



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
    int maxx = 0;
    int count = 0;

    for (int  i = 0; i < n; i++)
    {
        if(arr[i]==1){
            count++;
            maxx = max(maxx , count);
        }else count=0;
    }


    cout<<maxx;
    



    return 0 ;
}