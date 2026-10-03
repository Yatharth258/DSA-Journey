//Method 2 --> optimal approach ..> using set
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    if(nums.size() == 0){
        cout<<"Longest consecutive sequence is: 0";
        return 0;
    }
    int longest = 1;

    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x=it;
            while(st.find(x+1) != st.end()){
                x++;
                cnt++;
            }
            longest=max(cnt,longest);
        }

    }
    

        cout<<"Longest consecutive sequence is: "<<longest;

    return 0;
}

/*
Time Complexity: O(n) average
- Inserting n elements into unordered_set takes O(n) average.
- The outer loop runs n times.
- Each number is processed as part of a consecutive sequence only once.
- Overall TC = O(n) average.

Space Complexity: O(n)
- unordered_set stores up to n elements.
- Overall SC = O(n).
*/