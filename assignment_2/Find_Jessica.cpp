#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    bool found = false;

    while (cin >> name)
    {
        if (name == "Jessica")
        {
            found = true;
        }
    }

    cout << (found ? "YES" : "NO");
    return 0;
}
