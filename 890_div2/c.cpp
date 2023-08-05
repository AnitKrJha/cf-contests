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

ll getBig()
{
    return 1e12 * 1;
}

bool getAns(ll a[], ll n, ll mid, ll i, ll k)
{
    ll ans = 0;
    for (int j = i; j < n; j++)
    {
        if (a[j] >= mid)
            break;
        if (j == n - 1 && a[j] < mid)
            return false;
        else
            ans += mid - a[j];
        mid = mid - 1;
    }
    return ans <= k ? true : false;
}

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll copy[n];
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        copy[i] = arr[i];
    }
    ll mx = arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        ll K = k;
        ll localMax = arr[i];
        ll r = getBig();
        while (localMax <= r)
        {
            ll mid = (localMax + r) / 2;
            if (getAns(arr, n, mid, i, k))
            {
                localMax = mid + 1;
                mx = max(mx, mid);
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    cout << mx << "\n";
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