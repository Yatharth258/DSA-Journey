//2 sum problem
//given one array and a target , we need to find out index like which two element whose sum equals that target

//BRUTE FORCE METHOD --> Easy chech each two pair and based on that give output of those two index


//METHOD 2 --> using maps

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

    int tar;
    cout<<"Enter the target :";
    cin>>tar;

    bool isPresent=false;
    map<int , int> mpp;
    for (int i = 0; i < n; i++)
    {
            int a = arr[i];
            int more = tar-a;
            if(mpp.find(more) != mpp.end()){
                cout<<mpp[more]<<" "<<i<<endl;
                isPresent=true;
            }
            mpp[a] = i;
    }

    if(!isPresent){
        cout<<"The given target is not present in the array";
    }
    



    return 0 ; 
}

// Time Complexity: O(n log n)
// We traverse the array once, and each map search (find) and insertion takes O(log n).

// Space Complexity: O(n)
// In the worst case, the map stores all n distinct elements.