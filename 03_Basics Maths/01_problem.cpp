//count the number of didgits in a numnber 

#include<bits/stdc++.h>
using namespace std;

int main(){

    int count = 0;
    int N;
    cout << "Enter the value of N : ";
    cin>>N;

    while(N>0){
        count++;
        N/=10;
    }
    cout<< "The number of digits in N"<<" is :"<<count<<endl;
    return 0;
} // Time complexity --> O(log₁₀ N)



// method 2 


// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int N;
//     cout << "Enter the value of N: ";
//     cin >> N;

//     int count = (N == 0) ? 1 : log10(N) + 1;

//     cout << "The number of digits in " << N << " is: " << count << endl;

//     return 0;
// }