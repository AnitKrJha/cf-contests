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
        vector<pair<int, int>> a;
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back({x, i});
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i].second != i)
            {
                if (b[i] % 2 != a[i].first % 2)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}