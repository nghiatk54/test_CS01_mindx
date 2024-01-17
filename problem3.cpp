#include <bits/stdc++.h>
using namespace std;

// Hàm mã hoá chuỗi
void encodeString(string s, int n)
{
    stack<char> stack;
    int number = 0;
    if (n == 1)
    {
        cout << s[0] << 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (stack.empty())
        {
            stack.push(s[i]);
            number = 1;
        }
        else
        {
            if (s[i] == stack.top())
            {
                number += 1;
                if (i == n - 1)
                {
                    cout << stack.top() << number;
                }
            }
            else
            {
                cout << stack.top() << number;
                stack.pop();
                stack.push(s[i]);
                number = 1;
                if (i == n - 1)
                {
                    cout << stack.top() << number;
                }
            }
        }
    }
}

int main()
{
    string s;
    cout << "Nhập vào 1 chuỗi các ký tự viết thường: ";
    cin >> s;
    int n = s.size();
    cout << n << endl;
    encodeString(s, n);
    return 0;
}