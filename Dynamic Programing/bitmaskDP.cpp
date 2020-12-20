#include <bits/stdc++.h>
#define INF 999999
#define int long long
using namespace std;
int dp[(int)1 << 17][17], cost[17][17];
int n;

int turnOn(int mask, int pos)
{
    return (mask | (1 << pos));
}

bool isOn(int mask, int pos)
{
    return bool(mask & (1 << pos));
}

int solve(int mask, int pos)
{
    if (mask == (1 << n) - 1)
        return 0;

    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (isOn(mask, i))
            continue;
        ans = max(ans, cost[pos][i] + solve(turnOn(mask, i), pos + 1));
    }
    return dp[mask][pos] = ans;
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
    for (int i = 1; i <= t; i++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        cout << "Case " << i << ": " << solve(0, 0) << endl;
    }
}
