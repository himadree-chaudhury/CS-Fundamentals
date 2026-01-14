#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;

    int total()
    {
        return math_marks + eng_marks;
    }
};

bool cmp(Student l, Student r)
{
    int tl = l.total();
    int tr = r.total();

    if (tl != tr)
    {
        return tl > tr;
    }
    return l.id < r.id;
}

int main()
{
    int N;
    cin >> N;

    Student a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i].nm >> a[i].cls >> a[i].s >> a[i].id >> a[i].math_marks >> a[i].eng_marks;
    }

    sort(a, a + N, cmp);

    for (int i = 0; i < N; i++)
    {
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " "
             << a[i].id << " " << a[i].math_marks << " " << a[i].eng_marks
             << endl;
    }

    return 0;
}
