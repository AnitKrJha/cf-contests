#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // height diff between two persons is maxHeight diff = (m-1)*k
        int ans = 0;
        int n, m, k, H;
        cin >> n >> m >> k >> H;
        int h[n];
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            if (abs(h[i] - H) > 0 && abs(h[i] - H) % k == 0 && abs(h[i] - H) / k < m)
                ans++;
        }
        cout << ans << '\n';
    }
}