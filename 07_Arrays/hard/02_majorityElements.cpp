//Majority elements (grester than n/3 times)

//Method 1 --> Brute force --> Just check of each elemnts like wether is it grater than (n/3) and in last store them in a list

//Method 2 --> create a hasmap and store frequncy --> then iterate over map ans then store those value whose freq>n/3

//Method 3 -->little optimize version of method 2 only
// vector<int> majorityElement(vector<int> v) {
//     vector<int> ls;
//     map<int, int> mpp;

//     int n = v.size();
//     int mini = (int)(n / 3) + 1;

//     for (int i = 0; i < n; i++) {
//         mpp[v[i]]++;

//         if (mpp[v[i]] == mini) {
//             ls.push_back(v[i]);

//             if (ls.size() == 2)
//                 break;
//         }
//     }

//     sort(ls.begin(), ls.end());

//     return ls;
// }


//Method 4--> most optimal approach

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

    int mini = int(n/3)+1;
    int cnt1 = 0 , cnt2= 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(cnt1 == 0 && arr[i] != el2){
            el1 = arr[i];
            cnt1=1;
        }else if(cnt2 == 0 && arr[i] != el1){
            el2 = arr[i];
            cnt2=1;
        }else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

        vector<int> ls;
        cnt1=0 , cnt2=0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==1) cnt1++;
            if(arr[i] == el2) cnt2++;
        }

        if(cnt1>=mini) ls.push_back(el1);
        if(cnt2>=mini) ls.push_back(el2);


    
        for (int i = 0; i < ls.size(); i++)
        {
            cout<<ls[i]<<" ";
        }
        

    return 0;
}


//TC O(n)  {o(2n)}
//SC O(1)