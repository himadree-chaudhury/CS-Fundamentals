#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int id;
    char name[100];
    char Section;
    float Total_Marks;
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        Student top_ranker;
        top_ranker.Total_Marks = -1.0;
        for (int i = 1; i <= 3; i++)
        {
            Student s;
            cin >> s.id >> s.name >> s.Section >> s.Total_Marks;

            if (s.Total_Marks > top_ranker.Total_Marks)
            {
                top_ranker = s;
            }
            else if (s.Total_Marks == top_ranker.Total_Marks)
            {
                if (s.id < top_ranker.id)
                {
                    top_ranker = s;
                }
            }
        }
        cout << top_ranker.id << " " << top_ranker.name << " " << top_ranker.Section << " " << top_ranker.Total_Marks << endl;
    }
    return 0;
}