#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    vector<int> v1, v2;
    while (!s.empty())
    {
        v1.push_back(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        v2.push_back(q.front());
        q.pop();
    }

    v1 == v2 ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}