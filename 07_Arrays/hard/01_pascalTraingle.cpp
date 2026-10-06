#include <bits/stdc++.h>
using namespace std;

/*
    PASCAL'S TRIANGLE

    We are solving 3 problems:

    1. Given row and column -> find the element
    2. Given a row -> print that complete row
    3. Given n -> print the complete Pascal's triangle
*/


// OPTION 1

void findElement(int row, int column)
{
    /*
        Formula:
        Element at row r and column c is:
                    (r-1) C (c-1)
    */

    int n = row - 1;
    int r = column - 1;

    int result = 1;

    for (int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }

    cout << "Element at row " << row
         << " and column " << column
         << " is: " << result << endl;
}



// OPTION 2
// Print a particular row of Pascal's triangle

void printRow(int row)
{
    /*
        We start with 1.
        Every next element can be calculated using:
        current = current * (row - column) / column
    */

    long long currentElement = 1;

    cout << "Row " << row << ": ";

    // First element is always 1
    cout << currentElement << " ";

    /*
        column starts from 1 because column 0
        has already been printed.
    */
    for (int column = 1; column < row; column++)
    {
        currentElement = currentElement * (row - column);
        currentElement = currentElement / column;

        cout << currentElement << " ";
    }

    cout << endl;
}


// OPTION 3
// Print the complete Pascal's triangle
void printTriangle(int numberOfRows)
{
    /*
        Example:

        numberOfRows = 5

                    1
                  1   1
                1   2   1
              1   3   3   1
            1   4   6   4   1

        We can simply generate every row using
        the same formula that we used in option 2.
    */

    for (int row = 1; row <= numberOfRows; row++)
    {
        // Print spaces to give triangular shape
        for (int space = 1; space <= numberOfRows - row; space++)
        {
            cout << "  ";
        }

        // First element of every row
        long long currentElement = 1;

        cout << currentElement << "   ";

            // Generate remaining elements of this row.
       
        for (int column = 1; column < row; column++)
        {
            currentElement = currentElement * (row - column);
            currentElement = currentElement / column;

            cout << currentElement << "   ";
        }

        cout << endl;
    }
}



int main()
{
    int choice;

    cout << "Choose an option (1 / 2 / 3): ";
    cin >> choice;

    if (choice == 1)
    {
        int row, column;

        cout << "Enter row and column: ";
        cin >> row >> column;

        if (row < 1 || column < 1 || column > row)
        {
            cout << "Invalid row or column!" << endl;
        }
        else
        {
            findElement(row, column);
        }
    }

    else if (choice == 2)
    {
        int row;

        cout << "Enter row: ";
        cin >> row;

        if (row < 1)
        {
            cout << "Invalid row!" << endl;
        }
        else
        {
            printRow(row);
        }
    }

    else if (choice == 3)
    {
        int numberOfRows;

        cout << "Enter number of rows: ";
        cin >> numberOfRows;

        if (numberOfRows < 1)
        {
            cout << "Invalid number of rows!" << endl;
        }
        else
        {
            printTriangle(numberOfRows);
        }
    }

    else
    {
        cout << "Wrong option chosen!" << endl;
    }

    return 0;
}