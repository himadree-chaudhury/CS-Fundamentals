#include <bits/stdc++.h>
using namespace std;

int main()
{
    char S[100005];
    char letters[100005];
    while (cin.getline(S, 100005))
    {
        int cnt = 0;
        for (int i = 0; S[i]; i++)
        {
            if (S[i] != ' ')
                letters[cnt++] = S[i];
        }
        letters[cnt] = '\0';

        sort(letters, letters + cnt);

        for (int i = 0; i < cnt; i++)
            cout << letters[i];
        cout << endl;
    }
    return 0;
}