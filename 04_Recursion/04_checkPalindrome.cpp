// check the number is palindrome or not usiong recursion

#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, string s) {

    // Base case
    if (i >= s.length() / 2) {
        return true;
    }

    // If characters don't match
    if (s[i] != s[s.length() - i - 1]) {
        return false;
    }

    // Check next pair
    return palindrome(i + 1, s);
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    if (palindrome(0, s)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}