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
    vector<int> arr(n);
    vector<int> B(n);
    fori(i, n)
    {
        cin >> arr[i];
    }

    // approach is , as swapping is allowed for same parity then
    // the odd numbers will get sorted at their place , and even
    // number will get sorted at their place , and then the resulting array should be sorted.

    // so how can i do it , I can store the even indices and sort them
    // store the odd indices and sort them
    //

    for (int x = 0; x < 2; x++)
    {
        vector<int> indices;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == x)
                indices.push_back(i);
        }
        vector<int> oldIndices = indices;
        sort(indices.begin(), indices.end(), [&](int x, int y) -> bool
             { return arr[x] < arr[y]; });

        for (int i = 0; i < indices.size(); i++)
        {
            B[oldIndices[i]] = arr[indices[i]];
        }
    }
    cout << (is_sorted(B.begin(), B.end()) ? "Yes\n" : "No\n");
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