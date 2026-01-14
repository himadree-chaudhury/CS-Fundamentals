#include <bits/stdc++.h>
using namespace std;

void print_reverse(vector<long long int> v, int idx)
{
    if (v.empty() || idx == v.size())
    {
        return;
    }
    print_reverse(v, idx + 1);
    cout << v[idx] << " ";
}

int main()
{
    int N;
    cin >> N;
    vector<long long int> A(N);
    for (long long int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<long long int> prefixSum(N);
    prefixSum[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    print_reverse(prefixSum, 0);

    reverse(prefixSum.begin(), prefixSum.end());
    for( auto x : prefixSum)
    {
        cout << x << " ";
    }
    return 0;
}