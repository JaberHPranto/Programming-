// Problem : http://lightoj.com/volume_showproblem.php?problem=1004

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

int dp[1000][1000];
int a[1000][1000];
int n;
int maxPath(int i, int j)
{
    for (i = 1; i <= 2 * n - 1; i++)
    {
        if (i <= n)
        {
            for (j = 1; j <= i; j++)
            {
                dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
        else
        {
            for (j = 1; j <= 2 * n - i; j++)
            {
                dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
        }
    }
    return dp[2 * n - 1][1];
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

    int t, count = 1;
    cin >> t;

    while (t--)
    {
        int i, j;
        cin >> n;
        for (i = 1; i <= 2 * n - 1; i++)
        {
            if (i <= n)
            {
                for (j = 1; j <= i; j++)
                    cin >> a[i][j];
            }
            else
            {
                for (j = 1; j <= 2 * n - i; j++)
                    cin >> a[i][j];
            }
        }
        cout << "Case " << count << ": " << maxPath(1, 1) << endl;
        count++;
    }

    return 0;
}