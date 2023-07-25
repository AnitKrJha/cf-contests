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
        int k;
        cin >> k;
        int k2 = k;
        int c[n];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        if (c[0] == c[n - 1])
        {
            int x = count(c, c + n, c[0]);
            if (x >= k)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int r = n - 1;
            while (k > 0 && r >= 0)
            {
                if (c[r] == c[n - 1])
                    k--;
                r--;
            }
            int l = 0;
            while (k2 > 0 && l < n)
            {
                if (c[l] == c[0])
                    k2--;
                l++;
            }
            int lastIndex = k == 0 ? r + 1 : -1;
            int firstIndex = k2 == 0 ? l - 1 : -1;
            if (lastIndex == -1 || firstIndex == -1)
            {
                cout << "No\n";
                continue;
            }
            if (lastIndex > firstIndex)
            {
                cout << "Yes\n";
                continue;
            }
            cout << "No\n";
        }
    }
}