#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool checkPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Hàm kiểm tra số siêu nguyên tố
bool checkSuperPrime(int n)
{
    if (!checkPrime(n))
    {
        return false;
    }
    if (n == 0)
    {
        return true;
    }
    checkSuperPrime((n - n % 10) / 10);
}

int main()
{
    int n;
    cout << "Nhập số n: ";
    cin >> n;
    vector<int> superPrimeNumber;
    for (int i = 2; i < n; i++)
    {
        if (checkSuperPrime(i))
        {
            superPrimeNumber.push_back(i);
        }
    }

    for (auto i = superPrimeNumber.begin(); i != superPrimeNumber.end(); ++i)
        cout << *i << " ";

    return 0;
}