//Find the nth root of any number 
//in case you do not find the perfect nth root then return -1


#include<bits/stdc++.h>
using namespace std;


// Calculate mid^x
long long power(int mid, int n)
{
    long long ans = 1;

    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans = ans * mid;
            n = n - 1;
        }
        else
        {
            mid = mid * mid;
            n = n / 2;
        }
    }

    return ans;
}

int main(){
    int n,x;

    cout<<"Enter the number : ";
    cin>>n;

    cout<<"Enter which root is to be find : ";
    cin>>x;

    int low = 1;
    int high = n;

    while(low<=high){
        int mid = low + (high - low) / 2;
        long long ans=power(mid,x);

        if(ans==n){
           cout<<"The nth root of the number is : "<<mid;
           return 0;
        }else if(ans>n){
            high=mid-1;
        }else{
            low=mid+1;
        } 
    }
    cout<<"The perfect nth root of that number dosent exist";
    
    return 0;
}

/*
    Time Complexity: O(log x * log n)

    Binary Search: O(log n)
    Power calculation: O(log x)

    Space Complexity: O(1)

    Example:
    n = 3, m = 27

    3^3 = 27

    Answer = 3
*/