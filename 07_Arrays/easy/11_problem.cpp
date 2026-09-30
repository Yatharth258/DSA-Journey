//find the missing number in an array from 1 to n
//ex: if input = [1,2,3,5]  n=5

//brute force --> very easy search for all elemnets from 1 to n (linear search approach)

//second approach ==> use concept of hashing 
// use a hash array to store frequency of each elemnt and then itertae to the array , whosever index value is zero return that index 
// TC 2*O(n) or just simply O(n) and sc O(n)



//optiman approach
//method 1 --> sum of all n numbers we know formula , in the end n no. sum mei se array sum ko minus kardo
// TC 2*O(n) and sc O(1)


//method 2 --> using XOR  , XOR of the same numbers resluts in 0 , xor of any number with 0 is the same number 



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    int N = n-1;
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int xor1 = 0 , xor2 = 0;


    for (int i = 0; i < N; i++)
    {
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^n;


    cout<<(xor1^xor2);


    return 0;
}

//TC --> O(n)
//SC --> o(1)