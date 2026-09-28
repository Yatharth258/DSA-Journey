void explainSet() {
    //1. It stored unique value
    //2. It stored value in sorted order 
set<int>st;


st.insert(1); // {1}
st.emplace(2); // {1, 2}
st.insert(2); // {1, 2}
st.insert(4); // {1, 2, 4}
st.insert(3); // {1, 2, 3, 4}

// Functionality of insert in vector
// can be used also, that only increases
// efficiency

// begin(), end(), rbegin(), rend(), size(),
// empty() and swap() are same as those of above

// {1, 2, 3, 4, 5}
auto it = st.find(3);
//here 'it' is an iterator which points to the location where 3 is present in the set


// {1, 2, 3, 4, 5}
auto it = st.find(6);
// if the elemt is not present in the set then i t always point to the location just after the last element 


// {1, 4, 5}
st.erase(5); // erases 5 // takes logarithmic time

int cnt = st.count(1); 
// returns only 1 or 0 , 1 if that elemt presnt otherwise 0

auto it = st.find(3);
st.erase(it); // it goes to the element where st is poniting and delete it 

// {1, 2, 3, 4, 5}
auto it1 = st.find(2);
auto it2 = st.find(4);
st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

// lower_bound() and upper_bound() function works in the same way
// as in vector it does.
// This is the syntax
auto it = st.lower_bound(2);
auto it = st.upper_bound(3);
}
