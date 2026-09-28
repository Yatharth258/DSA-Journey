void explainVector() {

    vector<int> v; 
    // Creates an empty vector of integers

    v.push_back(1);
    // Adds 1 at the end of the vector

    v.emplace_back(2);
    // Adds 2 at the end of the vector
    // push_back and emplace_back both add elements


    vector<pair<int, int>> vec;
    // Creates a vector where every element is a pair of integers

    vec.push_back({1, 2});
    // Adds the pair {1, 2} to the vector

    vec.emplace_back(1, 2);
    // Adds the pair {1, 2} to the vector
    // With emplace_back, we don't need to write { }


    vector<int> v1(5, 100);
    // Creates a vector of size 5
    // All 5 elements have the value 100


    vector<int> v2(5);
    // Creates a vector of size 5
    // All elements are initialized to 0


    vector<int> v3(5, 20);
    // Creates a vector of size 5
    // All 5 elements have the value 20


    vector<int> v4(v3);
    // Creates v4 as a copy of v3


    vector<int>::iterator it = v.begin();
    // Creates an iterator pointing to the first element of v


    it++;
    // Moves the iterator one position forward


    cout << *(it) << " ";
    // *it gives the value at the position where iterator is pointing


    it = it + 2;
    // Moves the iterator 2 positions forward


    cout << *(it) << " ";
    // Prints the value at the current iterator position


    vector<int>::iterator it2 = v.end();
    // end() points just AFTER the last element
    // It does NOT point to the last element itself


    vector<int>::reverse_iterator it3 = v.rend();
    // rend() points to the position just BEFORE the first element
    // Used with reverse iterators


    vector<int>::reverse_iterator it4 = v.rbegin();
    // rbegin() points to the LAST element
    // Used to traverse the vector in reverse


    cout << v[0] << " ";
    // v[0] accesses the first element using index


    cout << v.at(0);
    // at(0) also accesses the first element
    // at() performs bounds checking


    cout << v.back() << " ";
    // back() gives the LAST element of the vector


    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        // Starts from the first element
        // Continues until the iterator reaches end()
        // it++ moves to the next element

        cout << *(it) << " ";
        // Prints the value at the current iterator position
    }


    for (auto it = v.begin(); it != v.end(); it++) {
        // auto automatically understands the iterator's data type
        // This is shorter than writing vector<int>::iterator

        cout << *(it) << " ";
        // Prints the current element
    }

    for (auto it : v){
        cout<< it << " ";
        // for each loop for used for printing the vector 
    }
    

// {10, 20, 12, 23} ---> {10,12,23}
v.erase(v.begin()+1);

// {10, 20, 12, 23, 35}
v.erase(v.begin() + 2, v.begin() + 4); //// {10, 20, 35} [start, end)

// Insert function

vector<int>v(2, 100); // {100, 100}

v.insert(v.begin(), 300); // {300, 100, 100);

v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

// ---------------------------------------------------------
// insert() - Insert elements from another vector
// ---------------------------------------------------------

vector<int> copy(2, 50);
// Creates a vector of size 2
// Both elements are 50
// copy = {50, 50}

v.insert(v.begin(), copy.begin(), copy.end());
// Inserts all elements of 'copy' at the beginning of 'v'
//
// copy.begin() -> points to the first element of copy
// copy.end()   -> points just after the last element
//
// Example:
// v = {300, 10, 10, 100, 100}
// copy = {50, 50}
//
// After insert:
// v = {50, 50, 300, 10, 10, 100, 100}


// ---------------------------------------------------------
// size() - Number of elements
// ---------------------------------------------------------

// v = {10, 20}

cout << v.size();
// size() returns the number of elements in the vector
// Output: 2


// ---------------------------------------------------------
// pop_back() - Remove the last element
// ---------------------------------------------------------

// v = {10, 20}

v.pop_back();
// Removes the last element from the vector
//
// v = {10}


// ---------------------------------------------------------
// swap() - Exchange two vectors
// ---------------------------------------------------------

// v1 = {10, 20}
// v2 = {30, 40}

v1.swap(v2);
// Exchanges the contents of v1 and v2
//
// After swap:
// v1 = {30, 40}
// v2 = {10, 20}


// ---------------------------------------------------------
// clear() - Remove all elements
// ---------------------------------------------------------

v.clear();
// Removes ALL elements from the vector
// The vector becomes empty


// ---------------------------------------------------------
// empty() - Check whether vector is empty
// ---------------------------------------------------------

cout << v.empty();
// Returns:
// 1 (true)  -> vector is empty
// 0 (false) -> vector is not empty