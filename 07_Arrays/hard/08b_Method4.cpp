//Mthod 4 --> Using XOR 

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

    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr^=arr[i]; // xor of numbers in array
        xr^=(i+1); // xor from 1 to n with the elemnts of array(we will find num here on basis of which we bifercate elemnts)
    }
    //now check which rightmost bit gives 1 in xor for bifercation
    int bitNo = 0;
    while(1){
        if((xr & (1 << bitNo)) != 0){ // right shift one from 0th index till index where it finds 1
            break;
        }
        bitNo++;
    }
    int zero = 0;
    int one = 0;

    //bifercating array elemnts
    for (int i = 0; i < n; i++)
    {
        // part of one club
        if((arr[i] & (1<<bitNo)) !=0){
            one^=arr[i];
        }// part of zero club
        else{
            zero^=arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // part of one club
        if((i & (1<<bitNo)) !=0){
            one^=i;
        }// part of zero club
        else{
            zero^=i;
        }
    }
  //now after this we have missing and repeating numbers stored in zero and one but dont know exctly which one is missing or repeating

  int cnt=0;
  for (int i = 0; i < n; i++)
  {
    if(arr[i]==zero) cnt++;
  }

  int x,y;
  if (cnt==0){
    x=one;
    y=zero;
  }else{
    x=zero;
    y=one;
  }


    cout<<"Repeating number = "<<x<<endl;
    cout<<"Missing number = "<<y;


    return 0;
}

//TC O(N)
//SC O(1)