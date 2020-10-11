#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define F(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << " = " << x << endl;

using namespace std;
int f[1005], g[1005], h[1005];
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

void numOfWays()
{
    // base cases
    f[0] = 1, f[1] = 1;
    g[0] = 1, g[1] = 2;
    h[0] = 1, h[1] = 1;

    for (int i = 2; i < 1005; i++)
    {
        f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 2] + h[i - 2];
        g[i] = f[i] + g[i - 1];
        h[i] = f[i] + h[i - 2];
    }
}
int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;
    numOfWays();
    F(i, n)
    {
        cin >> x;
        cout << i + 1 << " " << f[x] << endl;
    }

    return 0;
}
