#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // n-> the term
        // k-> the position

        // approach -> brute force , we know the (K)th element so we can iteratively fix (K-1)th element and find the previous terms using the formula "S_x-2 = S_x - S_x-1";
        //  after finding S_x-2 every time we will check for two conditions , S_x-2 >=0 and (S_x-2 <=S_x-1)

        // now the possible values of S_k-1 is 1 to n.
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int first = n;
            int second = i;
            bool validSeq = true;
            for (int j = 0; j < k - 2; j++)
            {
                int third = first - second;
                if (third < 0 || second < third)
                {
                    validSeq = false;
                    break;
                }
                first = second;
                second = third;
            }
            if (validSeq)
                ans++;
        }
        cout << ans << '\n';
    }
}