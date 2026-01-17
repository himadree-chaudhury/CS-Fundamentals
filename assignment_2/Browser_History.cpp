#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> l;
    while (true)
    {
        string ch;
        cin >> ch;
        if (ch == "end")
            break;
        l.push_back(ch);
    }

    int q;
    cin >> q;
    string url;
    while (q--)
    {
        string command;
        cin >> command;
        if (command == "visit")
        {
            string temp;
            cin >> temp;
            auto it = find(l.begin(), l.end(), temp);
            if (it != l.end())
            {
                url = temp;
                cout << url << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            auto it = find(l.begin(), l.end(), url);
            if (it != l.begin())
            {
                url = *prev(it);
                cout << url << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            auto it = find(l.begin(), l.end(), url);
            if (it != l.end() && next(it) != l.end())
            {
                url = *next(it);
                cout << url << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}