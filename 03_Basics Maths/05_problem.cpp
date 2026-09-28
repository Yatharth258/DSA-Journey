// find all divisors 




#include<bits/stdc++.h>
using namespace std;

int main(){

   
    int N ;
    cout << "Enter the value of N : ";
    cin>>N;
    vector<int> ls ;
  for (int i = 1 ; i*i<=N ; i++){ // we replace i <= sqrt(N) just for time , since sqrt function itself take some time
        if(N%i == 0){
            ls.push_back(i);
            if(i != N/i) {
                ls.push_back(N/i);
            }
        }

  }
  sort(ls.begin() , ls.end());
  for(auto it : ls){
    cout<<it<<endl;
  }

   
    
    return 0;
}
//TC-->
// Finding divisors → O(√N)
// Sorting          → O(k log k)
// Total             → O(√N + k log k)
// where k = number of divisors of N.




//Method  2 is brute force method 