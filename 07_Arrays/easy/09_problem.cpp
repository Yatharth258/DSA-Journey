//union of two sorted arrays
//we are not storing duplicate elemnts in this case

//BRUTE FORCE APPROACH
// arr1[] = [1,1,2,2,3,3,5];
// arr2[] = [2,2,2,3,3,4,4,6];
// set<int> st;
// for (int i = 0; i < arr1.size(); i++)
// {
//     st.insert(arr1[i]);
// }
// for (int i = 0; i < arr2.size(); i++)
// {
//     st.insert(arr2[i]);
// }

// int unioin[st.size()];
// int i=0;
// for(auto it : st){
//     union[i]=it;
//     i++;
// }
//TC--> O(n1logn + n2logn)+O(n1+n2)
//SC--> O(n1+n2)+O(n1+n2)


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1;
    cout << "Enter the length of the array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter the elements: ";
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

        int n2;
    cout << "Enter the length of the array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter the elements: ";
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    int i=0;
    int j=0;
    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (j<n2)
    {
         if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
          }
         j++;
    }
    while (i<n1)
    {
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
    }
    
    cout<<"The union of both the array: ";
    for (int i = 0; i < unionArr.size(); i++)
    {
        cout<<unionArr[i]<<" ";
    }
    
    

    return 0;
}

//TC -->o(N1 + N2)
//SC -->o(N1 + N2)