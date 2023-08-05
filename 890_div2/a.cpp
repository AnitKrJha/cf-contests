#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define ford(i, a, b) for (int i = (a); i >= (b); --i)
template <typename T>
void printVector(const vector<T> &vec)
{
    for (const auto &element : vec)
    {
        cout << element << " ";
    }
    cout << "\n";
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> getPrimeFactors(int n)
{
    vector<int> factors;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        a[i] = arr[i];
    }
    sort(arr, arr + n);
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != a[i])
        {
            mx = max(mx, a[i]);
        }
    }
    cout << max(0, mx) << '\n';
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}