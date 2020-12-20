#include <bits/stdc++.h>
#define INF 999999
#define int long long
using namespace std;
int dp[101][101], a[101];
int n;
int sum(int s, int e)
{
    int ans = 0;
    for (int i = s; i <= e; i++)
    {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}
int matrixChain(int i, int j)
{
    if (i >= j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int res = matrixChain(i, k) + matrixChain(k + 1, j) + sum(i, k) * sum(k + 1, j);
        ans = min(ans, res);
    }
    dp[i][j] = ans;
    return ans;
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
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << matrixChain(0, n - 1) << endl;
    }
}
