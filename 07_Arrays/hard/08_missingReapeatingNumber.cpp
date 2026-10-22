//find the missing and repeating number
//you will be given an array in which n will be given , in that array elemnts will be from 1 to n , but 1 number will be missing but one number will be repeating , you need to print out these two numbers

//Method 1 --> Brute force

//Method 2 --> Hashing 
//we will declare hash array(initially evry value will be zero) and iterate thorugh original array and find out frequency of each of elemnt then iterate once more to find whose count = 0 or 2
//TC O(2n) ans SC O(n)


//Method 3 --> Basic mathematics

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

    // we will find S - Sn = X-Y and S^2 - S^2n = (X+Y)(X-Y)  ; where X= missing and Y= repeating
    long long Sn = (n*(n+1))/2;
    long long S2n = (n * (n+1) * (2*n+1))/6;
    long long S=0;
    long long S2=0;

    for (int i = 0; i < n; i++)
    {
        S+=arr[i];
        S2+=((long long)arr[i]*(long long)arr[i]);
    }

    long long val1 = S - Sn;//x-y
    long long val2 = S2 - S2n;
    val2 = val2/val1;  //x-y

    long long x = (val1+val2)/2;
    long long y = x-val1;

    cout<<"Repeating number = "<<x<<endl;
    cout<<"Missing number = "<<y;


    return 0;
}


//TC O(N)
//SC O(1)