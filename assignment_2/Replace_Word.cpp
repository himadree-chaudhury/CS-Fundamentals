#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S, X;
        cin >> S >> X;

        string out;
        for (int i = 0; i < (int)S.size();)
        {
            if (S.compare(i, X.size(), X) == 0)
            {
                out += '#';
                i += X.size();
            }
            else
            {
                out += S[i];
                i++;
            }
        }

        cout << out << "\n";
    }

    return 0;
}
