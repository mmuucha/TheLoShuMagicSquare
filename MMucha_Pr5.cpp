
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;   // The value of the smallest number
const int MAX = 9;   // The value of the largest number

// Function prototypes
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main()
{
    char tryAgain;

    do
    {
        /* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
        int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];

        // Fill the arrays with user input
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        // Display the magic square
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        // Check if it is a magic square and display the result
        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
        {
            cout << "This is a Lo Shu Magic Square." << endl;
        }
        else
        {
            cout << "This is not a Lo Shu Magic Square." << endl;
        }

        // Ask if the user wants to try again
        cout << "\nDo you want to try again?";
        cin >> tryAgain;

    } while (tryAgain == 'Y' || tryAgain == 'y');
    cout << "\nProgrammer: Matthew Mucha\n";
    cout << "CMSC140 Common Project 5\n";
    cout << "Due Date: 08/1/2023\n";
    return 0;
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 0 and column " << i << " :";
        cin >> arrayRow1[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 1 and column " << i << " :";
        cin >> arrayRow2[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 2 and column " << i << " :";
        cin >> arrayRow3[i];
    }
}

void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
    
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    return (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
        checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkColSum(arrayRow1, arrayRow2, arrayRow3, size) &&
        checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size));
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        if (arrayRow1[i] < min || arrayRow1[i] > max || arrayRow2[i] < min || arrayRow2[i] > max || arrayRow3[i] < min || arrayRow3[i] > max)
        {
            return false;
        }
    }
    return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    bool used[9] = { false };
    for (int i = 0; i < size; i++)
    {
        used[arrayRow1[i] - 1] = true;
        used[arrayRow2[i] - 1] = true;
        used[arrayRow3[i] - 1] = true;
    }
    for (int i = 0; i < 9; i++)
    {
        if (!used[i])
        {
            return false;
        }
    }
    return true;
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; i++)
    {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }
    return (sum1 == sum2 && sum2 == sum3);
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int sum[3] = { 0 };
    for (int i = 0; i < size; i++)
    {
        sum[0] += arrayRow1[i];
        sum[1] += arrayRow2[i];
        sum[2] += arrayRow3[i];
    }
    return (sum[0] == sum[1] && sum[1] == sum[2]);
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int mainDiagSum = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int antiDiagSum = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    return (mainDiagSum == antiDiagSum);
}