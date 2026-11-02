//find the median of two sorted arrays 


//METHOD 1 :add the both sorted array in sorted manner , then find out the median in the new generated array
// double median(vector<int>& a, vector<int>& b) {
//     vector<int> arr3;
//     int n1 = a.size(), n2 = b.size();
//     int i = 0;
//     int j = 0;
//     while (i<ni && i < n2) {
//         if(a[i] < b[j]) arr3.push_back(a[i++]);
//         else arr3.push_back(b[j++]);
//     }
//     while(i<n1) arr3.push_back(a[i++]);
//     while(j<n2) arr3.push_back(b[j++]);
    
//     if(n%2 == 1){
//         return arr3[n/2];
//     }
//     return (double) ((double) (arr3[n/2]) + (double) (arr3 [n/2 - 1])) / 2.0;
// }


// METHOD2 : OPTIMAL SOLUTION


#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& a, vector<int>& b) {

    int n1 = a.size();
    int n2 = b.size();

    // Always do binary search on smaller array
    if(n1 > n2) return findMedian(b, a);

    int low = 0;
    int high = n1;

    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while(low <= high) {

        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {

            if(n % 2 == 1) {
                return max(l1, l2);
            }

            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }

        else if(l1 > r2) {
            high = mid1 - 1;
        }

        else {
            low = mid1 + 1;
        }
    }

    return 0;
}

int main() {

    int n1, n2;

    cout << "Enter the size of first array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter elements of first sorted array:\n";
    for(int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter elements of second sorted array:\n";
    for(int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    double ans = findMedian(a, b);

    cout << fixed << setprecision(6);
    cout << "Median = " << ans << endl;

    // TC: O(log(min(n1, n2)))
    // SC: O(1)

    return 0;
}