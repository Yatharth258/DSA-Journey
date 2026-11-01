// You are given n books, and each book has a certain number of pages. You also have m students.

// You have to allocate all books to the students such that:
// 1. Each student gets at least one book.
// 2. Books are allocated in order — you cannot skip a book.
// 3. A book cannot be divided between two students.
// 4. Your goal is to minimize the maximum number of pages assigned to any one student.



#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {

    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students++;
            pagesStudent = arr[i];
        }
    }

    return students;
}

int main() {

    int n, m;

    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the number of pages in each book:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> m;

    // If students are more than books,
    // allocation is not possible
    if (m > n) {
        cout << "Allocation is not possible." << endl;
        return 0;
    }

    int low = *max_element(arr.begin(), arr.end());

    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int students = countStudents(arr, mid);

        if (students > m) {
            // We need more students,
            // so increase the allowed pages
            low = mid + 1;
        }
        else {
            // Possible answer,
            // try to minimize the maximum pages
            high = mid - 1;
        }
    }

    cout << "Minimum possible maximum pages = " << low << endl;

    // TC: O(n log(sum of pages))
    //     Sorting is not required here.
    //
    // SC: O(1) extra space
    //     (Ignoring the input vector)

    return 0;
}