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
#define F(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int dp[101][101];

int maxPath(int n)
{

    if (n == 1)
        return dp[0][0];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
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

    int t;
    cin >> t;

    while (t--)
    {
        int n, i, j;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                int x;
                cin >> x;
                dp[i][j] = x;
            }
        }

        cout << maxPath(n) << endl;
    }

    return 0;
}