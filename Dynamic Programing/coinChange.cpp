#include <bits/stdc++.h>
using namespace std;
int dp[101][101], a[101];
int n;
int coinCount(int i, int need)
{
    if (need == 0)
        return 0;
    if (i == n or need < 0)
        return 10000;
    if (dp[i][need] != -1)
        return dp[i][need];
    return dp[i][need] = min(1 + coinCount(i + 1, need - a[i]), coinCount(i + 1, need));
}
int numOfWays(int i, int need)
{
    if (need == 0)
        return 1;
    if (i < 0 or need < 0)
        return 0;
    if (dp[i][need] != -1)
        return dp[i][need];
    return dp[i][need] = numOfWays(i, need - a[i]) + numOfWays(i - 1, need);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w;
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << coinCount(0, w) << endl;
    cout << numOfWays(n - 1, w) << endl;
}