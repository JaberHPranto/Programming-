#include <bits/stdc++.h>
using namespace std;
int dp[101][101], a[101];
int n;
int matrixChain(int i, int j)
{
    if (i == j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int res = matrixChain(i, k) + matrixChain(k + 1, j) + a[i - 1] * a[k] * a[j];
        ans = min(ans, res);
    }
    dp[i][j] = ans;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << matrixChain(1, n - 1) << endl;
}
