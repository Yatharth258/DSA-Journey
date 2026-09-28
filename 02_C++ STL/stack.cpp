
void explainStack() { // works onthe principle of last in first out

stack<int> st;

//in stack there are only three functions push/emplace , pop , top (top of the stack)

st.push(1); // {1}
st.push(2); // {2, 1}
st.push(3); // {3, 2, 1}
st.push(3); // {3, 3, 2, 1}


st.emplace(5); // {5, 3, 3, 2, 1}

cout << st.top(); // prints 5 "** st[2] is invalid ** , i.e. indexing is not allowed"

st.pop(); // st looks like {3, 3, 2, 1}

cout << st.top(); // 3
cout << st.size(); // 4 {3,3,2,1}
cout << st.empty(); // false


stack<int>st1, st2;
st1.swap(st2);
}
