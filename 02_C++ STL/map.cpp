
void explainMap() {
// values are stored in key value pair , keys are unique
// keys are stored in sorted order 


map<int, int> mpp;
map<int, pair<int, int>> mpp;
map< pair<int, int>, int> mpp;

mpp[1] = 2; // --> {1,2}
mpp.emplace({3, 1}); 
mpp.insert({2, 4}); //--> [{1,2},{2,4},{3,1}]


mpp[{2,3}] = 10; // --> {{2,3} , 10}



for(auto it: mpp) { // prints key value in sorted order of key
cout << it.first << " " << it.second << endl;
}

cout << mpp[1]; //--> 2 
cout << mpp[5];// --> 0/null , since 5 key is not present yet in mpp

auto it = mpp.find(3);
cout << *(it).second;


auto it = mpp.find(5); // since 5 is not there so it will point to the end just after the map end 


// This is the syntax
auto it = mpp.lower_bound(2);
auto it = mpp.upper_bound(3);


// erase, swap, size, empty, are same as above
}