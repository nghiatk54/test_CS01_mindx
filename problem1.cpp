#include <iostream>
using namespace std;

int main()
{
    // Input number test case
    int sumTest = 0;
    while (sumTest <= 0 || sumTest > 100)
    {
        cout << "Number test case (1-100): ";
        cin >> sumTest;
    }

    // Store number to array
    int arrTest[100];
    for (int i = 0; i < sumTest; i++)
    {
        cin >> arrTest[i];
    }

    // Print sum of divisors of integers
    int sum;

    for (int i = 0; i < sumTest; i++)
    {
        sum = 0;
        for (int j = 1; j <= arrTest[i]; j++)
        {
            if (arrTest[i] % j == 0)
            {
                sum += j;
            }
        }
        cout << sum << endl;
    }
}