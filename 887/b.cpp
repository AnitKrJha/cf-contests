#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int min_diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
            {
                min_diff = min(a[i] - a[i - 1], min_diff);
            }
        }
        if (min_diff < 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << (min_diff + 2) / 2 << '\n';
        }
    }
    return 0;
}