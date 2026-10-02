//rearrange an array with sign but whatever elemnts remains in the add , just write as it is

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), pos, neg;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] > 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    if(pos.size() > neg.size()) {
        for(int i = 0; i < neg.size(); i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        int index = neg.size() * 2;

        for(int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i = 0; i < pos.size(); i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        int index = pos.size() * 2;

        for(int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

// Time Complexity (TC): O(n) — traversing the array, separating elements, and rearranging them.

// Space Complexity (SC): O(n) — storing positive and negative elements in two separate vectors.