// * * * * * * * * * * 
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 
// *                 * 
// * *             * * 
// * * *         * * * 
// * * * *     * * * * 
// * * * * * * * * * * 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number : ";
    cin>>n;


    // Upper half
    for (int i = 1; i <= n; i++) {

        // Left stars
        for (int j = 1; j <= n - i + 1; j++) {
            cout << "* ";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * i - 2; j++) {
            cout << "  ";
        }

        // Right stars
        for (int j = 1; j <= n - i + 1; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 1; i <= n; i++) {

        // Left stars
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << "  ";
        }

        // Right stars
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}