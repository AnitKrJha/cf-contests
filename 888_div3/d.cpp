#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> pf;
        vector<long long> orig;
        set<long long> integers;
        long long curr = 0;
        long long target = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long x;
            cin >> x;
            pf.push_back(x);
            orig.push_back(pf[i] - curr);
            if (orig[i] > n)
                target = max(target, orig[i]);
            curr += orig[i];
            integers.insert(i + 1);
        }
        int sumOfIntegers = n * (n + 1) / 2;
        integers.insert(n);
        // for (auto &x : orig)
        //     cout << x << ",";

        // vector<int> missing;
        // sort(orig.begin(), orig.end());
        vector<int> left;
        for (int i = 0; i < orig.size(); i++)
        {
            if (integers.find(orig[i]) != integers.end())
            {
                integers.erase(integers.find(orig[i]));
                sumOfIntegers -= orig[i];
                orig[i] = -1;
            }
            else
            {
                left.push_back(orig[i]);
            }
        }

        if (integers.size() == 2)
        {
            if (left.size() == 1)
            {

                if (sumOfIntegers == left[0])
                {
                    cout << "Yes\n";
                }
                else
                {
                    cout << "No\n";
                }
                continue;
            }
            else
            {
                cout << "No\n";
            }
        }
        if (integers.size() == 1)
        {
            cout << "Yes\n";
            continue;
        }

        cout << "No" << '\n';
    }
}