void explainPQ() {
 // like queue only , but data is been added in a way such that largest element get at the top or is the highest priority

 //Max heap
priority_queue<int>pq;

pq.push(5); // {5}
pq.push(2); // {5, 2}
pq.push(8); // {8, 5, 2}
pq.emplace(10); // {10, 8, 5, 2}


cout << pq.top(); // prints 10

pq.pop(); // {8, 5, 2}

cout << pq.top(); // prints 8

// size swap empty function same as others


// Minimum Heap
priority_queue<int, vector<int>, greater<int>> pq; // syntax for priority queue in which minimum element is at the top

pq.push(5); // {5}
pq.push(2); // {2, 5}
pq.push(8); // {2, 5, 8}
pq.emplace(10); // {2, 5, 8, 10}

cout << pq.top(); // prints 2

}